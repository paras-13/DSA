#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(2^n);
void generate(vector<string>& pairs, int n, int open, int close, string str) {
    if(open == n && close == n) {
        pairs.push_back(str);
        return;
    }
    else {
        if(open <= n)
            generate(pairs, n, open+1, close, str+"(");
        if(close < open)
            generate(pairs, n, open, close+1, str+")");
    }
    return;
}
vector<string> generateParentheses(int n) {
    vector<string>parentheses;
    generate(parentheses, n, 1, 0, "(");
    return parentheses;
}
int main() {
    int n;
    cout << "Enter number of pairs to generate: ";
    cin >> n;
    vector<string>pairs = generateParentheses(n);
    for(string pair : pairs)
        cout << pair << " ";
    return 0;
}