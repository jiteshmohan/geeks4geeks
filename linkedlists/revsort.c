/* Given two sorted non-empty linked lists. Merge them in
such a way that the result list will be in reverse
order. Reversing of linked list is not allowed. Also,
extra space should be O(1) */
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int key;
    struct Node* next;
};

Node* return_smallest(Node **aref, Node **bref) {
    if (*aref==NULL && *bref==NULL) return NULL;
    else if ((*aref==NULL)||((*bref!=NULL)&&((*bref)->key<=(*aref)->key))) {
        Node *temp=*bref;
        *bref=(*bref)->next;
        return temp;
    } else if ((*bref==NULL)||((*aref!=NULL)&&((*aref)->key<=(*bref)->key))) {
        Node *temp=*aref;
        *aref=(*aref)->next;
        return temp;
    }
    return NULL;
}

// Given two non-empty linked lists 'a' and 'b'
Node* SortedMerge(Node *a, Node *b)
{
    Node *ahead=a, *bhead=b, *result=NULL, *currsmallest=NULL;
    do {
        currsmallest=return_smallest(&ahead, &bhead);
        if(currsmallest!=NULL) {
            currsmallest->next=result;
            result=currsmallest;
        }
    } while(currsmallest!=NULL);
    return result;
}

/* Function to print Nodes in a given linked list */
void printList(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->key << " ";
        Node = Node->next;
    }
}

/* Utility function to create a new node with
given key */
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}

/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* res = NULL;

    /* Let us create two sorted linked lists to test
    the above functions. Created lists shall be
        a: 5->10->15
        b: 2->3->20 */
    Node *a = newNode(1);
    a->next = newNode(1);
    a->next->next = newNode(1);

    Node *b = newNode(1);
    b->next = newNode(1);
    b->next->next = newNode(1);

    cout << "List A before merge: \n";
    printList(a);

    cout << "\nList B before merge: \n";
    printList(b);

    /* merge 2 increasing order LLs in descresing order */
    res = SortedMerge(a, b);

    cout << "\nMerged Linked List is: \n";
    printList(res);

    return 0;
}