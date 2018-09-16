#define MIN_ARR_SIZE 10000	// It is assumed that MIN and MAX are powers of STEP.
#define MAX_ARR_SIZE 1000000	// So, for example, if MIN is 16384 (2^14) and MAX is 65536 (2^16), then STEP should be 2.
#define STEP 10					// The code has been successfully tested for STEP values of 2 and 10.
#define OUT_FILE "time.txt"
#define FILE_BEG 1
#define FILE_DIVIDER 2
#define FILE_END 3

typedef void (*FuncPtr)(int*, int);

int *array, *MASKS, MASK;

int qSortCutOffs[] = {16, 32, 64, 128, 256, 512};
int qSortNumber = 0;	//This variable is used to stored the index of the currently running modified Quick Sort version.
int noOfQSorts = sizeof(qSortCutOffs)/sizeof(qSortCutOffs[0]);