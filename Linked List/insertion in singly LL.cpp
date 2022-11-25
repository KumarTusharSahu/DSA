#include <iostream>
using namespace std;

// creation of class node
class Node
{
public:
    int data;
    Node *next;

    // constructer
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// print LL
void print(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << "|";
        temp = temp->next;
    }
    cout << endl;
}
// creation of LL
Node *create()
{
    Node *head = NULL, *tail = NULL;
    int data, ch;
    cout << "Enter data to insert in linked list" << endl;
    cin >> data;
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = tail = newnode;
    }

    cout << "Do you want to insert more nodes press 1 to insert more press 0 to exit" << endl;
    cin >> ch;
    while (ch == 1)
    {
        cout << "Enter data to insert in linked list" << endl;
        cin >> data;
        Node *newnode = new Node(data);
        tail->next = newnode;
        tail = newnode;
        cout << "Do you want to insert more nodes press 1 to insert more press 0 to exit" << endl;
        cin >> ch;
    }
    return head;
}

// insert at last in LL
Node *insertLast(Node *head, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

// insert at first position
Node *insertFirst(Node *head, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    newnode->next = head;
    head = newnode;
    return head;
}

// insert after
Node *insertAfter(Node *head, int key, int data)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return head;
    }
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            Node *newnode = new Node(data);
            newnode->next = temp->next;
            temp->next = newnode;
            return head;
        }
        temp = temp->next;
    }
    cout << "Key not found" << endl;
}

// insert before
Node *insertBefore(Node *head, int key, int data)
{
    Node *temp = head, *prev = NULL;
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return head;
    }
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            Node *newnode = new Node(data);
            if (temp == head)
            {
                newnode->next = temp;
                head = newnode;
                return head;
            }
            prev->next = newnode;
            newnode->next = temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Key not found" << endl;
}

// insert at i_th position
Node *insert_ith(Node *head, int i, int data)
{
    int pos = i;
    Node *newnode = new Node(data);
    if (i == 0)
    {
        newnode->next = head;
        return newnode;
    }
    Node *temp=head;
    while (temp != NULL)
    {
        if (pos == 1)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            return head;
        }
        pos--;
        temp = temp->next;
    }
    cout << "index not valid" << endl;
    return head;
}


// driver function

int main()
{
    //-------------------------------------------------------------------------------

    // creation of multiple LL
    /*
        cout<<"Linked List 1"<<endl;
        Node *head1=create();
        print(head1);
        cout<<"Linked List 2"<<endl;
        Node *head2=create();
        print(head2);
    */
    //-------------------------------------------------------------------------------
    // insertion at last
    /*
        Node *head1 = create();
        print(head1);
        cout << "After inserting at last" << endl;
        head1 = insertLast(head1, 99);
        print(head1);
    */
    //-------------------------------------------------------------------------------
    // insertion at first

    /*
    Node *head1 = create();
    print(head1);
    cout << "After inserting at first" << endl;
    head1 = insertFirst(head1, 99);
    print(head1);
    */
    //-------------------------------------------------------------------------------
    // insert after
    /*
    Node *head1 = create();
      print(head1);
      cout << "Insert after" << endl;
      head1=insertAfter(head1, 10,99);
      print(head1);
  */
    //-------------------------------------------------------------------------------

    // insert before
    /*
    Node *head1 = create();
      print(head1);
      cout << "Insert before" << endl;
      head1=insertBefore(head1, 10,99);
      print(head1);
  */
    //-------------------------------------------------------------------------------

    // insert at i_th position

    Node *head1 = create();
      print(head1);
      cout << "Insert ith" << endl;
      head1=insert_ith(head1, 0,99);
      print(head1);

    return 0;
}
