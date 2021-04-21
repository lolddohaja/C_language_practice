#include <stdio.h>
int main(void)
{
int arr1[5]={1, 2, 3, 4, 5};
int arr2[]={1, 2, 3, 4, 5, 6, 7};
int arr3[5]={1, 2};
int a = 10;
int b = 20;

int *p;
int *p2;
p = &arr1[2];
p2 = &a;

return 0;
}