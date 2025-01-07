#include<stdio.h>
#include<stdlib.h>
int a[100],i,j,n;
int frequency[10]={0};
void getdata();
void printdata();
void makefrequency();
void makeHistogram();
void main()
{
getdata();
printdata();
makefrequency();
makeHistogram();
}
void getdata()
{
printf("enter the how many number of array elements\n");
scanf("%d",&n);
if(n ==0)
{
printf( "Array is Empty\n");
exit(0);
}
printf("Enter %d elements between the range 0-9\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);


}
}
void printdata()
{
printf("The array elements are \n");
for(int i = 0; i < n; i++)
printf("%d\t",a[i]);
}
void makefrequency()
{
for(i=0;i<10;i++)
for(j=0;j<n;j++)
if(a[j]==i)
frequency[i]++;

}
void makeHistogram()
{
printf("\nFrequency histogram is:\n");
printf("Histo---Frequency\t");
for(i=0;i<10;i++)
{
printf("\n[%d]",i);
for(j=0;j<frequency[i];j++)
printf("\t*");

}
printf("\n");
}