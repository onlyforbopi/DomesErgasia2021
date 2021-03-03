

#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100


int stack[LIMIT];
int top;
int i;
int choice;

void push();
int pop();
void display();

int add(int a,int b){
    return a+b;
}
int multiply(int a,int b){
    return a*b;
}

int main()
{
    push(10);
    display();
    push(-3);
    display();
    int one = pop();
    int two = pop();
    int diafora1 = add(one,two) ;
    push(diafora1);
    display();
    push(8);
    display();
    push(3);
    display();
    one = pop();
    two = pop();
    int athroisma1 = add(one,two);
    push(athroisma1);
    display();
    one = pop();
    two = pop();
    int ginomeno1 = multiply(one,two);
    push(ginomeno1);
    display();
    push(2);
    one = pop();
    two = pop();
    int apotelesma = add(one,two);
    push(apotelesma);
    display();

}


void push(int element)
{
    
    //int stack[LIMIT], top, element;
    if(top == LIMIT- 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        
        top++;
        stack[top]=element;
    }
}

int pop()
{
    int element;
    if(top == -1)
    {
        return -1;
    }
    else
    {
        element=stack[top];
        top--;
        return element;
         // The element below the topmost element is deleted
}
}

void display()
{
    if(top == -1)
    {
        printf("Stack underflow\n"); // Stack is empty
    }
    else if(top > 0)
    {
        printf("The elements of the stack are:\n");
        for(i = top; i >= 0; i--) // top to bottom traversal
        {
            printf("%d\n",stack[i]);
        }
    }
}