#include<stdio.h>
#include<stdlib.h>
void merging(int *b, int *c,int *a,int m,int n ){
    int i=0,j=0,k=0;
  while((i<m) && (j<n)){
    if(b[i]<c[j]){
        a[k]=b[i];
        i++;
    }
    else{
        a[k]=c[j];
        j++;
    }
    k++;
}
if(i==m){
    for(int p=j;p<n;p++){
        a[k]=c[p];
        k++;
    }
}
else{
    for(int p=i;p<m;p++){
        a[k]=b[p];
        k++;
    }
}
}
void merging_sort(int *A,int n){
    int*B,*C;
    int k=n/2;
    int m=n-k;
    if(n>1){
        B=(int *)malloc(k*(sizeof(int)));
        C=(int *)malloc(m*(sizeof(int)));
        for(int i=0;i<k;i++){
            B[i]=A[i];
        }
        for(int j=k;j<n;j++){
            C[j-k]=A[j];
        }
        merging_sort(B,k);
        merging_sort(C,m);
        merging(B,C,A,k,m);
        free(B);
        free(C);
    }
}

void ArraySorted(int arr[],int n){
 for(int i=0;i<n;i++){
    printf(" %d", arr[i]);
}
}
int main(){
    int arr[]={8,7,3,4,6,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Original Array:");
    ArraySorted(arr,n);
 merging_sort(arr,n);   
 printf("\nsorted Array:");
  ArraySorted(arr,n);
  return 0;
 }
