/*This code is from Deb's NSGA-II*/
/*tournament selection*/

void nselect(population *old_pop_ptr,population *pop2_ptr);

void nselect(population *old_pop_ptr,population *pop2_ptr)
{
  int *fit_ptr1,*fit_ptr2;

  float rnd2,*f1_ptr,*f2_ptr;
  
  float *select_ptr_r, *s1_ptr_r, *s2_ptr_r;
  
  void *j,*j1;
  
  int i,rnd,rnd1,k,n;
  
  old_pop_ptr->ind_ptr = &(old_pop_ptr->ind[0]);
  
  pop2_ptr->ind_ptr= &(pop2_ptr->ind[0]); 
  
  j =  &(old_pop_ptr->ind[popsize-1]);
  
  old_pop_ptr->ind_ptr = &(old_pop_ptr->ind[0]); 

  
  for(n = 0,k = 0;n < popsize;n++,k++)
    {
      pop2_ptr->ind_ptr = &(pop2_ptr->ind[k]);
      select_ptr_r = &(pop2_ptr->ind_ptr->xreal[0]);

      rnd2 = randomperc(); 

      rnd2 = popsize* rnd2; 

      rnd = floor(rnd2);

      if(rnd == 0)
	rnd = popsize - k;

      if(rnd == popsize)
	rnd = (popsize-2)/2;
      
      /*Select first parent randomly*/	
      j = &(old_pop_ptr->ind[rnd-1]);
      
      rnd2 = randomperc(); 
      
      rnd2 = popsize * rnd2; 
      
      rnd1 = floor(rnd2);
      
      if (rnd1 == 0)
	rnd1 = popsize - n;

      if(rnd1 == popsize)
	rnd1 = (popsize - 4)/2;
      
      
      /*Select second parent randomly*/
      j1 = &(old_pop_ptr->ind[rnd1-1]);
      
      old_pop_ptr->ind_ptr = j;
      
      s1_ptr_r = &(old_pop_ptr->ind_ptr->xreal[0]);
      fit_ptr1 = &(old_pop_ptr->ind_ptr->rank);
      f1_ptr = &(old_pop_ptr->ind_ptr->cub_len);
      
      old_pop_ptr->ind_ptr = j1;

      s2_ptr_r = &(old_pop_ptr->ind_ptr->xreal[0]);
      fit_ptr2 = &(old_pop_ptr->ind_ptr->rank);
      f2_ptr = &(old_pop_ptr->ind_ptr->cub_len);
/*--------------------------------------------------------------------------*/
      
/*------------------SELECTION PROCEDURE------------------------------------*/
      
      /*Comparing the fitnesses*/
      
      if(*fit_ptr1 > *fit_ptr2)
	{
	  for(i = 0;i < nvar;i++)
	    *select_ptr_r++=*s2_ptr_r++;
	}
      else
	{
	  if(*fit_ptr1 < *fit_ptr2)
	    {
	      for(i = 0;i < nvar;i++)
		*select_ptr_r++=*s1_ptr_r++;
	    }
	  else
	    {
	      if(*f1_ptr > *f2_ptr)
		{
		  for(i = 0;i < nvar;i++)
		    *select_ptr_r++=*s2_ptr_r++;
		}
	      else
		{
		  for(i = 0;i < nvar;i++)
		    *select_ptr_r++=*s1_ptr_r++;
		}
	    }
	}
    }
  return;
}







