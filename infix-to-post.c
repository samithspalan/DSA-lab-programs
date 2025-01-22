#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20
char stack[SIZE];
int top = -1;
void push(char elem)
{
stack[++top] = elem;
}
char pop()

{
return (stack[top--]);
}
int precedence(char elem) /* Decides the precedence */
{
switch (elem)
{
case'#': return 0;
case'(': return 1;
case'+':
case'-': return 2;
case'*':
case'/':
case'%': return 3;
case'^': return 4;
default: printf("Not a Valid Expression\n");
exit(0);

}
}
void main()
{
char infix[20], postfix[20], ch, elem;
int i = 0, k = 0, pr;
printf("Enter the Infix Expression: ");
scanf("%s", infix);
push('#'); 
while ((ch = infix[i++]) != '\0')
{
if (ch == '(') 
{
push(ch);
}
else if (isalnum(ch)) 
{
postfix[k++] = ch;
}
else if (ch == ')') 
{
while (stack[top] != '(')
{
postfix[k++] = pop();
if(stack[top] == '#')
{
printf("Not a Valid Expression\n");
exit(0);
}
}
elem = pop(); /* Removing left parenthesis */
}
else 
{
pr=precedence(ch);
if(ch=='^')
{
pr++; 

}
while (precedence(stack[top]) >= pr)
{
postfix[k++] = pop();
}
push(ch); 
}
}
while (stack[top] != '#') 
{
postfix[k++] = pop();
}
postfix[k] = '\0'; 
printf("Given Infix Expression: %s\nPostfix Expression: %s\n", infix, postfix);
}