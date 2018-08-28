unsigned int nextMilestone;

/* Used to calculate the median of the first, middle and last elements of an array.
*/
int medianOf3(int *arr, int low, int high)
{
	int mid = low + (high - low) / 2;   //Same as (low + high) / 2, but prevents overflow when low and high are large.

	if(arr[mid] < arr[low])	//Placing the lowest out of the first and middle element in the 0th position.
		swap(&arr[mid], &arr[low]);
	
	if(arr[high] < arr[mid])	//Placing the lowest out of the middle and last element in the middle.
		swap(&arr[high], &arr[mid]);

	if(arr[mid] < arr[low])	//Placing the lowest out of the first and middle element in the 0th position.This takes care of situation like 3,2,1 (original array).
		swap(&arr[mid], &arr[low]);
	
	//The median is the element in the middle - that is our pivot. We swap the second last element and the median (mid element).
	//Because, the last element will anyway end up on the right side of the pivot.
	swap(&arr[mid], &arr[high - 1]);	
	
	return arr[high - 1];
}

int partition(int *arr, int low, int high)
{
    int pivot = medianOf3(arr, low, high), lastLow = low -1, i;

    for(i = low; i <= high -2; ++i)
    	if(arr[i] <= pivot)
    	{
    		++lastLow;
    		if(lastLow != i)
    			swap(&arr[lastLow], &arr[i]);
    	}

	++lastLow;
	if(lastLow != high -1)
    	swap(&arr[lastLow], &arr[high -1]);
    return lastLow;
}

void qSort(int *arr, int left, int right, int n)
{
	int pivotPos;

	if(left < right)
	{
		pivotPos = partition(arr, left, right);
		
		qSort(arr, left, pivotPos - 1, n);

		if(pivotPos >= nextMilestone)
		{
			printf("\t\t\t\t\r%lf%% completed", (pivotPos * 100.0)/n);
			fflush(NULL);
			nextMilestone += MASK;
		}

		qSort(arr, pivotPos + 1, right, n);
	}
}

void quickSort(int *arr, int n)
{
	nextMilestone = MASK;
	printf("0%% completed");
	fflush(NULL);
	qSort(arr, 0, n - 1, n);
}