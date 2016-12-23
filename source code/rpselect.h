void rpselect(population *pop1_ptr,population *pop2_ptr,population *pop3_ptr,int pop);
//                       rp                   mate                 old

void rpselect(population *pop1_ptr,population *pop2_ptr,population *pop3_ptr,int pop)
{
	int i,j,k,l,n;
	float *D;
	float tempd;
	float maxched;
	float ched;
	float mind;
	int mini,minj;
	int flagrp[maxpop];
	int flagind[maxpop];
	D=(float*)malloc(maxpop*maxpop*2*sizeof(float));

	/*calculate Tchebycheff distance*/
	for(i=0;i<pop;i++)
	{
		for(j=0;j<popsize*2;j++)
		{
			maxched=-INF;
			for(k=0;k<nfunc;k++)
			{
				//ched=pop2_ptr->ind[j].fitness[k]-pop1_ptr->ind[i].fitness[k];
				ched=(pop2_ptr->ind[j].fitness[k]-pop1_ptr->ind[i].fitness[k])/maxminf[k];
				if(ched>maxched)
				{
					maxched=ched;
				}
			}
			D[i*2*popsize+j]=maxched;
		}
	}

	/*environment selection*/
	for(i=0;i<pop;i++) flagrp[i]=1;
	for(j=0;j<2*popsize;j++) flagind[j]=1;
	n=0;
	l=0;
	while(n<popsize)
	{
		/*renew reference points*/
		if(l==pop)
		{
			for(i=0;i<pop;i++)
				flagrp[i]=1;
			l=0;
		}

		mind=INF;
		mini=pop;
		minj=popsize*2;

		/*search for the minimum distance (i.e., mind)*/ 
		for(i=0;i<pop;i++)
		{
			for(j=0;j<popsize*2;j++)
			{
				if(D[i*2*popsize+j]<mind && flagrp[i]==1 && flagind[j]==1)
				{
					mind=D[i*2*popsize+j];
					minj=j;
					mini=i;
				}
			}
		}

		/*select the solution with mind*/
		copyind(pop3_ptr,pop2_ptr,n,minj);
		pop3_ptr->ind[n].cub_len=mind;//using for mating selection
		n++;
		l++;

		//mask the selected solution and reference point 
		flagrp[mini]=0;
		flagind[minj]=0;


	}//end while n

	free(D);


}//end rpselect