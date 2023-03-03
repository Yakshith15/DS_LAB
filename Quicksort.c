#include <stdio.h>

void print_Array(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i < j)
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } 

    
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; 

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  
        quickSort(A, partitionIndex + 1, high); 
    }
}

int main()
{
    int n;
    printf("ENter the size of the array\n");
    scanf("%d",&n);
    int A[n];
    printf("ENter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    quickSort(A, 0, n - 1);
    printf("THE sorted array is :");
    print_Array(A, n);
    return 0;
}
