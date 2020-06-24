// 24. Swap Nodes in Pairs
// 懒了递归, 感觉链表题都偏简单?
//
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        ListNode * ret = head->next;
        ListNode * t = head->next->next;
        ret->next = head;
        head->next = swapPairs(t);
        return ret;
    }
};