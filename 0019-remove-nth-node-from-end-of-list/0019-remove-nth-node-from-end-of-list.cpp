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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return NULL;
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int cnt2 = 0;
        temp = head;
        
        if(n==1){
            while(temp->next->next){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            return head;
        }
        while(temp){
            cnt2++;
            if(cnt2 == cnt-n+1){
                temp->val = temp->next->val;
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};