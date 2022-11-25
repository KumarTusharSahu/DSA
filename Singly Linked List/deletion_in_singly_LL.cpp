#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
node *head, *tail;
// print LL
void print()
{
    node *temp = head;
    if (head == NULL)
        cout << "list is empty" << endl;
    while (temp != NULL)
    {
        cout << "->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
}
// creation of Singly LL
void create()
{
    cout << "Enter data in LL" << endl;
    int data;
    cin >> data;
    // add members in linked list until user enters -1
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        cin >> data;
    }
    return;
}
// delete first element
void delete_first()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        head = tail = NULL;
        return;
    }
    node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}
// delete at last
void delete_last()
{
    node *temp = head, *prev = NULL;
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        head = tail = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    tail = prev;
    delete temp;
}

// delete after
void delete_after(int key)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "Delete after not possible" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp == tail)
            {
                cout << "Delete after not possible" << endl;
            }
            if (temp->next == tail)
            {
                temp->next = NULL;
                tail = temp;
                return;
            }
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
    cout << "Key not found" << endl;
}

// delete before
void delete_before(int key)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "Delete before not possible" << endl;
        return;
    }
    node *temp = head, *prev1 = NULL, *prev2 = NULL;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (prev2 == NULL)
            {
                head = head->next;
                delete prev1;
                return;
            }
            prev2->next = temp;
            prev1->next = NULL;
            delete prev1;
            return;
        }
        prev2 = prev1;
        prev1 = temp;
        temp = temp->next;
    }
    cout << "Key not found" << endl;
}

void delete_ith(int i)
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    int pos = i;
    if (i == 1)
    {
        head = head->next;
        return;
    }
    node *temp = head, *prev = NULL;
    while (temp != NULL)
    {
        if (pos == 1)
        {
            if (temp == tail)
            {
                tail = prev;
            }
            prev->next = temp->next;
            delete temp;
            return;
        }
        pos--;
        prev = temp;
        temp = temp->next;
    }
    cout << "invalid index" << endl;
}

// Driver Code
int main()
{
    create();
    print();
//-------------------------------------------------------------------------------
    /*
    cout << "Delete at beginning" << endl;
    delete_first();
    print();
    */
//-------------------------------------------------------------------------------
    /*
    cout << "Delete at last" << endl;
        delete_last();
        print();
        */
//-------------------------------------------------------------------------------
    /*
    cout << "Delete after" << endl;
    delete_after(20);
    print();
    */
//-------------------------------------------------------------------------------
    /*
    cout << "Delete before" << endl;
    delete_before(40);
    print();
    */
//-------------------------------------------------------------------------------
    cout << "Delete ith" << endl;
    delete_ith(3);
    print();
//-------------------------------------------------------------------------------
    return 0;
}