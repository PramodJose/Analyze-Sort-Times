/*	maxHeapify() assumes that array indexing starts from 0 (and not 1 as is popularly followed).
**	In such a case, the left child of a node situated at position i is at (2*i) +1...
**	...and the right child is at position (2*i) +2.
**	Also, 'size' must contain the number of nodes in the heap.
**
**	maxHeapify() assumes that the left and right sub-tree of the node at index i (sent as argument), are already max-heaps.
**	maxHeapify() then proceeds to place the node at index i in its correct position in the tree.
**	Note that nodes at indices lesser than i are not considered for the time being.
**
**	The time complexity of this function is O(log i); where i is the index of the node which needs to be "maxHeapify-ed".

**	NOTE: Some portions of the code may be optimised for better performance [eg, 2*i +1 can be written as ((i << 1) | 1)], but this has been avoided to increase readability.
**
**	This procedure has been adapted (with some modifications) from Ravindrababu Ravula's online lecture - https://www.youtube.com/watch?v=2fA1FdxNqiE
*/

void maxHeapify(int *arr, int i, int size)
{
	int leftChild = (2*i) +1, rightChild = (2*i) +2, largest;

	if(leftChild < size && arr[leftChild] > arr[i])
		largest = leftChild;
	else
		largest = i;
	if(rightChild < size && arr[rightChild] > arr[largest])
		largest = rightChild;
	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		maxHeapify(arr, largest, size);
	}
}

/*	buildMaxHeap() assumes that array indexing starts from 0 (and not 1).
**	In such a case, the index of the first leaf = size/2, where size is the number of nodes present in the heap and the index of the last leaf = size -1.
**	We start off with the last non-leaf element, i.e. at index (size/2 -1) and make our way to the root of the heap (i.e. a decrementing loop).
**	We call maxHeapify() on each of these indices. Since the leaves are max-heaps in their own right, and since we are working our way up the tree, we would successfully
**	be able to build a max-heap in this way.
**
**	NOTE: It may seem as if the whole process takes O(n * logn) time, but amortized (average case) analysis shows that this only takes O(n) time. This has been explained in the video mentioned below from 4:30 mins.
**	NOTE: Some portions of the code may be optimised for better performance [eg, size /2 can be written as size >> 1)], but this has been avoided to increase readability.
**
**	This procedure has been adapted (with some modifications) from Ravindrababu Ravula's online lecture - https://www.youtube.com/watch?v=HI97KDV23Ig
*/
void buildMaxHeap(int *arr, int size)
{
	int nonLeaf = size/2 -1;
	while(nonLeaf >= 0)
	{
		maxHeapify(arr, nonLeaf, size);
		--nonLeaf;
	}
}

void heapSort(int *arr, int n)
{
	int i, size = n;
	//nextMilestone = MILESTONE;
	buildMaxHeap(arr, n);	//This takes O(n) time.

	for(i = n -1; i > 0; --i)	//This takes O(n logn) time.
	{
		swap(&arr[0], &arr[i]);
		--n;
		maxHeapify(arr, 0, n);
	}
}