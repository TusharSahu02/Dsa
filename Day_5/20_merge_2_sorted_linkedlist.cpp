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
    // T.C.- O(N+M)+O(log(N+M))
    // S.C.- O(N+M)
    Node *bruteForce(Node *head1, Node *head2)
    {
        // 2 temp for both list head
        Node *temp1 = head1;
        Node *temp2 = head2;

        // take a array/vector to store all the values
        vector<int> v;
        // insert all the list1 values
        while (temp1 != nullptr)
        {
            v.push_back(temp1->data);
            temp1 = temp1->next;
        }

        // insert all the list2 values
        while (temp2 != nullptr)
        {
            v.push_back(temp2->data);
            temp2 = temp2->next;
        }

        // sort the vector
        sort(v.begin(), v.end());

        // after sorting create a new list
        Node *result = new Node(-1);

        // temp is to store the new head
        Node *temp = result;
        // iterate in the list the and add the values into linkedlist back
        for (int i = 0; i < v.size(); i++)
        {
            result->next = new Node(v[i]);
            result = result->next;
        }
        temp = temp->next;

        // return the new head
        return temp;
    }

    // 2nd approach
    // T.C. - O(N+M)
    // S.C. - O(1)
    Node *optimal(Node *head1, Node *head2)
    {
        // using the concept of dummy node.

        // assign t1 and t2 to the head of both list
        Node *t1 = head1;
        Node *t2 = head2;
        // create a new node (Dnode) pointing initial to null
        Node *dNode = new Node(-1);

        // temp to traverse in dNode
        Node *temp = dNode;

        // traversing a loop till any of the list reaches to the null
        while (t1 != nullptr && t2 != nullptr)
        {
            // if the data from 1st list element is small
            if (t1->data < t2->data)
            {
                // simply point the dNode's next to that element
                temp->next = t1;
                // move the temp to 1st list head(temp1)
                temp = t1;
                // and move forword that (temp1) to it's next
                t1 = t1->next;
            }
            else
            {
                // same for this if the 2nd list element is small
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        // if there is any element left in the list
        if (t1)
        {
            // simply point the next to that element
            temp->next = t1;
            // coz as it's already sorted so we need not to travers and check
            // only point to that node and return
        }
        else
        {
            temp->next = t2;
        }

        // return the dummies node next
        // coz 1st element in dNode is -1 after that we have the original elements
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
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    // 2nd list - [6,7,8,9,10]
    Node *head2 = new Node(6);
    head2->next = new Node(7);
    head2->next->next = new Node(8);
    head2->next->next->next = new Node(9);
    head2->next->next->next->next = new Node(10);

    Solution s;
    // Node *head3 = s.bruteForce(head1, head2);
    Node *head3 = s.optimal(head1, head2);

    printLinkedlist(head3);
    // printLinkedlist(head2);
    return 0;
}