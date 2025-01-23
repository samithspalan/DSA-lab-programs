#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef struct
{
int front, rear;
int item[MAXSIZE];
} queue;
queue q1, q2, q3, q4;
int a[10], no=0, no2=0;
void insert(queue *q, int n)
{
if(q->rear==MAXSIZE)
{
printf("Queue is full.");
}
else
{
q->item[++q->rear]=n;
}
}
int delete(queue *q)
{
if(q->rear<q->front)
printf("Queue is empty.");
else
return q->item[q->front++];

}
//Display from Queue
void displayQ(queue *q)
{
int i;
no++;
if(q->rear<q->front)
{
printf("Group %d: Queue is empty.",no);
}
else
{
printf("Group %d: Contents of queue %d are\n ", no,no);
for(i=q->front; i<=q->rear; i++)
{
printf("%d\t", q->item[i]);
}
}
printf("\n");
}

void displaySorted(int a[])
{
no2++;
printf("Group %d: Contents after sorting\n ", no2);
for(int i=0; a[i]!='\0';i++)
{
printf("%d\t", a[i]);
a[i]='\0';
}
printf("\n");
}

void insertionSort()
{
for (int i = 1; a[i]!='\0'; i++)
{

10
Department of Computer Science & Engineering, SCEM, Mangaluru.

CS322L5C:Data Structures Laboratory with C

int element = a[i];
int j = i - 1;
while (j >= 0 && a[j] > element)
{
a[j + 1] = a[j];
j = j - 1;
}
a[j + 1] = element;
}
}
void sortqueue(queue *q)
{
for(int i=0;q->item[i]!='\0';i++)
{
a[i]=delete(q);
}
insertionSort(a);
displaySorted(a);
}
void main()
{
q1.front=0,q2.front=0,q3.front=0,q4.front=0;
q1.rear=-1,q2.rear=-1,q3.rear=-1,q4.rear=-1;
int i,n,a[50];
printf("Enter how many Elements:\n");
scanf("%d",&n);
printf("Enter %d Elements:\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

for(i=0;i<n;i++)
{
if(a[i]>=0 && a[i]<10)
{
insert(&q1, a[i]);
}
else if (a[i]>=10 && a[i]<20)
{
insert(&q2, a[i]);
}
else if (a[i]>=20 && a[i]<30)
{
insert(&q3, a[i]);
}
else if (a[i]>=30)
{
insert(&q4, a[i]);
}
}
printf("Categorised data into different group:\n");
displayQ(&q1);
displayQ(&q2);
displayQ(&q3);
displayQ(&q4);
printf("\nSorted data:\n");
sortqueue(&q1);
sortqueue(&q2);
sortqueue(&q3);
sortqueue(&q4);
}