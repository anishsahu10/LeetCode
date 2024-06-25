//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* middleNode(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while(list1 && list2){
            if(list1->data < list2->data){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;   
            }
            temp = temp->next;
        }
        if(list1){
            temp->next = list1;
        }
        if(list2){
            temp->next = list2;
        }
        return dummy->next;
    }
    
    Node* mergeSort(Node* head) {
        if(head == NULL || head->next == NULL) return head;
        Node* middle = middleNode(head);
        Node* lNode = head;
        Node* rNode = middle->next;
        middle->next = NULL;
        lNode = mergeSort(lNode);
        rNode = mergeSort(rNode);
        return mergeTwoLists(lNode, rNode);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends