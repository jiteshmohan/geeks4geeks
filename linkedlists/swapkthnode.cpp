// A C++ program to swap Kth node from beginning with kth node from end
#include <iostream>
#include <stdlib.h>
using namespace std;

// A Linked List node
struct node
{
    int data;
    struct node *next;
};

/* Utility function to insert a node at the beginning */
void push(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Utility function for displaying linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

/* Utility function for calculating length of linked list */
int countNodes(struct node *s)
{
    int count = 0;
    while (s != NULL)
    {
        count++;
        s = s->next;
    }
    return count;
}

/* Function for swapping kth nodes from both ends of linked list */
void swapKth(struct node **head, int k)
{
    if (k==0||*head==NULL||(*head)->next==NULL) return;
    int num=k-1, flag=1;
    node *kbeg=*head, *prev1=NULL, *kend=*head, *prev2=NULL, *temp=NULL;
    while(num>0 && kbeg!=NULL) {
        prev1=kbeg;
        kbeg=kbeg->next;
        num--;
    }
    if (kbeg==NULL) return;
    temp=kbeg->next;
    while(temp!=NULL) {
        temp=temp->next;
        prev2=kend;
        kend=kend->next;
    }
    if (kbeg==kend) return;
    if (kbeg==*head) {
    	*head=kend;
    	flag=0;
    } else prev1->next=kend;
    if (kend==*head && flag) *head=kbeg;
    else prev2->next=kbeg;
    
    temp=kbeg->next;
    kbeg->next=kend->next;
    kend->next=temp;
    return;
}

// Driver program to test above functions
int main()
{
    // Let us create the following linked list for testing
    // 1->2->3->4->5->6->7->8
    struct node *head = NULL;
    for (int i = 8; i >= 1; i--)
    push(&head, i);

    cout << "Original Linked List: ";
    printList(head);

    for (int k = 1; k < 10; k++)
    {
        swapKth(&head, k);
        cout << "\nModified List for k = " << k << endl;
        printList(head);
    }

    return 0;
}
