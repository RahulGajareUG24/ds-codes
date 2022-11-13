#include <stdio.h>
void SelectionSort(int a[],int n);
int main()
{
int a[100], n,i;
printf("pleaseEnter number of elements:");
scanf("%d", &n);
printf("Enter %d Numbersn", n);
for(i = 0; i < n; i++)
scanf("%d", &a[i]);
SelectionSort(a,n);
getch();
return 0;
}
void SelectionSort(int a[], int n)
{
int i, j, pos, temp;
for(i = 0; i < (n - 1); i++)
{
pos=i;
for(j = i + 1; j < n; j++)
{
if(a[pos]>a[j])
pos=j;
}
if(pos != i)
{
temp=a[i];
a[i]=a[pos];
a[pos]=temp;
}
}
printf("Sorted Array:,");
for(i = 0; i < n; i++)
printf("%d,", a[i]);
}