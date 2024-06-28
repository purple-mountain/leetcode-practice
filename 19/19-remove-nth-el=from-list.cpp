struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode *node = head;
        int l = 1;
        while (node->next)
        {
            node = node->next;
            l++;
        }

        if (l == 1)
        {
            return nullptr;
        }

        if (l - n == 0)
        {
            return head->next;
        }

        node = head;
        for (int i = 0; i < l - n - 1; i++)
        {
            node = node->next;
        }

        node->next = node->next->next;

        return head;
    }
};
