/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *l = head, *m = head, *r = head;
        while (r && r->next) {
            r = r->next->next;
            m = l;
            l = l->next;
        }
        m->next = nullptr;
        return merge(sortList(head), sortList(l));
    }
    //归并排序
    ListNode* merge(ListNode* n1, ListNode* n2) {
        if (!n1) return n2;
        if (!n2) return n1;
        if (n1->val <= n2->val) {
            n1->next = merge(n1->next, n2);
            return n1;
        } else {
            n2->next = merge(n2->next, n1);
            return n2;
        }
    }
};