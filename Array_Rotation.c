//give an array A of length n that was originally sorted in ascending order and then rotated by k steps,it might now become unsorted now ,determine the length of the contigupous sub-array A[i.....j] such that
//stability:-A[m]>=A[m-1] for all k in the range(0<m<=n-1).

// Example:-original array:[0,1,2,3,4,5,6]
// Rotated(k=4):[4,5,6,7,0,1,2,3]
// longest sorted subarray:[4,5,6,7](length 4) and [0,1,2,3](length 4).


//using extra array........
#include<stdio.h>
int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("Array A is:");
    for(int i=0;i<n;i++){
    printf(" %d ", A[i]);
    }
    printf("\n");
    int B[n];
    int k=4;
    for(int i=0;i<n;i++){
     B[((i+k)%n)]=A[i];//new array B me elements rotate ho gya 
    }

      printf("Rotated array");
     for(int i=0;i<n;i++){
        printf(" %d ",B[i]);
    }
    int current_length=1;   //initially  koi element khud ke respect me to sorted hoga length=1
    int max_length=1;

    for(int i=0;i<n-1;i++){// i<n-1: kyki last wala element ek back element se compare hoke chota bada pata 
    // chal jayega to index n-1 means nth element par jaane ki koi jarurat nhi hai kyuki uske baad koi element nhi h
    if(B[i+1]>B[i]){ 
        current_length++;
    }
    else{
        if(current_length>max_length){
            max_length=current_length;
        }
        current_length=1;
    }
    }

    if(current_length>max_length){
        max_length=current_length;
    }
    printf("\nmax length of sorted subarray in array A is = %d\n",max_length);
    return 0;
}


//without using extra array.........
// #include<stdio.h>

// void reverse(int A[], int l, int r){
//     while(l < r){
//         int temp = A[l];
//         A[l] = A[r];
//         A[r] = temp;
//         l++;
//         r--;
//     }
// }

// int main(){
//     int n;
//     printf("Enter n:");
//     scanf("%d",&n);

//     int A[n];
//     printf("Elements of array A:");
//     for(int i=0;i<n;i++){
//         scanf(" %d", &A[i]);
//     }

//     int k;
//     printf("Enter times of Rotation:");
//     scanf("%d",&k);

//     reverse(A, 0, n-1);  // reverse whole array

//     reverse(A, 0, k-1); //reverse first k elements

//     reverse(A, k, n-1); // reverse remaining n-k elements

//     printf("\nRotated Array:");
//     for(int i=0;i<n;i++){
//         printf(" %d ", A[i]);
//     }
//     printf("\n");

//     int current_length = 1;
//     int max_length = 1;

//     for(int i=0;i<n-1;i++){
//         if(A[i+1] > A[i]){
//             current_length++;
//         }
//         else{
//             if(current_length > max_length){
//                 max_length = current_length;
//             }
//             current_length = 1;
//         }
//     }

//     if(current_length > max_length){
//         max_length = current_length;
//     }

//     printf("\nmax length of sorted subarray is = %d\n", max_length);

//     return 0;
// }
