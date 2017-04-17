#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    struct node* ptr;
};

struct node* createNode(int data);
void appendValues(struct node** dp, int data);
void printValues(struct node* pp);
void deleteValues(struct node** dp);

int main(){
    struct node* head = NULL;
    int data;
    cin>>data;
    appendValues(&head,data);
    cin>>data;
    appendValues(&head,data);
    cin>>data;
    appendValues(&head,data);
    printValues(head);
    deleteValues(&head);
    printValues(head);
    cin>>data;
    appendValues(&head,data);
    printValues(head);
    deleteValues(&head);
    printValues(head);
    deleteValues(&head);
    return 0;
}

struct node* createNode(int data){
    struct node* new_node = new node;
    new_node->data = data;
    new_node->ptr = NULL;
    return new_node;
};

void appendValues(struct node** dp, int data){
    if(*dp == NULL){
        *dp = createNode(data);
    }
    else{
        struct node* new_node = createNode(data);
        new_node->ptr = *dp;
        *dp = new_node;
    }
}

void deleteValues(struct node** dp){
    if( *dp == NULL){
        cout<<"Empty"<<endl;
    }
    else{
    struct node* iter = *dp;
    iter = iter->ptr;
    *dp = iter;
}
}

void printValues(struct node* pp){
    cout<<"Printing Stack"<<endl;
    int length = 0;
    while( pp != NULL){
        cout<<pp->data<<endl;
        pp = pp->ptr;
        length++;
    }
    cout<<"Length:";
    cout<<length<<endl;
}
