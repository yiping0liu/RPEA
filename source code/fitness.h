void func(population *pop_ptr,int pop,int test_flag);

void func(population *pop_ptr,int pop,int test_flag)
{ 
  float x[maxvar],
	  *x_ptr,
	  f[maxfun];
  int i,j,k,n;

  float g,h,dtlz_t;//for dtlz
  float th[maxfun];
  int ii=1;//for dtlz5&6

  for(n=0;n<pop;n++)
  {
	  for(i=0;i<nvar;i++)
	  {
		  x[i]=pop_ptr->ind[n].xreal[i];
	  }
	  x_ptr=x;



/*--------------calculate fitness-------------------*/

/*dltz1*/
	  if(test_flag==1)
	  {
		   g=0;
	  for(j=nfunc-1;j<nvar;j++)
	  {
		  g=g+square(x[j]-0.5)-cos(20*PI*(x[j]-0.5));
	  }
	  g=100*(nvar-nfunc+1+g);

	  f[0]=0.5*(1+g);
	  for(j=0;j<nfunc-1;j++)
	  {
		  f[0]=f[0]*x[j];
	  }

	  for(k=1;k<nfunc;k++)
	  {
		  f[k]=0.5*(1+g);
		  for(j=0;j<nfunc-k-1;j++)
		  {
			  f[k]=f[k]*x[j];
		  }
		  f[k]=f[k]*(1-x[nfunc-k-1]);
	  }
	  }
/*dltz2*/
	  else if(test_flag==2)
	  {
		  g=0;
	  for(j=nfunc-1;j<nvar;j++)
	  {
		  g=g+square(x[j]-0.5);
	  }

	  f[0]=1+g;
	  for(j=0;j<nfunc-1;j++)
	  {
		  f[0]=f[0]*cos(PI*x[j]/2);
	  }

	  for(k=1;k<nfunc;k++)
	  {
		  f[k]=1+g;
		  for(j=0;j<nfunc-k-1;j++)
		  {
			  f[k]=f[k]*cos(PI*x[j]/2);
		  }
		  f[k]=f[k]*sin(PI*x[nfunc-k-1]/2);
	  }
	  }

/*dltz3*/
	  else if(test_flag==3)
	  {
		  g=0;
	  for(j=nfunc-1;j<nvar;j++)
	  {
		  g=g+square(x[j]-0.5)-cos(20*PI*(x[j]-0.5));
	  }
	  g=100*(nvar-nfunc+1+g);

	  f[0]=1+g;
	  for(j=0;j<nfunc-1;j++)
	  {
		  f[0]=f[0]*cos(PI*x[j]/2);
	  }

	  for(k=1;k<nfunc;k++)
	  {
		  f[k]=1+g;
		  for(j=0;j<nfunc-k-1;j++)
		  {
			  f[k]=f[k]*cos(PI*x[j]/2);
		  }
		  f[k]=f[k]*sin(PI*x[nfunc-k-1]/2);
	  }
	  }

/*dltz4*/
	  else if(test_flag==4)
	  {
		   g=0;
	  for(j=nfunc-1;j<nvar;j++)
	  {
		  g=g+square(x[j]-0.5);
	  }

	  f[0]=1+g;
	  for(j=0;j<nfunc-1;j++)
	  {
		  f[0]=f[0]*cos(PI*pow(x[j],(float)100)/2);
	  }

	  for(k=1;k<nfunc;k++)
	  {
		  f[k]=1+g;
		  for(j=0;j<nfunc-k-1;j++)
		  {
			  f[k]=f[k]*cos(PI*pow(x[j],(float)100)/2);
		  }
		  f[k]=f[k]*sin(PI*pow(x[nfunc-k-1],(float)100)/2);
	  }
	  }

/*dltz5*/
	  else if(test_flag==5)
	  {
		  g=0;
	  for(j=nfunc-1;j<nvar;j++)
	  {
		  g=g+square(x[j]-0.5);
	  }
	  dtlz_t=PI /(4 * (1 + g));

	  for(j=0;j<ii;j++)
	  {
		  th[j]=x[j]*PI/2;
	  }
	  for(j=ii;j<nfunc-1;j++)
	  {
		  th[j]=dtlz_t*(1+2*g*x[j]);
	  }

	  f[0]=1+g;
	  for(j=0;j<nfunc-1;j++)
	  {
		  f[0]=f[0]*cos(th[j]);
	  }

	  for(j=1;j<nfunc;j++)
	  {
		  f[j]=1+g;
		  for(k=0;k<nfunc-j-1;k++)
		  {
			  f[j]=f[j]*cos(th[k]);
		  }
		  f[j]=f[j]*sin(th[nfunc-j-1]);
	  }
	  }

/*dltz6*/
	  else if(test_flag==6)
	  {
		  g=0;
	  for(j=nfunc-1;j<nvar;j++)
	  {
		  g=g+pow(x[j],0.1);
	  }
	  dtlz_t=PI /(4 * (1 + g));

	  for(j=0;j<ii;j++)
	  {
		  th[j]=x[j]*PI/2;
	  }
	  for(j=ii;j<nfunc-1;j++)
	  {
		  th[j]=dtlz_t*(1+2*g*x[j]);
	  }

	  f[0]=1+g;
	  for(j=0;j<nfunc-1;j++)
	  {
		  f[0]=f[0]*cos(th[j]);
	  }

	  for(j=1;j<nfunc;j++)
	  {
		  f[j]=1+g;
		  for(k=0;k<nfunc-j-1;k++)
		  {
			  f[j]=f[j]*cos(th[k]);
		  }
		  f[j]=f[j]*sin(th[nfunc-j-1]);
	  }
	  }

/*dltz7*/
	  else if(test_flag==7)
	  {
		  g=0;
	  for(j=nfunc-1;j<nvar;j++)
	  {
		  g=g+x[j];
	  }
	  g=g*9/(nvar-nfunc+1);
	  g=g+1;

	  for(j=0;j<nfunc-1;j++)
	  {
		  f[j]=x[j];
	  }

	  h=0;
	  for(j=0;j<nfunc-1;j++)
	  {
		  h=h+f[j]*(1+sin(3*PI*f[j]))/(1+g);
	  }
	  h=nfunc-h;

	  f[nfunc-1]=(1+g)*h;
	  }

/*error*/	
	  else{printf("error problem\n");getchar();}

	  /*fitness assignment*/
	  for(k=0;k<nfunc;k++)
	  {
			pop_ptr->ind[n].fitness[k]=f[k];
	  }


  }//end n pop


}//end fitness