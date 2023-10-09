// Valid Parenthesis: 
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string str)
{
    stack <int> st;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            st.push(str[i]);
        else
        {
            if(st.empty()) return false;
            else if(str[i] == ')')
            {
                if(st.top() == '(') st.pop();
                else return false;
            }
            else if(str[i] == '}')
            {
                if(st.top() == '{') st.pop();
                else return false;
            }
            else if(str[i] == ']')
            {
                if(st.top() == '[') st.pop();
                else return false;
            }

        }
    }
    if(st.empty()) return true;
    else return false;
}
int main()
{
    string str;
    cout << "Enter: "; cin >> str;
    int res = isValid(str);
    if(res) cout << "Valid\n";
    else cout << "Invalid\n";
}
