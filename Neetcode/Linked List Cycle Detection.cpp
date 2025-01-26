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
    bool hasCycle(ListNode* head) {
        ListNode* slow=head, *fast = head;
        while(true) {
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            else
                fast = fast->next;
            if(!slow || !fast)
                break;
            else if(slow == fast)
                return true;
        }
        return false;
    }
};
