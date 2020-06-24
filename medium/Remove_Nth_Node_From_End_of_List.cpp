// 19. Remove Nth Node From End of List
// 思路, 2pass 数数
// 这题应该放到easy吧,试了下数据然后一次ac

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
        int len = 0;
        ListNode* t = head;
        while(t!= nullptr)
        {
            t = t->next;
            len++;
        }
        if (len==n)
        {
            return head->next;
        }
        t = head;
        for (int i = len-n;i>1;--i)
        {
            t = t->next;
        }
        t->next = t->next->next;
        return head;
        
    }
};