#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ConstantsNGlobals.c"
#include "HelperCode.c"
#include "BubSort.c"
#include "SelSort.c"
#include "InsSort.c"
#include "MergeSort.c"
#include "QuickSort.c"
#include "ModQSort.c"
#include "HeapSort.c"

FuncPtr funcArr[] = {/*bubSort, selSort, insSort, mergeSort, quickSort, modQSort,*/ heapSort};
char* names[] = {/*"Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Modified Quick Sort",*/ "Heap Sort"};
int noOfFuncs = sizeof(funcArr)/sizeof(FuncPtr);

/*void main()
{
	clock_t start;
	int i, j, *arr;
	double timeTaken, clocksPS = (double)CLOCKS_PER_SEC;
	FILE *outFile = fopen(OUT_FILE, "w");
	
	
	srand(time(0));
	array = malloc(MAX_ARR_SIZE * sizeof(int));
	genRandInts(MAX_ARR_SIZE);
	calculateMasks(0);
	formatFile(outFile, FILE_BEG);
	
	for(i = 0; i < noOfFuncs; ++i)
	{
		formatFile(outFile, FILE_DIVIDER);
		fprintf(outFile, "%-30s", names[i]);
		printf("\nWorking on %s...", names[i]);
		fflush(NULL);
		
		for(j = MIN_ARR_SIZE; j <= MAX_ARR_SIZE; j *= STEP)
		{
			printf("\n\tArray size-> %d...\n", j);
			fflush(NULL);
			arr = malloc(j * sizeof(int));
			copyArray(arr, j);
			calculateMasks(j);
			
			start = clock();
			(*funcArr[i])(arr, j);
			timeTaken = (double) (clock() - start);
			timeTaken = timeTaken / clocksPS;
			
			fprintf(outFile, "| %16lf ", timeTaken);
			free(arr);
		}
		fprintf(outFile, "\n");
		printf("\n============Completed============\n");
		fflush(NULL);
	}
	
	formatFile(outFile, FILE_END);
	free(array);
	calculateMasks(-1);	//Freeing MASKS.
	fclose(outFile);
}*/

/*void main()
{
	int arr[] = {57, 23, 95, -5, 9, 45, 10, 7, 8, 12, 75, 36, 85, 123, -9, 54, 0, 1, 10, 48, 74, 81, 65, 16, 31, 98, 100, -4, 74, -85, 96, 48};
	int	n = sizeof(arr)/sizeof(arr[0]), i;
	quickSort(arr, n);
	
	printf("\n\nThe array is:\n");
	for(i = 0; i < n; ++i)
		printf("%d ", arr[i]);
		
}*/

void main()
{
	int arr[] = {57, 23, 95, -5, 9, 45, 10, 7, 8, 12, 75, 36, 85, 123, -9, 54, 0, 1, 10, 48, 74, 81, 65, 16, 31, 98, 100, -4, 74, -85, 96, 48};
	int n = sizeof(arr)/sizeof(arr[0]), i;

	heapSort(arr, n);
	printf("\n\nThe array is:\n");
	for(i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

/*void main()
{
	int iterations = (log(MAX_ARR_SIZE) - log(MIN_ARR_SIZE))/log(STEP) + 1, i;
	calculateMasks(0);

	printf("\n\nThe masks are:-\n");
	for(i = 0; i < iterations; ++i)
		printf("%d ", MASKS[i]);
	printf("\n");

	calculateMasks(1024);
	printf("Mask -> %d\n", MASK);

	calculateMasks(-1);
}*/