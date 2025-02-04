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
        ListNode* dhead = new ListNode(-1, head);
        ListNode *tail = dhead, *offset = dhead;
        int k = n;
        while(k--) tail = tail->next;
        
        while(tail->next) {
            tail = tail->next;
            offset = offset->next;
        }
        if(offset == dhead) head = head->next;
        offset->next = offset->next->next;
        return head;
    }
};
