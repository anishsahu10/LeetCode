//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverseList(Node* head) {
        Node* curr = head;
        Node* last = NULL;
        while(curr != NULL){
            Node* front = curr->next;
            curr->next = last;
            last = curr;
            curr = front;
        }
        return last;
    }
    
    Node* addOne(Node *head) 
    {
        Node* newHead = reverseList(head);
        Node* temp = newHead;
        int carry = 1;

        while(temp && carry){
            int sum = temp->data + carry;
            carry = (sum)/10;
            temp->data = (sum)%10;
            temp = temp->next;
        }
        Node* newHead2 = reverseList(newHead);
        if(carry){
            Node* NNode = new Node(carry);
            NNode->next = newHead2;
            return NNode;
        }
    
        return newHead2;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends