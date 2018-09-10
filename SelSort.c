void selSort(int *arr, int n)
{
	int i, j, t, pos;

	MASK -= 1;	//The reason for this decrementation has been explained in BubSort.c file.
	for(i = 0; i < n -1; ++i)
	{
		if((i & MASK) == 0)
		{
			printf("\t\t\t\t\r%lf%% completed", (i * 100.0)/n);
			fflush(NULL);
		}
		pos = i;
		for(j = i + 1; j < n; ++j)
			if(arr[pos] > arr[j])
				pos = j;
		
		if(pos != i)
		{
			t = arr[pos];
			arr[pos] = arr[i];
			arr[i] = t;
		}
	}
}