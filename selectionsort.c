#include <stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	
	for (i = 0; i < n-1; i++)
	{
		
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		if(min_idx != i)
			swap(&arr[min_idx], &arr[i]);
	}
}


int main()
{
	printf("Enter size of the array\n");
	int n;
	scanf("%d",&n);
	int A[n];
	printf("Enter the elements of the array\n");
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	selectionSort(A, n);
	printf("Sorted array: \n");
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	return 0;
}
