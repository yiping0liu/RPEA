void copyind(population *pop1_ptr,population *pop2_ptr,int num1,int num2);

void copyind(population *pop1_ptr,population *pop2_ptr,int num1,int num2)
{
	int k;

	for(k=0;k<nvar;k++)
		pop1_ptr->ind[num1].xreal[k] = pop2_ptr->ind[num2].xreal[k];
	for(k=0;k<nfunc;k++)
		pop1_ptr->ind[num1].fitness[k] = pop2_ptr->ind[num2].fitness[k];
	for(k=0;k<ncons;k++)
		pop1_ptr->ind[num1].constr[k] = pop2_ptr->ind[num2].constr[k];
	pop1_ptr->ind[num1].cub_len =pop2_ptr->ind[num2].cub_len;
	pop1_ptr->ind[num1].rank = pop2_ptr->ind[num2].rank;
	pop1_ptr->ind[num1].flag = pop2_ptr->ind[num2].flag;
}//end copyind