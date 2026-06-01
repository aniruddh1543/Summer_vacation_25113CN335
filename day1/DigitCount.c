#include<stdio.h>
int main()
{
int count=0,i,n;
printf("enter the number : ");
scanf("%d",&n);
while (n>0)
{
    n=n/10;
    count++;
}
    printf("Total digits = %d", count);
return 0;



}  