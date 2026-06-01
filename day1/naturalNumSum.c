//Write a program to Calculate sum of first N natural numbers//
#include<stdio.h>
int main()
{
int i,n,sum=0;
printf("enter the number : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    sum=sum+i;

}
printf("The sum of the %d natural number is %d ",n,sum);


}