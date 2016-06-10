#ifndef MSORT
#define MSORT

#include <pthread.h>

void mergeSortParallel (const int* values, unsigned int N, unsigned int K, int* sorted);

#endif
