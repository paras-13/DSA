// Robin Karp Algorithm
// String matching algorithm
// Robin karp algorithm maintains a hash value of the pattern which is needed to be searched in the text.
/*
    ? How it works ?
    *It matches the hash value of the pattern with hash value of the current substring in the text
    *If the hash values matches, then it compares the pattern with the current substring
    *If the hash values do not match, then it calculates the hash value of the next substring in the text

    * Drawback:- Spurious hits, hash collision
       # When hash value matches, but the pattern and the substring do not match
    * To avoid spurious hits, we have to use a strong hash function
        It uses polynomial rolling hash function to calculate the hash value of the pattern and the substring in the text

    ? Polynomial Rolling Hash Function ?
    * it use multiplication and addition to calculate the hash value for the string
    * it allows us to update the hash value for a new substring by efficiently removing the
        * contribution of first character and adding the contribution of the new character.

    ? Mathematical implementation of hash function ?
    ! hash(s) = s[0] + s[1]*p + s[2]*p^2 + s[3]*p^3 + ... + s[n-1]*p^(n-1)
    ! new hash(s) = (d * (old hash - t[i]*d^m-1) + t[i+m])%q;

    / Now lets implement the robin karp algorithm
    / Implementation of hash function is slightly different from the above mentioned hash function
    *
*/

// Robin Karp Algorithm
// Time Complexity:- O(n+m)
// Worst case:- O(n*m) => reason:- multiple hash collisions
#include <iostream>
#include <vector>
using namespace std;

vector<int> rabinKarp(string text, string pattern)
{
    int n = text.size();    // Size of text
    int m = pattern.size(); // Size of pattern
    int q = INT_MAX;        // q is taken as big as possible to avoid the collison
    int d = 256;            // d is the base for hash functions, here it is taken 256 which is the number of characters in the ASCII table
    int h = 1;
    int p = 0; // pattern hash
    int t = 0; // text hash
    vector<int> res;

    // First lets calculate h
    // h value will be (d^m-1)%q;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Now calculating hash value of pattern and text, upto window of pattern
    for (int i = 0; i < m; i++)
    {
        p = ((d * p) + pattern[i]) % q;
        t = ((d * t) + text[i]) % q;
    }

    // Lets slide the pattern over the text
    for (int i = 0; i <= n - m; i++)
    {

        // if hash values of p and t matches, we will check the characters
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (pattern[j] != text[i + j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.push_back(i);
        }
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
    return res;
}
int main()
{
    string text, pattern;
    cout << "Enter text string: ";
    cin >> text;
    cout << "Enter pattern string ";
    cin >> pattern;
    vector<int> res = rabinKarp(text, pattern);
    if (res.empty())
        cout << "Pattern not found in the text";
    else
    {
        cout << "Pattern found at index: ";
        for (int it : res)
            cout << it << " ";
    }
    return 0;
}
