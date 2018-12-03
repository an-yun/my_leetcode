#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        int largest = 0;
        for (auto c:s)
        {
            if (c == '(')
                st.push(1);
            else if (!st.empty())
            {
                int push_value = 1;
                if (!st.empty() && st.top() != 1)
                {
                    push_value += st.top();
                    st.pop();
                }
                if (!st.empty())
                {
                    st.pop();
                    push_value += 1;
                    if(!st.empty() && st.top() != 1)
                    {
                        push_value += st.top();
                        st.pop();
                    }
                    largest = max(largest, push_value);
                    st.push(push_value);
                }
            }
        }
        return largest;
    }
};

int main()
{
    Solution s;
    cout << s.longestValidParentheses("(()()())(()(()())())") << endl;
    return 0;
}
