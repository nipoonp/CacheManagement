/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime(){
  struct timeval t;
  double sec, msec;
  
  while (gettimeofday(&t, NULL) != 0);
  sec = t.tv_sec;
  msec = t.tv_usec;
  
  sec = sec + msec/1000000.0;
  
  return sec;
}
 
/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "Usage: cachetest1/2 [--repetitions M] [--array_size N]\n");
	exit(1);
}

int main (int argc, char *argv[])
{
  double t1, t2; 
  
  /* variables for task 1 */
  unsigned int M = 2000;
  unsigned int N = 8388608; 
  unsigned int i;
	
  /* declare variables; examples, adjust for task */
	int *a;
	int *b;
	//double  a[100];
 
  
  /* parameter parsing task 1 */
  for(i=1; i<(unsigned)argc; i++) {
	  if (strcmp(argv[i], "--repetitions") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &M);
		  else
			  usage();
	  } else if (strcmp(argv[i], "--array_size") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &N);
		  else
			  usage();
	  } else usage();
  }
  
  

    
  /* allocate memory for arrays; examples, adjust for task */
	 a = malloc (N * sizeof(int));
	 b = malloc (N * sizeof(int));

	 /* initialise arrray elements */
 	int sum = 0;
 	int j = 0;
 

 	int fill_index = 0;
 	for (fill_index = 0; fill_index < N; fill_index++){
		a[fill_index] = fill_index;
		b[fill_index] = 5;
 	}
 	
 	
	 
  t1 = getTime();
  /* code to be measured goes here */
  /***************************************/
	for(j = 0; j < M; j++){
		sum = 0;
		for (i = 0; i < N; i++){
			
	    	sum = sum + b[a[i]];
	    	
		}
		//printf("sum = %d\n", sum);
	}
	
	
  /***************************************/
	t2 = getTime(); 
  
  /* output; examples, adjust for task */
  printf("time: %.12f secs\n",(((t2 - t1)/N)/M));
  printf("total time : %f sec\n",(t2-t1));
  printf("sum: %d\n", sum);

  /* free memory; examples, adjust for task */
  free(a);
  free(b);

  return 0;  
}
