#include <stack>

using namespace std;

class MinStack
{
    stack<int> st;
    stack<int> min_num_stack;

  public:
    void push(int val)
    {
        st.push(val);
        if (min_num_stack.empty())
        {
            min_num_stack.push(val);
        }
        else
        {
            min_num_stack.push(min(min_num_stack.top(), val));
        }
    }

    void pop()
    {
        st.pop();
        min_num_stack.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return this->min_num_stack.top();
    }
};
