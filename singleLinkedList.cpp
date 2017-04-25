#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct node {
    int data;
    struct node* next;
};

void printList(struct node* pp);
int ListLength(struct node* lp);
struct node* createNode(int data);
void appendNode(struct node** dp,int data);
void insertNode(struct node** dp,int data,int pos);
void delValues(struct node** dp,int pos);

int main(){
    struct node* head = NULL;
    int number,pos,i=0;
    while(i != 5){
    cout<<"Enter code for following operations: \n 1:Create or Append \n 2:Print List \n 3:Insert \n 4:Delete \n 5:Exit \n"<<endl;
    cout<<"Enter choice: ";
    cin>>i;
    if(i==1){
        cout<<"Enter Data element:  ";
        cin>>number;
        appendNode(&head,number);
    }
    if(i==2){
        printList(head);
    }
    if(i==3){
        int length = ListLength(head);
        cout<<"Linked List Length is: ";
        cout<<length<<endl;
        cout<<"Enter number between 0 and Length: ";
        cin>>pos;
        cout<<"Enter Data element: ";
        cin>>number;
        insertNode(&head,number,pos);
    }
    if(i==4){
        int length = ListLength(head);
        cout<<"Linked List Length is: ";
        cout<<length<<endl;
        cout<<"Enter number between 0 and Length: ";
        cin>>pos;
        delValues(&head,pos);
    }
    }
    return 0;
}

void printList(struct node* pp){
    cout<<"-------------"<<endl;
    cout<<"The Elements are: "<<endl;
    while(pp != NULL){
        cout<<pp->data<<endl;
        pp = pp->next;
    }
    cout<<"-------------"<<endl;
};

struct node* createNode(int data){
    struct node* new_node = new node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
};

void appendNode(struct node** dp,int data){
    if(*dp == NULL){
        * dp = createNode(data);
    }
    else{
        struct node* iter = *dp;
        while(iter->next != NULL){
            iter = iter->next;
        }
        iter->next = createNode(data);
    }
};

int ListLength(struct node* lp){
    int length = 0;
    while(lp != NULL){
        lp = lp->next;
        length++;
    }
    return length;
};

void insertNode(struct node** dp,int data,int pos){
    int length = ListLength(*dp);
    struct node* new_node = createNode(data);
    if(pos == 0){
        new_node->next = *dp;
        * dp = new_node;
    }
    else{
        if(pos<=length){
            struct node* iter = *dp;
            struct node* prev = NULL;
            for(int i=0;i<pos;i++){
                prev = iter;
                iter = iter->next;
            }
            prev->next = new_node;
            new_node->next = iter;
        }
    }
};


void delValues(struct node** dp,int pos){
    if(*dp == NULL){
        cout<<"Empty List"<<endl;
    }
    else{
        int length = ListLength(*dp);
        struct node* del = *dp;
        struct node* temp = NULL;
        if(pos<length){
        if(pos==0){
            del = del->next;
            *dp = del;
        }
        else{
            for(int i=0;i<pos;i++){
                temp = del;
                del = del->next;
            }
            temp->next = del->next;
            del->next = NULL;
            free(del);
        }
        }
    }
};
