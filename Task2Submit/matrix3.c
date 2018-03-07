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
	unsigned int M = 1000;
	unsigned int N = 1000; 
	
  /* declare variables; examples, adjust for task */
	double *first, *second, *multiply, *temp;
	//double  a[100];
	int i, j, m, n, p, q, c, d, k,kk,jj; 
	double sum = 0;
	double temp_variable;
	int bsize = 64;


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
	first = malloc (N * N * sizeof(double)); //this is matrix a
	second = malloc (N * N * sizeof(double)); //this is matrix b
	multiply = malloc (N * N * sizeof(double)); //this is matrix c
	

	 /* initialise arrray elements */
	 //fill in the first matrix
	for (c = 0; c < N; c++) {
		for (d = 0; d < N; d++) {
			first[c*N + d] = 5;
			second[c*N + d] = 10;
		}
	}

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			multiply[i*N +j] = 0.0;
		}
	}

	t1 = getTime();
  /* code to be measured goes here */
  /***************************************/

	for (kk = 0; kk < N; kk += bsize) {
		for (jj = 0; jj < N; jj += bsize) {
			for (i = 0; i < N; i++) {
				for (j = jj; j < jj + bsize; j++) {
					sum = multiply[i*N +j];
					for (k = kk; k < kk + bsize; k++) {
						sum += first[i*N +k]*second[k*N +j];
					}
					multiply[i*N +j] = sum;
				}
			}
		}
	}


  /***************************************/
t2 = getTime(); 

  /* output; examples, adjust for task */
printf("time: %6.2f secs\n",(t2 - t1));

 //print out the results
  /*
    printf("Product of entered matrices:-\n");
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        printf("%f\t", multiply[c*N + d]);
      printf("\n");
    }
  }
  */

  /* free memory; examples, adjust for task */
free(first);
free(second);
free(multiply);

return 0;  
}
