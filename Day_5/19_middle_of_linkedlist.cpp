#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;

    Node *next;

    Node(int data1, Node *next1)
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
    // 1st approach
    // T.C. - O(N) + O(N/2)
    // S.C. - O(1)
    Node *bruteForce(Node *head)
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        int midNode = (count / 2);
        temp = head;
        for (int i = 0; i < midNode; i++)
        {
            temp = temp->next;
        }

        return temp;
    }
    // 2nd approach
    // T.C. - O(N)
    // S.C. - O(1)
    Node *optimal(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        // fast != null && fast->next != null
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution s;
    head = s.bruteForce(head);
    head = s.optimal(head);

    printLinkedlist(head);

    return 0;
}