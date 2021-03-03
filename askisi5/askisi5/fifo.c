#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int element;
    struct node *next;
};
struct node *head;
void push(int element){
    struct node *temp;
    struct node *tempHead;
    tempHead = head;
    temp = (struct  node*)malloc(sizeof(struct node));
    temp->element = element;
    
    if (tempHead == NULL){
        head = temp;
        head->next = NULL;
    }
    else{
        while(tempHead->next != NULL){
            tempHead = tempHead->next;
        }
        tempHead->next = temp;
        temp->next = NULL;
    }
    
}

struct node pop() {

    struct node *current = head;
    printf("%d\n",current->element);
    head = current->next;
    return *current;    
}
void display(){
    struct node *r;
    r = head;
    if (r==NULL){
        return;
    }
    printf("************************************************\n");
    while (r!=NULL){
        printf("%d\n",r->element);
        r=r->next;
    }
    printf("************************************************\n");
}

int main(){
    int selection;
    int element;
    
    while (1){
        printf("Menu\n");
        printf("1. Push Element(int)\n");
        printf("2. Pop element (FIFO)\n");
        printf("3. Display (FIFO)\n");
        
        printf("4. Exit\n");
        printf("Make a choice:");
        scanf("%d",&selection);
        if (selection==4){
            printf("END.");
            return 0;
        } else if (selection==3){
            display();
        } else if (selection==2){
            pop();
        } else if (selection==1){
            printf("Enter Element:");
            scanf("%d",&element);
            
            push(element);
        }
    }
    return 0;
}