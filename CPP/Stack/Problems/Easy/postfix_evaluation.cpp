// Ques = To evaluate postfix expression using stack
/*
    Expression of the form “a b operator”
    Time Complexity: O(N) 
    Auxiliary Space: O(N)
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluate(string str)
{
    stack<int> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
            st.push(str[i] - '0');
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (str[i])
            {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break; 
            }
        }
    }
    return st.top();
}
int main()
{
    string str;
    cout << "Enter a postfix expression: ";
    cin >> str;
    cout << "Result: " << evaluate(str);
}