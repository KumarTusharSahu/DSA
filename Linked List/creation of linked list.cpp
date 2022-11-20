
#include<iostream>
using namespace std;

//creation of class node
class node{
    public:
    int data;
    node *next;

    node(){
        next=NULL;
    }
};

//print function to print LL
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
 node *head;
 node *temp,*last;

 //Creation of node
void create(){
    int data;
    temp=new node;
    cout<<"enter data of node : ";
    cin>>data;
    temp->data=data;
    if(head==NULL){
        head=last=temp;
    }
    else{
        last->next=temp;
        last=temp;
    }
    cout<<"node created successfully"<<endl;
}

//insertion of new nodes in existing LL
void insert(){
    char ch;
    cout<<"press 'y' to insert new node  press 'p' to print press any key to return: "<<endl;
    cin>>ch;
    while(1){
        switch(ch){
            case 'y':
        create();
        break;
        case 'p':print(head);
        break;
        default:exit(0);
        }
        cout<<"press 'y' to insert new node  press 'p' to print press any key to return: "<<endl;
    cin>>ch;

}
}

int main(){
    insert();
    print(head);
    return 0;
}
