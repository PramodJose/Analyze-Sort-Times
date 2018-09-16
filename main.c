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

FuncPtr funcArr[] = {bubSort, selSort, insSort, heapSort, mergeSort, quickSort, modQSort};
char* names[] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Heap Sort", "Merge Sort", "Quick Sort", "Modified Quick Sort"};
int noOfFuncs = sizeof(funcArr)/sizeof(FuncPtr);

void main()
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

		//If the function is Modified Quick Sort, then append the CUT OFF limit in brackets when printing the algorithm name to the file...
		if(funcArr[i] == modQSort)
		{
			char buffer[64];
			/*	The field length of "Algorithm Name" in the file is assumed to be maximum 30, so a buffer size of 64 is
			**	not necessary; but it is made 64 so that even if the field length is increased later, it won't be a problem.
			*/

			sprintf(buffer, "%s (%d)", names[i], qSortCutOffs[qSortNumber]);
			fprintf(outFile, "%-30s", buffer);
			printf("\nWorking on %s...", buffer);
		}
		else	//...else, just print the name of the algorithm as is.
		{
			fprintf(outFile, "%-30s", names[i]);
			printf("\nWorking on %s...", names[i]);
		}

		fflush(NULL);
		
		for(j = MIN_ARR_SIZE; j <= MAX_ARR_SIZE; j *= STEP)
		{
			printf("\n\tArray size-> %d...\n", j);
			fflush(NULL);

			if(j > CUT_OFF_FOR_N2_ALGOS && (funcArr[i] == bubSort || funcArr[i] == selSort || funcArr[i] == insSort))
			{
				printf("----- SKIPPED -----");
				fprintf(outFile, "| %16s ", "TLE");	//Time Limit Exceeded
			}
			else
			{
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
		}

		//If the number of Modified Quick Sorts have not been exhausted, then we need to run modQSort() again; hence, decrement i.
		if(funcArr[i] == modQSort && ++qSortNumber != noOfQSorts)
			--i;

		fprintf(outFile, "\n");
		printf("\n============ Completed ============\n");
		fflush(NULL);
	}
	
	formatFile(outFile, FILE_END);
	free(array);
	calculateMasks(-1);	//Freeing MASKS.
	fclose(outFile);
}