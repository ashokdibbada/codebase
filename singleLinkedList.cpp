#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

struct node{
    int data;
    struct node* ptr;
};


struct node* createNode(int data);
void appendValues(struct node** dp,int data);
void printValues(struct node* pp);
void popValues(struct node** dp);
void deleteValues(struct node** dp, int pos);
void insertValues(struct node** dp, int pos,int data);

int main(){
    struct node* head = NULL;
    int data;
    cin>>data;
    appendValues(&head,data);
    cin>>data;
    appendValues(&head,data);
    cin>>data;
    appendValues(&head,data);
    cin>>data;
    appendValues(&head,data);
    cin>>data;
    appendValues(&head,data);
    cin>>data;
    appendValues(&head,data);
    popValues(&head);
    deleteValues(&head,4);
    insertValues(&head,0,5);
    printValues(head);
    return 0;
}

struct node* createNode(int data){
    struct node* temp = new node;
    temp->data = data;
    temp->ptr = NULL;
    return temp;
};

void appendValues(struct node** dp,int data){
    if(*dp == NULL){
        *dp = createNode(data);
    }
    else{
        struct node* last = *dp;
        while(last->ptr != NULL){
            last = last->ptr;
        }
        last->ptr = createNode(data);
    }
}

void printValues(struct node* pp){
    cout<<"List:"<<endl;
    while(pp !=NULL){
    cout<<pp->data<<endl;
    pp = pp->ptr;
    }
}

void popValues(struct node** dp){
    if(*dp == NULL){
        cout<<"Empty"<<endl;
    }
    else{
        struct node* del = *dp;
        struct node* slast = NULL;
        while(del->ptr != NULL){
            slast = del;
            del = del->ptr;
        }
        slast->ptr = NULL;
    }
}

void deleteValues(struct node** dp, int pos){
    struct node* del = *dp;
    struct node* iter = NULL;
    if(pos==0){ // base case
        del = del->ptr;
        *dp = del;
    }
    else{
        for(int i=0;i<pos;i++){
            iter = del;
            del = del->ptr;
        }
        iter->ptr = del->ptr;
        free(del);
    }
}

void insertValues(struct node** dp,int pos,int data){
    struct node* new_node = createNode(data);
    if(pos==0){
        new_node->ptr = *dp;
        *dp = new_node;
    }
    else{
        struct node* ip = *dp;
        struct node* iter = NULL;
        for(int i=0;i<pos;i++){
                iter = ip;
                ip = ip->ptr;
        }
        new_node->ptr = ip;
        iter->ptr = new_node;
    }
}
