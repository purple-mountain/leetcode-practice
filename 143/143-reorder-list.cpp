#include <cstddef>
struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
  private:
    ListNode *reverse(ListNode *slow)
    {
        ListNode *prev = NULL;
        ListNode *c = slow;

        while (c != NULL)
        {
            ListNode *tmp = c->next;
            c->next = prev;
            prev = c;
            c = tmp;
        }

        return prev;
    }

    void merge(ListNode *first, ListNode *second)
    {
        while (first && second)
        {
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            second = tmp2;
            first = tmp1;
        }
    }

  public:
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *second = reverse(slow->next);

        slow->next = NULL;

        merge(head, second);
    }
};
