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
    
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* start = head;
        ListNode* last = newHead;
        while(last){
            if(start->val != last->val) return false;
            start = start->next;
            last = last->next;
        }
        return true;
    }
};