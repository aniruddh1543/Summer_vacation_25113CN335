//table of a number input from user//
#include<stdio.h>
int main()
{int n,i ,table ;
    printf("Enter the number");
    scanf("%d",&n);
    for (i=1;i<=10;i++)
{
        table=n*i;
        printf("%d\n",table);

}
    return 0;
}