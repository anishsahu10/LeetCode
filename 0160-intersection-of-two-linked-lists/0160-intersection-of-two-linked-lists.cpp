/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* collisionPt(ListNode* smol, ListNode* large, int d){
        while(d){
            large = large->next;
            d--;
        }
        while(smol != large){
            smol = smol->next;
            large = large->next;
        }
        return smol;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int cnt1 = 0, cnt2 = 0;
        while(t1){
            cnt1++;
            t1 = t1->next;
        }
        while(t2){
            cnt2++;
            t2 = t2->next;
        }
        
        if(cnt1 < cnt2) return collisionPt(headA, headB, cnt2 - cnt1);
        else return collisionPt(headB, headA, cnt1 - cnt2);
    }
};