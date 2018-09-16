#define MIN_ARR_SIZE 10000	// It is assumed that MIN and MAX are powers of STEP. Also, MIN and MAX should not be greater than 2,147,483,647.
#define MAX_ARR_SIZE 100000000	// So, for example, if MIN is 16384 (2^14) and MAX is 65536 (2^16), then STEP should be 2.
#define STEP 10					// The code has been successfully tested for STEP values of 2 and 10.
#define OUT_FILE "time.txt"
#define FILE_BEG 1
#define FILE_DIVIDER 2
#define FILE_END 3
#define CUT_OFF_FOR_N2_ALGOS 1000000	//An array of 10^6 elements will take Bubble Sort roughly 50 mins to finish. That's the maximum supported size for n^2 algorithms.

typedef void (*FuncPtr)(int*, int);

int *array, *MASKS, MASK;

int qSortCutOffs[] = {8, 16, 32, 64};
int qSortNumber = 0;	//This variable is used to stored the index of the currently running modified Quick Sort version.
int noOfQSorts = sizeof(qSortCutOffs)/sizeof(qSortCutOffs[0]);