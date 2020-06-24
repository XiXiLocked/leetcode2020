// 25. Reverse Nodes in k-Group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * new_head = reverseX(head,1,k);
        return new_head != nullptr? new_head: head;
    }
    ListNode* reverseX(ListNode* head, int acc, int k)
    {
        if (head==nullptr)
        {
            return nullptr;
        }
        if (acc==k)
        {
            head->next = reverseX(head->next, 1,k);
            return head;
        }
        else // acc < k
        {
            if (head->next == nullptr)
            {
                return head;
            }
            else{
                ListNode *t = reverseX(head->next, acc+1,k);
                if (t==nullptr)
                {
                    return head;

                }
                else
                {
                ListNode * new_next =  t->next;
                t->next = head;
                head->next = new_next;
                return t;

                }

            }

        }

    }
};