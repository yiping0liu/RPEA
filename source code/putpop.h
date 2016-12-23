void putobj(population *pop_ptr,FILE *fpt);//output objective
void putvar(population *pop_ptr,FILE *fpt);//output variable

void putobj(population *pop_ptr,FILE *fpt)
{
	int i,k;

	for(i=0;i<popsize;i++)
	{
		for(k=0;k<nfunc;k++)
		{
			fprintf(fpt,"%e\t",pop_ptr->ind[i].fitness[k]);
		}
		fprintf(fpt,"\n");
	}
	fprintf(fpt,"\n");
}

void putvar(population *pop_ptr,FILE *fpt)
{
	int i,k;

	for(i=0;i<popsize;i++)
	{
		for(k=0;k<nvar;k++)
		{
			fprintf(fpt,"%e\t",pop_ptr->ind[i].xreal[k]);
		}
		fprintf(fpt,"\n");
	}
	fprintf(fpt,"\n");

}