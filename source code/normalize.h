void maxmin(population *pop_ptr,int pop);

void maxmin(population *pop_ptr,int pop)
{
	int i,k;

	for(k=0;k<nfunc;k++)
	{
		maxf[k]=-INF;
		minf[k]=INF;
		for(i=0;i<pop;i++)
		{
			if(pop_ptr->ind[i].fitness[k]>maxf[k])
					maxf[k]=pop_ptr->ind[i].fitness[k];
			if(pop_ptr->ind[i].fitness[k]<minf[k])
					minf[k]=pop_ptr->ind[i].fitness[k];
		}
		maxminf[k]=maxf[k]-minf[k];
/*
		if(maxminf[k]<EPS)
		{
			maxminf[k]=EPS;
			printf("error, mami[%d]=%f\n",k,maxminf[k]);
			getchar();
		}
*/
	}

}//end maxmin


void normalize(population *pop_ptr,int pop);

void normalize(population *pop_ptr,int pop)
{
	int i,k;

	for(i=0;i<pop;i++)
	{
		for(k=0;k<nfunc;k++)
		{
			pop_ptr->ind[i].fitness[k]=(pop_ptr->ind[i].fitness[k]-minf[k])/maxminf[k];
		}
	}


}//end normalize
