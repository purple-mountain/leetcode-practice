struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
  public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return head;
        }

        ListNode *node = head->next;
        ListNode *prev_node = head;

        while (node)
        {
            ListNode *tmp = node->next;
            node->next = prev_node;
            prev_node = node;
            node = tmp;
        }

        head->next = nullptr;

        return prev_node;
    }
};
