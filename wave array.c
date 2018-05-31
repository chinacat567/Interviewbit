#include <stdio.h>
#include<stdlib.h>
int comparator(const void *a, const void *b)
 {
     int l=*(const int*)a;
     int r=*(const int*)b;
     return(l-r);
 }
 
 void swap(int *x, int*y)
 {
     int temp=*x;
     *x=*y;
     *y=temp;
     
 }


int* wave(int* A, int n1) {
    qsort((void *)A,n1,sizeof(A[0]),comparator);
    int i;
   
    int *result=(int*)malloc(sizeof(int)*n1);
    for(i=0;i<n1-1;i+=2)
    {
       swap(&A[i],&A[i+1]);
    }
    result[n1-1]=A[n1-1];
    for (int i = 0; i < n1; ++i)
    {
        result[i]=A[i];
    }
    return result;
       
}

int main(void)
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    int *ans= wave(arr,n);

    for(i=0;i<n;i++)
        
        printf("%d\n",ans[i] );
}
