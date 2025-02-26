// Palindrome Partitioning, backtracking
// Time Complexity: O(n*2^n)
// Space Complexity: O(n)
// n -> length of the string

#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string &str)
{
    int i = 0;
    int j = str.length() - 1;
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}
void generate(string &str, int ind, vector<vector<string>> &res, vector<string> &vec)
{
    if (ind == str.size())
    {
        res.push_back(vec);
        return;
    }
    for (int i = ind; i < str.length(); i++)
    {
        string subStr = str.substr(ind, i - ind + 1);
        if (isPalindrome(subStr))
        {
            vec.push_back(subStr);
            generate(str, i + 1, res, vec);
            vec.pop_back();
        }
    }
}
vector<vector<string>> palindromePartioning(string str)
{
    vector<vector<string>> res;
    vector<string> vec;
    generate(str, 0, res, vec);
    return res;
}
int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    int n = str.size();
    vector<vector<string>> res = palindromePartioning(str);
    for (auto vec : res)
    {
        for (auto ele : vec)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}