void insSort(int *arr, int n)
{
	int i, p, t;

	MASK -= 1;	//The reason for this decrementation has been explained in BubSort.c file.
	for(i = 1; i < n; ++i)
	{
		if((i & MASK) == 0)
		{
			printf("\t\t\t\t\r%lf%% completed", (i * 100.0)/n);
			fflush(NULL);
		}

		p = i - 1;
		t = arr[i];

		while(p >= 0 && t < arr[p])
		{
			arr[p + 1] = arr[p];
			--p;
		}
		
		arr[p + 1] = t;
	}
}