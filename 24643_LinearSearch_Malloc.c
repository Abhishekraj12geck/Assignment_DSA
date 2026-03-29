// linear search with malloc:
// wap in 'c' to find a key element from an array of n elements.

// Dynamically allocate memory for each array using malloc();
// input the array size and element from the user.
// properly free() the allocated memory


#include<stdio.h>
#include<stdlib.h>

int linear_search(int arr[],int n,int key){
  for(int i=0;i<n;i++){
    if(arr[i]==key){
        return i;
    }
  }
  return -1;
}

int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    //for allocation of 'n' no. of integer in memory memory

  int *arr=(int *)malloc(n*sizeof(int));    
    printf("Array Elements is:");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    
    int key;
    printf("Elements to search:");
    scanf("%d",&key);
   int result =  linear_search(arr,n,key);
   if(result!=-1){
  printf("%d exits at index %d in the array",key,result);
  }
  else{
    printf("%d is not found in array",key);
  }
  return 0;
  free(arr);
}
