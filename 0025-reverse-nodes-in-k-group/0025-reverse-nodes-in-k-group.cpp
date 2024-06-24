/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* last = NULL;
        while(curr != NULL){
            ListNode* front = curr->next;
            curr->next = last;
            last = curr;
            curr = front;
        }
        return last;
    }
    
    ListNode* findKNode(ListNode* temp, int k){
        k=k-1;
        while(temp && k){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;
        ListNode* kNode = NULL;
        while(temp){
            kNode = findKNode(temp,k);
            if(!kNode){
                if(prevNode) prevNode->next = temp;
                break;
            }
            nextNode = kNode->next;
            kNode->next = NULL;
            reverseList(temp);
            if(temp == head){
                head = kNode;
            }
            else prevNode->next = kNode;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};