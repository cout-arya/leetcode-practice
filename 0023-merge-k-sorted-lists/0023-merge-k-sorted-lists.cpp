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
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* curr = lists[i];
            while (curr != nullptr) {
                pq.push(curr->val);
                curr = curr->next;
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while (!pq.empty()) {
            tail->next = new ListNode(pq.top());
            tail = tail->next;
            pq.pop();
        }
        return dummy->next;
    }
};