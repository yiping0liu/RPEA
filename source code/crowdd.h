void crowdd(population *pop_ptr,int pop);

void crowdd(population *pop_ptr,int pop)
{
	int i,j,k;
	int indno[maxpop];
	float fit[maxpop];
	int tempind;
	float tempfit;

	for(i=0;i<pop;i++)
		pop_ptr->ind[i].cub_len=0;

	for(k=0;k<nfunc;k++)
	{
		for(i=0;i<pop;i++)
		{
			fit[i]=pop_ptr->ind[i].fitness[k];
			indno[i]=i;
		}
		
		for(i=0;i<pop-1;i++)
		{
			for(j=0;j<pop-1-i;j++)
			{
				if(fit[j]>fit[j+1])
				{
					tempfit=fit[j];
					fit[j]=fit[j+1];
					fit[j+1]=tempfit;

					tempind=indno[j];
					indno[j]=indno[j+1];
					indno[j+1]=tempind;
				}
			}
		}

		pop_ptr->ind[indno[0]].cub_len+=INF;
		pop_ptr->ind[indno[pop-1]].cub_len+=INF;

		for(i=1;i<pop-1;i++)
		{
			pop_ptr->ind[indno[i]].cub_len+=fit[i+1]-fit[i-1];
		}


	}//end k

	for(i=0;i<pop;i++)
		asort[i]=pop_ptr->ind[i].cub_len;
	psort(pop);

}//end crowdd

void crowdd1(population *pop_ptr,int pop,int k);

void crowdd1(population *pop_ptr,int pop,int k)
{
	int i,j;
	int indno[maxpop];
	float fit[maxpop];
	int tempind;
	float tempfit;

	for(i=0;i<pop;i++)
		pop_ptr->ind[i].cub_len=0;

	//for(k=0;k<nfunc;k++)
	{
		for(i=0;i<pop;i++)
		{
			fit[i]=pop_ptr->ind[i].fitness[k];
			indno[i]=i;
		}
		
		for(i=0;i<pop-1;i++)
		{
			for(j=0;j<pop-1-i;j++)
			{
				if(fit[j]>fit[j+1])
				{
					tempfit=fit[j];
					fit[j]=fit[j+1];
					fit[j+1]=tempfit;

					tempind=indno[j];
					indno[j]=indno[j+1];
					indno[j+1]=tempind;
				}
			}
		}

		pop_ptr->ind[indno[0]].cub_len+=INF;
		pop_ptr->ind[indno[pop-1]].cub_len+=INF;

		for(i=1;i<pop-1;i++)
		{
			pop_ptr->ind[indno[i]].cub_len+=fit[i+1]-fit[i-1];
		}


	}//end k

	for(i=0;i<pop;i++)
		asort[i]=pop_ptr->ind[i].cub_len;
	psort(pop);

}//end crowdd
