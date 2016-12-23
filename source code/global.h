#define INF 1.0e14
#define EPS 1.0e-14
#define E  2.71828182845905
#define PI 3.14159265358979323846

#define square(x) ((x)*(x))

#define maxpop  2000  
#define maxvar    100  
#define maxfun    50 
#define maxcons   50 
#define maxgener 5000 


/*parameters in RPEA*/
int nrp1d; //number of reference points to generate for each dimentioon
float a_rpea; //a parameter to control nrp1d, in the range of [1/M,1]
float e_rpea; //step size when using fomular (3) to generate reference points
int rpsize; //total number of reference points


/*common parameters*/
char dir[100];
char filename[100];
float startTime;
float endTime;
float runtime[50];

int test_flag;//Test Problem, DTLZ 1~7
int nfunc;//number of objective    
int nvar;//number of variable        
int ncons;//number of constraint

float seed; 
float seed0;//original seed
int maxrun;//max run times
int gener;//generation
int popsize;//population size
                  
float pcross;//crossover probability       
float pmut_r;//mutation probability        
float lim_r[maxvar][2];
float di;       
float dim;  
int var_bound;

float asort[maxpop];

float maxf[maxfun],minf[maxfun],maxminf[maxfun];//max/min values of objecitves

typedef struct      
{
	int	flag;
	int rank;//Pareto rank
	float xreal[maxvar];//variable
	float fitness[maxfun];//objective
    float constr[maxcons];//constraint   
    float cub_len;//crowding distance         

}individual;        

typedef struct
{
  int maxrank;              
  int rankno[maxpop];     
  individual ind[maxpop], 
    *ind_ptr; 
}population ;            

population oldpop,
  newpop,
  matepop,
  rppop,
  *old_pop_ptr,
  *new_pop_ptr,
  *mate_pop_ptr,
  *rp_pop_ptr;//set of reference points

