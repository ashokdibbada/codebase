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
void popValues(struct node** dp);
void insertValues(struct node** dp,int pos,int data);
void deleteValues(struct node** dp, int pos);

int main(){
    struct node* head = NULL;
    int data,pos;
    cin>>data;
    appendValues(&head,data);
    cin>>data;
    cin>>pos;
    insertValues(&head,pos,data);
    printValues(head);
    cin>>data;
    appendValues(&head,data);
    cin>>data;
    appendValues(&head,data);
    cin>>data;
    appendValues(&head,data);
    popValues(&head);
    printValues(head);
    cin>>data;
    deleteValues(&head,data);
    printValues(head);
    return 0;
}

struct node* createNode(int data){
    struct node* new_node = new node;
    new_node->data = data;
    new_node->ptr = NULL;
    return new_node;
};

void appendValues(struct node** dp, int data){
    struct node* iter = NULL;
    if(*dp == NULL){
        struct node* new_node = createNode(data);
        *dp = new_node;
        new_node->ptr = *dp;
    }
    else{
        iter = *dp;
        while(iter->ptr != *dp){
            iter = iter->ptr;
        }
        struct node* new_node = createNode(data);
        new_node->ptr = *dp;
        iter->ptr = new_node;
    }
}

void printValues(struct node* pp){
    struct node* iter = pp;
    int length = 0;
    cout<<"Printing List"<<endl;
    do{
        cout<<iter->data<<endl;
        iter = iter->ptr;
        length++;
    }while(iter != pp);
    cout<<"Length:";
    cout<<length<<endl;
}

void popValues(struct node** dp){
    struct node* iter = *dp;
    struct node* slast = NULL;
    while(iter->ptr != *dp){
        slast = iter;
        iter = iter->ptr;
    }
    iter->ptr = NULL;
    slast->ptr = *dp;
    free(iter);
}

void insertValues(struct node** dp,int pos,int data){
    struct node* new_node = createNode(data);
    struct node* iter = *dp;
    struct node* slast = NULL;
    if(pos == 0){
        new_node->ptr = *dp;
        while(iter->ptr != *dp){
            iter = iter->ptr;
        }
        iter->ptr = new_node;
        *dp = new_node;
    }
    else{
        for(int i=0;i<pos;i++){
            slast = iter;
            iter = iter->ptr;
        }
        new_node->ptr = iter;
        slast->ptr = new_node;
    }
}

void deleteValues(struct node** dp,int pos){
    struct node* iter = *dp;
    struct node* slast = NULL;
    if(pos == 0){
        slast = *dp;
        while(iter->ptr != *dp){
            iter = iter->ptr;
        }
        iter->ptr = slast->ptr;
        *dp = slast->ptr;
    }
    else{
        for(int i=0;i<pos;i++){
            slast = iter;
            iter = iter->ptr;
        }
        slast->ptr = iter->ptr;
        iter->ptr = NULL;
        free(iter);
    }
}
