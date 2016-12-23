int rpgen(population *pop1_ptr,population *pop2_ptr,population *pop3_ptr);

int rpgen(population *pop1_ptr,population *pop2_ptr,population *pop3_ptr)
{
	int i,j,k,l,m,n;
	int pop;

	/*select non-dominated solutions*/
	ranking(pop3_ptr,2*popsize);
	pop=0;
	for(i=0;i<2*popsize;i++)
	{
		if(pop3_ptr->ind[i].rank==1)
		{
			copyind(pop1_ptr,pop3_ptr,pop,i);
			pop++;
		}
	}
	maxmin(pop1_ptr,pop);

	/*sample reference points in each dimension*/
	n=0;
	for(j=0;j<nfunc;j++)
	{	
		crowdd1(pop1_ptr,pop,j);

		for(i=0;i<pop;i++)
		{
			if(pop1_ptr->ind[i].cub_len>asort[nrp1d])
			{
				for(k=0;k<nfunc;k++)
				{
					if(k==j)
					{
						//pop2_ptr->ind[n].fitness[k]=pop1_ptr->ind[i].fitness[k]-e_rpea;
						pop2_ptr->ind[n].fitness[k]=pop1_ptr->ind[i].fitness[k]-e_rpea*maxminf[k];
					}
					else
						pop2_ptr->ind[n].fitness[k]=pop1_ptr->ind[i].fitness[k];
				}
				n++;
			}
		}
	}

	/*select non-dominated reference points*/
	ranking(pop2_ptr,n);
	l=pop2_ptr->rankno[0];
	m=0;
	for(i=0;i<n;i++)
	{
		if(pop2_ptr->ind[i].rank==1)
		{
			if(i!=m)
			{
				copyind(pop2_ptr,pop2_ptr,m,i);
			}
			m++;
		}
	}

	/*eliminate crowded reference points*/
	if(l>popsize)
	{
		crowdd(pop2_ptr,l);
		m=0;
		for(i=0;i<l;i++)
		{
			if(pop2_ptr->ind[i].cub_len>asort[popsize])
			{
				copyind(pop2_ptr,pop2_ptr,m,i);
				m++;
			}
		}
		return popsize;
	}
	else
		return l;



}//end rpgen