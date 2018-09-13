unsigned int nextMilestone;

void modInsSort(int *arr, int left, int right)
{
	int i, p, t;

	for(i = left +1; i <= right; ++i)
	{
		p = i -1;
		t = arr[i];

		while(p >= left && t < arr[p])
		{
			arr[p + 1] = arr[p];
			--p;
		}

		arr[p + 1] = t;
	}
}

void mQSort(int *arr, int left, int right, int n)
{
	int pivotPos;

	if(left < right)
	{
		if((right - left) > MOD_QSORT_CUT_OFF)
		{
			pivotPos = partition(arr, left, right);

			mQSort(arr, left, pivotPos - 1, n);

			if(pivotPos >= nextMilestone)
			{
				printf("\t\t\t\t\r%lf%% completed", (pivotPos * 100.0)/n);
				fflush(NULL);
				nextMilestone += MASK;
			}

			mQSort(arr, pivotPos + 1, right, n);
		}
		else
		{
			modInsSort(arr, left, right);

			if(right >= nextMilestone)
			{
				printf("\t\t\t\t\r%lf%% completed", (right * 100.0)/n);
				fflush(NULL);
				nextMilestone += MASK;
			}
		}
	}
}

void modQSort(int *arr, int n)
{
	nextMilestone = MASK;
	printf("0%% completed");
	fflush(NULL);
	mQSort(arr, 0, n - 1, n);
}