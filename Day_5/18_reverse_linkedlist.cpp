#include <bits/stdc++.h>
using namespace std;

// class to create node
class Node
{
public:
    // data stored in the node
    int data;

    // pointer to the next node in the list
    Node *next;

    // constructer with data and next
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // constructer with data only.
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// 1st approach
// T.C -O(2N)
// S.C -O(N)
Node *bruteForce(Node *head)
{
    // store the head into temp
    // will never do anything with original head, always create temp and assign to it
    Node *temp = head;
    // create a stack to push all the data into it.
    stack<int> s;

    // iterating till temp not equal to null
    // pushing all the values.
    while (temp != nullptr)
    {
        s.push(temp->data);
        temp = temp->next;
    }

    // reassign temp with head
    temp = head;
    // and iterate again into list and this time
    while (temp != nullptr)
    {
        // manipulate the data with the stack data, which will help us in reversing the list
        temp->data = s.top();
        // as stack follows <LIFO> property so last will be 1st
        s.pop();

        temp = temp->next;
    }
    // simply return the head.
    return head;
}

// 2nd approach
// T.C. - O(N)
// S.C. - O(1)
// did using iterative method
Node *optimal1(Node *head)
{

    Node *temp = head;
    Node *prev = nullptr;
    Node *front;
    // iterate till temp != null
    while (temp != nullptr)
    {
        // assign front to temp's next
        front = temp->next;
        // and break the link of next's value and point it to prev
        temp->next = prev;
        // now increment the prev
        prev = temp;
        // and temp
        temp = front;
    }

    // and the end prev will be our new head
    return prev;
}
// 3rd approach
// T.C. - O(N)
// S.C. - O(1)
Node *optimal2(Node *head)
{

    // base case
    if (head->next == nullptr || head == nullptr)
    {
        return head;
    }

    Node *newHead = optimal2(head->next);

    Node *front = head->next;

    front->next = head;

    head->next = nullptr;

    return newHead;
}

// this is to print linkedlist
void printLinkedlist(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // creating a linkedlist of vales [1] -> [2] -> [3] -> [4] -> null
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // 1st approach
    // head = bruteForce(head);

    // 2nd approach
    // iterative method
    // head = optimal1(head);

    // 3rd approach
    // recursive method
    head = optimal2(head);

    // print linkedlist
    printLinkedlist(head);

    return 0;
}