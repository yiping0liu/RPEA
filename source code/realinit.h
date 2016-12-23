/*This code is from Deb's NSGA-II*/
/*Initialize the population*/
void realinit(population *pop_ptr);

void realinit(population *pop_ptr)
{
  int i,j;
  float d,d1;
  
  for (i = 0 ; i < popsize ; i++)
    { 
      for (j = 0; j < nvar; j++)
	{
	  d = randomperc();
	  d1 = 2*d - 1;
	  /*if limits are not specified then generates any number between 
	    zero and infinity*/
	  if(var_bound != 1)
	    {  
	      pop_ptr->ind[i].xreal[j] = 1/d1 ;
	    }
	  
	  /*if limits are specified it generates the value in 
	    range of minimum and maximum value of the variable*/
	  else
	    {
	 
			pop_ptr->ind[i].xreal[j] = d*(lim_r[j][1] - lim_r[j][0])+lim_r[j][0];
	    }
	}
      /* pop_ptr->ind_ptr = &(pop_ptr->ind[i+1]); */
    }
  /*pop_ptr->ind_ptr = &(pop_ptr->ind[0]); */
 return;
}






























































