#include<stdio.h>
#include<stdlib.h>

#define size 10
int arr[size],i;
void insert(int value){   
    int key = value % size;
    if(arr[key] == -1){   
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else{   
        printf("Collision : arr[%d] has element %d already!\n",key,arr[key]);
        printf("Unable to insert %d\n",value);
    }
}
void del(int value){
    int key = value % size;
    if(arr[key] == value)
        arr[key] = -1;
    else
        printf("%d not present in the hash table\n",value);
}
void search(int value){
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}
void print(){
    for(i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}
int main(){
	int z,n,val;
	for(i = 0; i < size; i++)
        arr[i] = -1;
	printf("MENU\n1.insert\n2.delete\n3.search\n4.display\n5.exit\nEnter your choice:");
	while(1){
		printf("ENter ur choice\n");	
		scanf("%d",&z);
		switch(z){
			case 1:printf("enter the number of elements\n");
			scanf("%d",&n);
			printf("enter the elements\n");
			for(i=0;i<n;i++){
				scanf("%d",&val);
				insert(val);
			}
			break;
			case 2:printf("enter the value to be deleted\n");
			scanf("%d",&val);
			del(val);
			break;
			case 3:printf("enter the value to be searcched\n");
			scanf("%d",&val);
			search(val);
			break;
			case 4:printf("The hash table is\n");
			print();
			break;
			case 5: exit(0);
			break;
		}
	}
    return 0;
}