#include<stdio.h>

void Merge(int A[],int low,int mid,int high){
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            k++;
            i++;
        }
        else{
            B[k]=A[j];
            k++;
            j++;;
        }
    }
        while(i<=mid){
            B[k]=A[i];
            k++;
            i++;
        }
        while(j<=high){
            B[k]=A[j];
            k++;
            j++;
        }
       // A=B;
       for(int i=low;i<=high;i++){
        A[i]=B[i];
       }
    
}

void mergeSort(int A[],int low,int high){
    int mid;
    if(low<high){
        mid=(high+low)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}

int main(){
    int a;
    printf("Enter the size of the array:\n");
    int size;
    scanf("%d",&size);
    int A[size];
    printf("ENter the elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&A[i]);
    }
    mergeSort(A,0,size-1);
    printf("After the sorting the arry\n");
    for(int i=0;i<size;i++){
        printf("%d ",A[i]);
    }
}