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
void pop(){
    struct node *temp;
    temp = head;
    if (temp->next == NULL){
        head = NULL;
        printf("************************************************\n");
        printf("%d\n",temp->element);
        printf("************************************************\n");
        
        temp = NULL;
        free(temp);
        printf("************************************************\n");
        printf("The list is empty\n");
        printf("************************************************\n");
        return;
    }
    while(temp->next->next!=NULL){
        temp = temp->next;  
    }
    
    printf("************************************************\n");
    printf("%d\n",temp->next->element);
    printf("************************************************\n");
    temp->next = NULL;
    free(temp->next);

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
        printf("2. Pop element (LIFO)\n");
        printf("3. Display (LIFO)\n");
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