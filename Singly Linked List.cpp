#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define ull unsigned long long int

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data" << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    // Create New Node
    Node *temp = new Node(d);

    temp->next = head; // pointing new nodes pointer to head
    head = temp;       // making the new node head
}

void insertAtTail(Node *&tail, int d)
{
    // created a new node
    Node *temp = new Node(d);
    tail->next = temp; // tails next location points to temp
    tail = temp;       // tail points to last node which is temp
}

void insertAtIndex(Node *&head, Node *&tail, int index, int d)
{
    Node *temp = head; // temporary variable for traversing
    int cnt = 1;

    // Inserting at 1st position
    if (index == 1) // for adding to head and updating the value of head
    {
        insertAtHead(head, d);
        return;
    }

    while (cnt < index - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last position
    if (temp->next == NULL) // if the position becomes tail we are uopdating the tail
    {
        insertAtTail(tail, d);
        return;
    }
    // inserting in index
    Node *nodeToInsert = new Node(d); // Creating the node that we will insert
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// deleting a node
void deleteNode(int index, Node *&head)
{
    // deleting first node
    if (index == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }
    // deleting any other node
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt <= index)
        {
            prev = curr;
            curr = curr->next; // Traversing to the position needed
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&head)
{
    // Creating a temp var for traversing
    Node *temp = head; // pointing temp to head
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Created a new node
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;

    // Inserting at head
    cout << "Inserting at head" << endl;
    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 100);
    print(head);

    // Inserting at tail
    cout << "Inserting at tail" << endl;
    insertAtTail(tail, 99); // We have to pass tail as tail willbe the last node
    insertAtTail(tail, 88);

    print(head);

    cout << "Inserting in Index 3" << endl;
    insertAtIndex(head, tail, 6, 69);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    // deleteing Node
    deleteNode(3, head);
    print(head);
    return 0;
}