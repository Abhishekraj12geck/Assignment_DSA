// Question 2: Modular Array Operations (7 Marks)
// Develop a C program to perform the following tasks using pointers for all array operations:
// Part (i): Dynamic Input (1 Mark)
// Implement a function int* input array(int* size, int* max size) that:
// • Accepts integers until a maximum limit is reached or a negative integer is entered.
// • Returns the pointer to the array and updates the actual size.
// Part (ii): In-place Reversal (4 Marks)
// Implement a function void reverse array(int* arr, int* size) that:
// • Reverses the elements of the array using two-pointer logic.
// • Does not use a secondary helper array.
// Part (iii): Uniqueness Validation (2 Marks)
// Implement a function int check unique array(int* arr, int* size) that:
// • Returns 1 if all elements are unique, and 0 if duplicates are found.
// • Performs comparisons using pointer arithmetic.


#include<stdio.h>
#include<stdlib.h>
#define S 100
int *input_array(int *array,int *length){

    int size=0;
    printf("Enter array elements:");
    for(int i=0;i<S;i++){
     scanf("%d",&array[i]);
        if(array[i]<0){
            break;
        }   
        size=size+1;
    }
    *length=size;
    return array;
}

void reverse_array(int *array,int *length){
 int n= (*length)/2;

 for(int i=0;i<n;i++){
 int temp= array[i];
 array[i]=array[(*length)-i-1];
 array[(*length)-i-1] = temp;
 }
}

int *check_unique_array(int *array,int *length){
int *unique_adress=(int*)malloc(sizeof(int));
*unique_adress=0;
int n=*length;

for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(array[i]==array[j]){
         *unique_adress=1;
         return unique_adress;
        }
    }
}
return unique_adress;
}
int main(){
    int array[S],*unique,i;
    int *length=(int*)malloc(sizeof(int));
    *length=0;
    printf("Max Size of an array =100\n");

    input_array(array,length);
    printf("the actual length of array is: %d\n",*length);
    printf("Array Input is:");
    for(i=0;i<*length;i++){
        printf(" %d", array[i]);
    }

    reverse_array(array,length);
    printf("\nthe array after reverse:");
    for(i=0;i<*length;i++){
        printf(" %d", array[i]);
    }

    unique=check_unique_array(array,length);
      if(*unique==1){
        printf("\nArray elements are not unique.");
      }
      else {
      printf("\nArray elements are unique.");
      }
      free(length);
      free(unique);

    return 0;
}
