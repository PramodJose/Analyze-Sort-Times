void bubSort(int *arr, int n)
{
	int i, j, t;

	for(i = 0; i < n - 1; ++i)
	{
		if((i & MASK) == 0)
		{
			printf("\t\t\t\t\r%lf%% completed", (i * 100.0)/n);
			fflush(NULL);
		}
		for(j = 0; j < n - i - 1; ++j)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j+1]);
	}
}