#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *next;
    int data;

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
    // T.C. - O(N) + O(N-M)
    // S.C. - O(1)
    Node *bruteForce(Node *head, int N)
    {
        if (head == nullptr)
        {
            return NULL;
        }

        Node *temp = head;
        int count = 0;
        Node *newHead;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        if (count == N)
        {
            newHead = head->next;
            delete (head);
            return newHead;
        }
        int res = count - N;
        temp = head;

        while (temp != nullptr)
        {
            res--;
            if (res == 0)
            {
                break;
            }
            temp = temp->next;
        }

        Node *delNode = temp->next;
        temp->next = temp->next->next;
        delete (delNode);

        return head;
    }

    // 2nd approach
    Node *optimal(Node *head, int N)
    {
        // take 1 node to iterate in list slow and fast.
        Node *fast = head;
        Node *slow = head;

        // iterate till the N provided and place fast pointer there
        for (int i = 0; i < N; i++)
        {
            fast = fast->next;
        }

        // this is for if the Nth node is head
        if (fast == nullptr)
        {
            return head->next;
        }

        // traverse till fast ka next Null nai ho jata
        while (fast->next != nullptr)
        {
            // and iterate them accordingly
            fast = fast->next;
            slow = slow->next;
        }
        // delNode is to store that particular elem that needs to be deleted
        Node *delNode = slow->next;
        // chnage the link of that node to it's next node
        slow->next = slow->next->next;
        // and free that node
        delete (delNode);

        // return the new list
        return head;
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
    head->next->next->next->next->next = new Node(6);

    int N = 3;
    Solution s;
    // head = s.bruteForce(head, N);
    head = s.optimal(head, N);
    printLinkedlist(head);
    return 0;
}