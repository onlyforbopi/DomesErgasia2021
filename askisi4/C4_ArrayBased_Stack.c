
#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100

// Init Basic Variables
int stack[LIMIT];
int top;
int i;
int choice;

// Function placeholders
void push();
int pop();
int peek();
void display();

// Main Function
int main()
{
    top = -1;
    choice = 1;
    while(choice!=5)
    {

        //
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Peek\n5. Exit\n\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        //
        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: exit(0);
            default: printf("Invalid choice. Re-enter.\n");break;
        }
    }
    

}

// Name: push
// Function: Pushes an element in the top of the stack.
// Input: None, it asks for user to specify the input element.
//        For our example the input element needs to be integer.
// Output: None, push operation simply adds a value to the LIFO.
// Usage: push()
// Notes: Push adds a value to the top of the stack, in a LIFO stack
//        top is really the only attribute we need to monitor. Here
//        we increment top, to add another index to our stack, and then
//        we assign the element to be entered into the stack.
void push()
{
    int element;
    //int stack[LIMIT], top, element;
    if(top == LIMIT- 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the element to be inserted:");
        scanf("%d", &element);
        top++;
        stack[top]=element;
        printf("Element was inserted at %d", stack[top]);
    }
}


// Name: pop
// Function: Pops the top element out of the stack.
// Input: None
// Output: Pop in most languages, /returns/ the top element.
// Usage: pop()
// Notes: Pop is the other basic Lifo stack operation, it removes
//        the top element of the stack, the last one to be inserted,
//        and returns it to the user for process.
//        If the stack is empty, we display a stack underflow message
//        and reprompt for input, in any other case we:
//        assign the value of stack[top] to the element we will return
//        decrement the top index, so that it points to the immediately
//        next element.
int pop()
{
    int element;
    if(top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        element=stack[top];
        printf("The deleted item is %d\n",stack[top]);
        top--; // The element below the topmost element is deleted
    }

    return element;
}

// Name: peek
// Function: Peeks the top element of the stack, without removing it.
// Input: None
// Output: None, could return the red value.
// Usage: peek()
// Notes: Peek is the third traditional Lifo Stack method and it simply
//        peeks the top value and returns it to the user, or prints it,
//        it is used for controls without altering the stack.
int peek()
{
    if (top == -1)
    {
        printf("Stack underflow. No values in stack.");
    }
    else
    {
        printf("The first element of the stack is %d", stack[top]);
        return stack[top];
    }
}

// Name: Display
// Function: Displays the entire stack
// Input: None
// Output: None
// Usage: display()
// Notes: If its empty, just prints underflow, in any other case
//        we iterate from the top of the stack, to the last element
//        by decrementing i, and print every element.
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