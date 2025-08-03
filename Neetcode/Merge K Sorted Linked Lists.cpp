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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(auto list: lists) pq.push({list->val, list});
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while(!pq.empty()) {
            auto curNode = (pq.top()).second;
            pq.pop();
            tail->next = curNode;
            tail = tail->next;
            if(curNode->next) pq.push({(curNode->next)->val, curNode->next});
        }
        return head->next;
    }
};
