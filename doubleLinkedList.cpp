#include <iostream>

using namespace std;

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createNode(int data);
void appendValues(struct node** dp, int data);
void printValues(struct node* pp);
void popValues(struct node** dp);
void insertValues(struct node** dp, int pos, int data);
void deleteValues(struct node** dp, int pos);

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
    insertValues(&head,1,data);
    cin>>data;
    insertValues(&head,1,data);
    printValues(head);
    deleteValues(&head,1);
    printValues(head);
    return 0;
}

struct node* createNode(int data){
    struct node* new_node = new node;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void appendValues(struct node** dp, int data){
    if(*dp == NULL){
        *dp = createNode(data);
    }
    else{
        struct node* iter = *dp;
        struct node* temp = NULL;
        while(iter->next != NULL){
            iter = iter->next;
        }
        iter->next = createNode(data);
        temp = iter;
        iter = iter->next;
        iter->prev = temp;
    }
}

void printValues(struct node* pp){
    cout<<"Printing List"<<endl;
    while(pp->next != NULL){
        pp = pp->next;
    }
    while(pp != NULL){
        cout<<pp->data<<endl;
        pp=pp->prev;
    }
}

void popValues(struct node** dp){
    if(*dp == NULL){
        cout<<"Empty"<<endl;
    }
    else{
        struct node* iter = *dp;
        struct node* slast = NULL;
        while(iter->next != NULL){
            slast = iter;
            iter = iter->next;
        }
        slast->next = NULL;
    }
}

void insertValues(struct node** dp, int pos, int data){
    struct node* new_node = createNode(data);
    struct node* iter = *dp;
    if(pos == 0){
        new_node->next = iter;
        new_node->prev = NULL;
        iter->prev = new_node;
        *dp = new_node;
    }
    else{
        struct node* temp = NULL;
        for(int i=0;i<pos;i++){
            temp = iter;
            iter = iter->next;
        }
        iter->prev = new_node;
        temp->next = new_node;
        new_node->next = iter;
        new_node->prev = temp;
    }
}

void deleteValues(struct node** dp, int pos){
    struct node* iter = *dp;
    if(pos==0){
            iter =iter->next;
            iter->prev = NULL;
            *dp = iter;
    }
    else{
        struct node* temp = NULL;
        for(int i=0;i<pos;i++){
            temp = iter;
            iter = iter->next;
        }
        temp->next = iter->next;
        iter->next->prev = temp;
    }
}
