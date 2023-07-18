//Aidan Castillo
//CPSC-335
//7.17.21
//Using HeapSort/MinHeap to organize multiple merged LinkedLists
 
#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node* next;
};//end Node
 
//Creating our nodes for sorting
struct Node* newNode(int data)
{
    // Allocate node
    struct Node* new_node = new Node();
 
    //Entering Node Data
    new_node->data = data;
    new_node->next = NULL;
 
    return new_node;
}//end Node Creation
 
struct compare
{
    bool operator()(
         struct Node* a, struct Node* b)
    {
        return a->data > b->data;
    }
};//End Compare
 
// Function to merge k sorted linked lists
struct Node* mergeKSortedLists(
             struct Node* arr[], int K)
{
    // Priority_queue 'pq' implemented
    // as min heap with the help of
    // 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;
 
    // Push the head nodes of all
    // the k lists in 'pq'
    for (int i = 0; i < K; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);
     
      // Handles the case when k = 0
      // or lists have no elements in them   
      if (pq.empty())
        return NULL;
   
      struct Node *dummy = newNode(0);
      struct Node *last = dummy;
   
    // Loop till 'pq' is not empty
    while (!pq.empty()) 
    {
        // Get the top element of 'pq'
        struct Node* curr = pq.top();
        pq.pop();
 
        // Add top element to merged list
        last->next = curr;
        last = last->next; 
       
        // Check if there for node following head node
        if (curr->next != NULL)
             
        pq.push(curr->next);
    }
 
    // Head node
    return dummy->next;
}//End Merging
 
// Function to print the singly
// linked list
void printList(struct Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
 
int main()
{
    // Number of linked lists
    int N = 4;

 
    // Pointers array pointing to head of each list
    Node* arr[N];
 
    //Create our LinkedLists
    arr[0] = newNode(2);
    arr[0]->next = newNode(5);
    arr[0]->next->next = newNode(9);
    arr[0]->next->next->next = newNode(21);
 
    arr[1] = newNode(-1);
    arr[1]->next = newNode(0);
    arr[1]->next->next = newNode(2);
    //arr[1]->next->next->next = newNode();
 
    arr[2] = newNode(-10);
    arr[2]->next = newNode(81);
    arr[2]->next->next = newNode(121);
    //arr[2]->next->next->next = newNode();

    arr[3] = newNode(4);
    arr[3]->next = newNode(6);
    arr[3]->next->next = newNode(12);
    arr[3]->next->next->next = newNode(20);
    arr[3]->next->next->next->next = newNode(150);

 
    struct Node* head = mergeKSortedLists(arr, N);
 
    // Print the merged list
    printList(head);
 
    return 0;
}//end main
