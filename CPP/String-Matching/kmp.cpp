// KMP algo -> Knuth-Morris-Pratt Algorithm
// LPS = Longest Prefix Suffix
/*
    LPS array contains the longest proper prefix and suffix of the pattern.
    * Construction of LPS array
    / lps[0] = 0 as string of length 1 has no proper prefix and suffix
    / As we traverse the pattern, we compare the current index i, with the character at index len.

    * It mainly has three cases
    * Case 1: If pattern[i] == pattern[len], then lps[i] = len+1, len++, i++
    * Case 2: If pattern[i] != pattern[len] and len == 0, then lps[i] = 0, i++
    * Case 3: If pattern[i] != pattern[len] and len != 0, then len = lps[len-1]
*/
/*
    https://leetcode.com/problems/longest-happy-prefix/description/
    https://leetcode.com/problems/shortest-palindrome/description/
    https://leetcode.com/problems/repeated-substring-pattern/description/
    https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
    https://www.geeksforgeeks.org/problems/search-pattern0205/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
    https://leetcode.com/problems/rotate-string/editorial/
*/
#include <iostream>
#include <vector>
using namespace std;
void createLps(string pattern, vector<int> &lps)
{
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < pattern.length())
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector<int> solve(string text, string pattern)
{
    int m = pattern.length();
    vector<int> lps(m);
    vector<int> res;
    createLps(pattern, lps);
    int j = 0;
    int i = 0;
    while (i < text.length())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
            if (j == m)
            {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string text, pattern;
        cin >> text;
        cin >> pattern;
        vector<int> res = solve(text, pattern);
        if (res.empty())
        {
            cout << "Not Found\n\n";
            continue;
        }
        cout << res.size() << endl;
        for (int it : res)
            cout << it + 1 << " ";
        cout << "\n\n";
    }
}
