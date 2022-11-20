#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int data){
        this->data=data;
        next=NULL;
    }
};

void print(node *head){
    node *temp=head;
    if(head==NULL)
    cout<<"list is empty"<<endl;
    while(temp!=NULL){
        cout<<temp->data<<"|";
        temp=temp->next;
    }
    cout<<endl;
}



node* create(){
    node *head=NULL,*tail=NULL;
    int data;
    cin>>data;
    while(data!=-1){
    node *newNode=new node(data);
    if(head==NULL){
        head=tail=newNode;
    }
    tail->next=newNode;
    tail=newNode;
    
    cin>>data;
    }
    return head;
    }

    node* insert_ith(node *head,int i,int data){
        node *newNode=new node(data);
        int pos=i;
            if(i==0){
            newNode->next=head;
            return newNode;
        }
        node *temp=head;
        while(temp!=NULL){
            if(pos==1){
                newNode->next=temp->next;
                temp->next=newNode;
            }
            pos--;
            temp=temp->next;
        }
        cout<<"index not valid"<<endl;
        return head;
    }
    int main(){
        node *head1=create();
        print(head1);
        node *head2=insert_ith(head1,7,99);
        print(head2);
        return 0;
    }