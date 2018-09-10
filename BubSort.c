void bubSort(int *arr, int n)
{
	int i, j, t;

	MASK -= 1;
	/*	MASK is a power of 2. We need to reduce MASK by 1 to display the percentage after every MASK times.
	**	Example: Suppose MASK = 8. Our intention is to update the percentage after every 8 entries get sorted.
	**	The loop variable i starts from 0 and goes till n-1. We check whether the lower log MASK (base 2) bits of i are 0's or not.
	**	If they are 0's then we display the percentage, else not.
	**
	**	Say i is 0:-
	**		i 		-> 0000 0000
	**		MASK	-> 0000 0111
	**		Result	-> 0000 0000
	**	Since result is 0, the percentage gets displayed. Next, when i is 1, then:-
	**		i		-> 0000 0001
	**		MASK	-> 0000 0111
	**		Result	-> 0000 0001
	**	Since result is not 0, percentage is not updated. This continues until i becomes 8 when:-
	**		i		-> 0000 1000
	**		MASK	-> 0000 0111
	**		Result	-> 0000 0000
	**	Since the result is 0, percentage gets updated on screen.
	**	Again when i = 16:-
	**		i		-> 0001 0000
	**		MASK	-> 0000 0111
	**		Result	-> 0000 0000
	**	This is the reason why MASK needs to be decremented by 1. This makes sure that the lower bits are set in MASK.
	**	This method of bit arithmetic is preferred over using a counter which is incremented everytime (like what is done in QuickSort) to make the program a bit more efficient.
	*/
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