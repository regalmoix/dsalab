#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printLinkedList(Node* headnode)
{
    Node* current = headnode;       //store headnode in a new current node iterator

    while (current != NULL)
    {
        cout << current -> data << endl;
        current = current -> next;
    }
}

Node* prependNodetoList(Node* headnode)
{
    Node* node = new Node();

    cout << "Enter data of node to put at the begining" << endl;
    cin >> node -> data;

    node -> next = headnode;
    headnode = node;

    return headnode;
}

Node* appendNodetoList(Node* tailnode)
{
    Node* node = new Node();

    cout << "Enter data of node to put at the ending" << endl;
    cin >> node -> data;
    node -> next = NULL;

    tailnode -> next = node;
    tailnode = node;

    return tailnode;
}

Node* insertNodeatIndex(int index, Node* headnode, Node* tailnode, int size)
{
    Node* iterator = headnode;

    for (int i = 0; i < index - 1; i++)
    {
        iterator = iterator -> next;
    }

    Node* node = new Node();

    cout << "Enter data of node to insert " << endl;
    cin >> node -> data;

    node -> next = iterator -> next;
    iterator -> next = node;

    return iterator;
}

void deleteNodeatIndex(int index, Node* headnode, Node* tailnode, int size)
{
    if (index != 0)
    {
        Node* iterator = headnode;

        for (int i = 0; i < index - 1; i++)
        {
            iterator = iterator -> next;
        }

        Node* temp = iterator->next;
        iterator-> next = (iterator -> next) -> next;

        delete(temp);
    }

    else
    {
        Node* iterator = headnode;
        headnode = headnode -> next;
        delete(headnode);
    }

}

int main()
{
    cout << "Hi enter the number of linked list nodes" << endl;
    int n;
    cin >> n;

    Node* head = NULL;
    Node* current = head;

    for (int i = 0; i < n; i++)
    {
        Node* temp = new Node();

        cout << "Enter data of Node #" << i << endl;

        cin >> temp -> data;
        temp -> next = NULL;

        if (i == 0)
        {
            head = temp;
            current = temp;
        }

        else
        {
            current -> next = temp;
            current = current -> next;
        }

    }

    Node* tail = current;

    cout << endl << "The elements of List are" << endl;
    printLinkedList(head);
    cout << endl;

/*
    head = prependNodetoList(head);
    n++;

    cout << endl << "The elements of List after prepending are" << endl;
    printLinkedList(head);
    cout << endl;


    tail = appendNodetoList(tail);
    n++;

    cout << endl << "The elements of List after apppending are" << endl;
    printLinkedList(head);
    cout << endl;


    cout << "Enter index to insert node at" << endl;
    int index;
    cin >> index;

    if (index == 0)
        head = prependNodetoList(head);

    else if (index == n - 1)
        tail = appendNodetoList(tail);

    else
        insertNodeatIndex(index, head, tail, n);

    n++;
    cout << endl << "The elements of List after insertion are" << endl;
    printLinkedList(head);
    cout << endl;
*/

    cout << "Enter index to remove node from" << endl;
    int index;
    cin >> index;

    deleteNodeatIndex(index, head, tail, n);
    n--;

    cout << endl << "The elements of List after deletion are" << endl;
    printLinkedList(head);
    cout << endl;




    return 0;
}
