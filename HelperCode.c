void genRandInts(int n)
{
	int i;
	for(i = 0; i < n; ++i)
		array[i] = rand();
}

void copyArray(int *arr, int n)
{
	int i;
	for(i = 0; i <  n; ++i)
		arr[i] = array[i];
}

void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void formatFile(FILE *p, int position)
{
	if(position == FILE_BEG)
	{
		int i;
		fprintf(p, "%-30s", "Sorting Algorithm");
		for(i = MIN_ARR_SIZE; i <= MAX_ARR_SIZE; i *= STEP)
			fprintf(p, "| %16d ", i);
		fprintf(p, "\n");
	}
	else if(position == FILE_DIVIDER || position == FILE_END)
	{
		int i;
		for(i = 0; i < 30; ++i)
			fprintf(p, "-");
		for(i = MIN_ARR_SIZE; i <= MAX_ARR_SIZE; i *= STEP)
		{
			int j = 18;
			fprintf(p, "+");
			while(j--)
				fprintf(p, "-");
		}
		fprintf(p, "\n");
	}
}


/*	When argument is:- 			 0 -> calculates the mask for each array size and stores it in a dynamically created array which is pointed to by global pointer MASKS.
**								-1 -> frees the dynamically created MASKS array.
**	positive and is a power of STEP-> sets the global MASK.
**					 anything else -> undefined (neither does it throw any error nor handle it; i.e. no error checks have been put in place).
**
**	NOTE: Because of this function, the program needs to be compiled with the -lm switch.
**	Example: gcc main.c -o main.out -lm
*/
void calculateMasks(int size)
{
	if(size == 0)
	{
		int iterations = (log(MAX_ARR_SIZE) - log(MIN_ARR_SIZE))/log(STEP) + 1, i, j, k = 0;
		MASKS = malloc(iterations * sizeof(int));

		for(i = MIN_ARR_SIZE; i <= MAX_ARR_SIZE; i *= STEP, ++k)
		{
			int calcMask = i / 100;
			 /*	The percentage should be updated roughly 100 times (at most 100). It may be updated less than 100 times.
			 **	calcMask may not be a power of 2, so we find out the smallest power of 2 which is greater than calcMask.
			 **	For example, if calcMask = 100, our actual mask would be 128. In that case, the percentage is updated after every 128 elements have been sorted.
			 **	calcMask needs to be a power of 2 because bubble, selection, insertion and merge sort assume that MASK is a power of 2 to display
			 **	their progress percentage.
			 */

			 for(j = 63; j >= 0 && (calcMask & (1 << j)) == 0; --j);	//Find out the highest bit set.

			 if (calcMask == (1 <<j))
			 	MASKS[k] = 1 << j;
			 else
			 	MASKS[k] = 1 << (j +1);
		}
	}
	else if(size == -1)
	{
		free(MASKS);
	}
	else
	{
		int i = (log(size) - log(MIN_ARR_SIZE))/log(STEP);
		MASK = MASKS[i];
	}
}