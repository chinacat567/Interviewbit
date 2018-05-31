#include <stdio.h>
#include<stdlib.h>

int digits(int n)
 {
     int count=0;
     while(1)
     {
         count++;
         n=n/10;
         if(n==0)
            break;
         
     }
     return count;
 }
int comp(const int*a, const int*b)
{
    int digits_a,digits_b,i=0,j=0;
    int l=*a;
    int r=*b;
    digits_a=digits(l);
    digits_b=digits(r);
    while(i<digits_a)
    {
        r=r*10;
        i++;
        
    }
    r=r+(*a);

    l=l+(*b);
    if(l>r)
    return 1;
    else if(l<r)
    return -1;
    else return 0;
}

char* largestNumber(const int* A, int n1) {
    int i=0,str_len=0,j=0,k=0, flag=0;
    int *dig=(int*)malloc(sizeof(int)*n1);
    int *B=(int*)malloc(sizeof(int)*n1);
   
    qsort((void*)A,n1,sizeof(int),comp);
    
    for(i=0;i<n1;i++)
    {
       dig[i]=digits(A[i]);
       str_len=str_len + dig[i];
       B[i]=A[i];
       if(A[i]>0)
       flag=1;
    
    }
    if(flag==0)
    {
        char s[2];
        s[0]=0;
        s[1]='/0';
        return s;
         return 0;
    }
    
    char *result=(char*)malloc(sizeof(char)*(str_len+1));
   
   for (i =n1-1; i>=0; i--)
   {

j=dig[i];
   while(1)
   {

   result[k+j-1]= B[i]%10+'0';
    B[i]=B[i]/10;
    j--;
    if(B[i]==0)
        break;
   }

   k=k+dig[i];   
}
result[str_len]='\0';


return result;

}


int main(void)
{

int A[]={3,30,34,5,9};
char*B=largestNumber(A,5);

   printf("%s\n", B); /* code */

}