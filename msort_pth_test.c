//C header files
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "timer.h"
#include "msort_pth.h"

//Dynamically allocate an array of size N in heap
void fillArray ( int** values, unsigned int N )
{
    srand(time(0));
	unsigned int i;
    for (i=0; i<N; i++)
        (*values)[i] = rand() - (RAND_MAX/2);
}

//Check to see if the sorted array is really sorted!
void checkArray ( const int* values, unsigned int N, const int* sorted )
{
    unsigned int i;
	for (i=0; i <= N-2; i++)
        if (sorted[i]>sorted[i+1])
        {
		printf("ERROR i=%d %d %d", i, sorted[i], sorted[i+1]);
		return;
        }
	printf("OK\n");
}

int main ( int argc, char* argv[] )
{
    if ( argc != 3 ){
        printf("Please enter: \n ./a.out  M  K\n");
        exit( 1 );
    }

	//input array
	unsigned int K;
	unsigned int N;

	//Fill in the input array with random data
	K = atoi(argv[2]);
	N = pow( 2, atoi(argv[1]) );
	int* values = (int*) malloc ( sizeof(int) * N );
	fillArray ( &values, N );

	//Sorted array
	int* sorted = (int*) malloc ( sizeof(int) * N );

	//Sort the input array and report its runtime
	double t1,t2;
	GET_TIME(t1);
	mergeSortParallel ( values, N, K, sorted );
	GET_TIME(t2);
	printf("Runtime = %g s \n", t2-t1);

    //Check for correctness
    checkArray ( values, N, sorted );

	return 0;
}
