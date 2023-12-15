/*
    Infix: Expression of the form "a operator b" (a + b).
    Postfix: Expression of the form "a b operator" (ab +).

    Need - Humans can understand infix expression easily but computers can't;
           computer can evaluate postfix expression easily.

    ** Hence STACK DATA STRUCTURE is used to convert this expression.

    Time complexity: O(n)
    Space: O(n)
*/

// Code-->
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int prec(char opr)
{
    if(opr=='^') return 3;
    else if(opr=='*' || opr=='/') return 2;
    else if(opr=='+' || opr=='-') return 1;
    else return -1;
}
void infix_to_postfix(string exp)
{
    string postfix;
    stack <char> st;
    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z' || exp[i]>='0' && exp[i]<='9') postfix.push_back(exp[i]);
        else if(exp[i]=='(') st.push(exp[i]);
        else if(exp[i]==')')
        {
            while(st.top()!='(')
            {
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && prec(exp[i]) <= prec(st.top()))
            {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while(!st.empty())
    {
        postfix.push_back(st.top());
        st.pop();
    }
    cout << "Prefix expression: " << postfix << endl;
}
int main()
{
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    cout << "Infix expression: " << infix << endl;
    infix_to_postfix(infix);
}