/*	Takes an arr(array) as argument along with l(left), mid(middle) and r(right). Assumes that the subarray [l, mid] - both inclusive and [mid+1, r] - both
**	inclusive are sorted.

**	Creates two temporary arrays; with the first containing all elements from [l, mid] - both inclusive and the second array containing all elements from
**	[mid + 1, r] - both inclusive.

**	Overwrites the array sent as argument from [l, r] - both inclusive with the sorted elements of the two subarrays.
*/
void merge(int *arr, int l, int mid, int r)
{
	int i, j = 0, k = l, n1 = mid - l + 1, n2 = r - mid;
	int *left = malloc(n1 * sizeof(int)), *right = malloc(n2 * sizeof(int)); 
	
	for(i = 0; i < n1; ++i)
		left[i] = arr[l+i];
	for(i = 0; i < n2; ++i)
		right[i] = arr[mid + 1 + i];
	
	i = 0;
	while(i < n1 && j < n2)
		if(left[i] < right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	
	while(i < n1)
		arr[k++] = left[i++];
	
	while(j < n2)
		arr[k++] = right[j++];
	
	free(left);
	free(right);
}

/*	The standard mergeSort() function from CLRS and GeeksForGeeks, with the extra argument 'n' used to calculate the percentage of sorting completed.
*/
void mSort(int *arr, int l, int r, int n)	//The last argument is sent to calculate the percentage of sorting completed.
{
	if(l < r)
	{
		int mid = l + (r - l)/2;
		
		mSort(arr, l, mid, n);
		
		/*	Note: If you notice closely, 'mid' increases linearly at **this point**, i.e., 0 1 2 3 4 5 6 7 8 9 10 12 13 14 15 16...
		**	This happens due to the same reason as why you get sorted values when you do the inorder traversal of a Binary Search Tree.
		**	**This point** is the "inorder position", i.e., in between two recursive calls. You'll be able to connect this scene from your RBR Data Structure classes.
		**	Drawing a recursion tree may help you visualise how this works. This is indeed very interesting and took me some time to work out how to estimate
		**	progress like I did for Bubble, Selection and Insertion sort.
		*/
		if((mid & MASK) == 0)
		{
			printf("\t\t\t\t\r%lf%% completed", (mid * 100.0)/n);
			fflush(NULL);
		}
		
		mSort(arr, mid + 1, r, n);
		
		merge(arr, l, mid, r);
	}
}

/*	Note: The signature of mergeSort() could have been changed to what mSort()'s current signature is; and eliminated mSort() itself, but this was
**		  not done because we would not have been able to call mergeSort() using a pointer to function as is done in main().
*/
void mergeSort(int *arr, int n)
{
	mSort(arr, 0, n - 1, n);
}