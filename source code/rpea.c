/********************************************************************************************/
/* Y. Liu et.al, Many-objective evolutionary optimization based on reference points (RPEA). */
/* Published on Applied Soft Computing, vol. 50, pp. 344-355, 2017.                         */
/* This source code of RPEA was implemented by Yiping Liu.                                  */
/* Please contact yiping0liu@gmail.com, if you have any problem or question.                */
/* Copyright 2014-2017 by Yiping Liu                                                        */
/********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <direct.h>
#include <conio.h>
#include <time.h>
#include "global.h"
#include "random.h"  
#include "normalize.h"
#include "realinit.h" //initialize population      
#include "fitness.h" //fitness assignment
#include "realcross2.h" //crossover  
#include "realmut1.h" //mutation
#include "select.h" //mating select
#include "ranking.h" //Pareto rank 
#include "copyind.h" //copy individual 
#include "psort.h" //sort function
#include "crowdd.h" //crowding distance 
#include "rpgen.h"   //generate reference points
#include "rpselect.h"   //enviorenment selection based on reference points
#include "putpop.h" //output

main()  /* */
{
	int g,i,norun;
	FILE *fp_obj,*fp_var;

	old_pop_ptr = &(oldpop);
	mate_pop_ptr = &(matepop);
	new_pop_ptr = &(newpop);
	rp_pop_ptr = &(rppop);

	/*-----common parameter settings-----*/
	test_flag=2;
	nfunc=6;
	nvar=nfunc+9;
	popsize=120;
	gener=300;
	maxrun=5;
	seed0=0.0233;

	ncons=0; 
	pcross=1.00; 
	pmut_r=1.00/(1.00*nvar); 
	di=20; 
	dim=20;
	for(i = 0; i < nvar; i++) 
	{
		lim_r[i][0]=0;
		lim_r[i][1]=1;
	}
	var_bound=1;

	/*-----rpea parameter settings-----*/
	a_rpea=0.4;
	e_rpea=0.05;
	nrp1d=ceil(a_rpea*popsize);

	/*-----make directories-----*/
	sprintf(dir,"dtlz%d-%d-%.3f-%.3f",test_flag,nfunc,a_rpea,e_rpea);
	mkdir(dir);

	strcpy(filename,dir);
	strcat(filename,"\\objective.txt");
	fp_obj=fopen(filename,"w");

	strcpy(filename,dir);
	strcat(filename,"\\variable.txt");
	fp_var=fopen(filename,"w");

	/*-----run 'maxrun' times-----*/
	for(norun=0;norun<maxrun;norun++)
	{
	printf("DTLZ%d\tObjective=%2d\tRun=%2d\n",test_flag,nfunc,norun);
	seed=seed0+norun/(maxrun*1.00); 
	warmup_random(seed);
	old_pop_ptr = &(oldpop);
	mate_pop_ptr = &(matepop);
	new_pop_ptr = &(newpop);
	rp_pop_ptr = &(rppop);

	printf("runing ");
	startTime = clock();
	realinit(old_pop_ptr);
	func(old_pop_ptr,popsize,test_flag);

	/*-----evolving-----*/
	for (g = 0;g < gener;g++)
	{
		if(g%(gener/10)==gener/10-1) printf("%1.f%% ",100.0*(g+1.0)/gener);

		nselect(old_pop_ptr,mate_pop_ptr);//mating select
		realcross(new_pop_ptr ,mate_pop_ptr);//crossing
		real_mutate(new_pop_ptr );//mutation
		func(new_pop_ptr,popsize,test_flag);//calculate objective values

		for(i=0;i<popsize;i++)//merge old&new pop
			copyind(mate_pop_ptr,old_pop_ptr,i,i);
		for(i=0;i<popsize;i++)
			copyind(mate_pop_ptr,new_pop_ptr,popsize+i,i);
		
		rpsize=rpgen(new_pop_ptr,rp_pop_ptr,mate_pop_ptr);//generate reference poins
		rpselect(rp_pop_ptr,mate_pop_ptr,old_pop_ptr,rpsize);//enviroment selection based on reference points
		func(old_pop_ptr,popsize,test_flag);

	}//end g

	endTime=clock();
	runtime[norun]=(endTime-startTime)/CLOCKS_PER_SEC;
	printf("time used %.3fs\n",runtime[norun]);

	putobj(old_pop_ptr,fp_obj);
	putvar(old_pop_ptr,fp_var);

	}//end norun

	fclose(fp_obj);
	fclose(fp_var);

	printf("Done!\nPlease press the AnyKey to exit...");
	getch();

}//end main
