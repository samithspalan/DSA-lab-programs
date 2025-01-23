#include<stdio.h>
#define SIZE 4
int rear=-1, front=-1;
char queue[SIZE];
char item;
void insert()
{
if(front==((rear + 1) % SIZE))
printf("Queue is full.\n");
else
{
rear = (rear + 1) % SIZE;
printf("Enter ITEM: ");
scanf("%*c%c", &item);
queue[rear] = item;
printf("Item inserted: %c\n", item);
if(front == -1) 
front++;

}
}
void del()
{
if(front == -1)
printf("Queue is empty.\n");
else
{
item = queue[front];
printf("ITEM deleted: %c\n", item);
if(front == rear)
{
front = rear = -1;
}

else
front = (front + 1) % SIZE;

}
}
void display()
{
int i,j;
if(front == -1)
printf("Queue is empty.\n");
else
{ printf("Elements of queue are\n");
i = front;
while(i != rear)
{
printf("%c\t",queue[i]);
i = (i+1)%SIZE;
}
printf("%c\t",queue[i]);
printf("\n");
}
}
main()
{
int choice;
while(1)
{
choice=0; 
printf("\nCircular Queue Operations:\n");
printf("1.Insert \n2.Delete \n3.Display \n4.Exit \n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1: insert();
break;
case 2: del();
break;
case 3: display();
break;
case 4: return;
default:printf("Invalid choice.\n");

15
Department of Computer Science & Engineering, SCEM, Mangaluru.

CS322L5C:Data Structures Laboratory with C
return;

}
}
}