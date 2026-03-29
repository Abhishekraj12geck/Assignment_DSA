#include<stdio.h>
int BinarySearch(int arr[],int left,int right,int target){
    // for(left=0,right=n-1;left<=right;){
    //or
    while(left <= right){
     int mid=(left+right)/2;

     if(arr[mid]==target)
     return mid+1;

     else if(arr[mid]<target)
     left=mid+1;

     else
     right=mid-1;
    }
    return left;
}
void insertion_sort(int arr[],int n){
    int key;
    for(int i=1;i<n;i++){
        key=arr[i];

           // Find location to insert using Binary Search
        int pos = BinarySearch(arr, 0, i - 1, key);

        // Shift elements to make space
       int j=i-1;
    while(j>=pos){
        arr[j+1]=arr[j];
        j=j-1;
    }
    arr[pos]=key;
}
}

void ArraySorted(int arr[],int n){
 for(int i=0;i<n;i++){
    printf(" %d", arr[i]);
}
}
int main(){
    int arr[]={8,17,23,4,6,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Original Array:");
    ArraySorted(arr,n);
    insertion_sort(arr,n);   
    printf("\nsorted Array:");
   ArraySorted(arr,n);
  return 0;
 }

