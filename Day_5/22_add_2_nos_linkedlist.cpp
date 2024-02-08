#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(Node *next1, int data1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
class Solution
{
public:
    // T.C-O(max(m,n))
    // S.C-O(max(m,n))
    Node *bruteForce(Node *head1, Node *head2)
    {
        Node *t1 = head1;
        Node *t2 = head2;

        Node *dNode = new Node(-1);
        Node *temp = dNode;

        int carry = 0;

        while (t1 != nullptr || t2 != nullptr || carry)
        {
            int sum = 0;
            if (t1 != nullptr)
            {
                sum += t1->data;
                t1 = t1->next;
            }
            if (t2 != nullptr)
            {
                sum += t2->data;
                t2 = t2->next;
            }

            sum += carry;
            carry = sum / 10;
            Node *node = new Node(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return dNode->next;
    }
};

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
    // 1st list - [1,2,3,4,5]
    Node *head1 = new Node(3);
    head1->next = new Node(5);
    // head1->next->next = new Node(3);

    // 2nd list - [6,7,8,9,10]
    Node *head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = new Node(9);
    head2->next->next->next = new Node(9);

    Solution s;
    Node *head3 = s.bruteForce(head1, head2);
    // Node *head3 = s.optimal(head1, head2);

    printLinkedlist(head3);
    // printLinkedlist(head2);
    return 0;
}