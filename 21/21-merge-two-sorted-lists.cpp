#include <cstddef>

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL && list2 == NULL)
        {
            return NULL;
        }

        if (list1 == NULL)
        {
            return list2;
        }

        if (list2 == NULL)
        {
            return list1;
        }

        ListNode *ans = new ListNode();
        ListNode *head = ans;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val >= list2->val)
            {
                ans->next = list2;
                list2 = list2->next;
            }
            else
            {
                ans->next = list1;
                list1 = list1->next;
            }

            ans = ans->next;
        }

        ans->next = list2 ? list2 : list1 ? list1 : nullptr;

        return head->next;
    }
};
