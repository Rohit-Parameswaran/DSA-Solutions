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
    ListNode* getHalfHead(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode *head) {
        ListNode *prev = nullptr, *cur = head, *t = head;
        while(cur) {
            t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode *shead = getHalfHead(head);
        ListNode *rhead = reverseList(shead);

        ListNode *fhead = head, *temp = head;
        while(fhead && rhead) {
            temp = rhead->next;
            rhead->next = fhead->next;
            fhead->next = rhead;
            rhead = temp;
            fhead = fhead->next->next;
        }

        if(fhead) fhead->next = nullptr;
    }
};
