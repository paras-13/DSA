// Z - algorithm
// Optimised O(n + m), string pattern matching algorithm

/*
Z-Algorithm for Pattern Matching

The Z-algorithm is an efficient string matching algorithm that preprocesses a string to find occurrences of a pattern within a text in linear time, O(n + m), where n is the length of the text and m is the length of the pattern.

Theory and Working:
-------------------
The Z-array for a string S of length L is an array Z of length L where Z[i] represents the length of the longest substring starting from S[i] that is also a prefix of S. In other words, Z[i] is the maximum number of characters starting from position i that match the prefix of S.

The Z-algorithm efficiently computes the Z-array in linear time by maintaining a window [L, R] which is the interval with maximum R such that S[L...R] is a prefix substring (matches the prefix of S).

Algorithm Steps:
1. Concatenate the pattern, a special character (not present in pattern or text), and the text to form a new string.
2. Compute the Z-array for this concatenated string.
3. Wherever the Z-value equals the length of the pattern, it indicates a match of the pattern in the text.

Example:
--------
Let pattern = "abc" and text = "abxabcabcaby".
Concatenate: "abc$abxabcabcaby"
Compute Z-array:
Index:  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
Char:   a  b  c  $  a  b  x  a  b  c  a  b  c  a  b  y
Z:      0  0  0  0  2  0  0  3  0  0  3  0  0  2  0  0

Here, Z[4]=2, Z[7]=3, Z[10]=3, which means the pattern "abc" occurs at positions 7 and 10 in the concatenated string, corresponding to positions 3 and 6 in the text.
Note: Z[4]=2 because only "ab" matches the prefix, not the full pattern. Z[13]=2 because "ab" matches the prefix, but not the full pattern.

Advantages:
-----------
- Linear time complexity.
- Useful for multiple pattern occurrences.
- Simple to implement and understand.

Implementation:
---------------
Below is the C++ implementation of the Z-algorithm for pattern searching.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute Z-array
vector<int> computeZArray(const string &s)
{
    int n = s.length();
    vector<int> Z(n, 0);
    int L = 0, R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= R)
            Z[i] = min(R - i + 1, Z[i - L]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            ++Z[i];
        if (i + Z[i] - 1 > R)
        {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

// Function to search pattern in text using Z-algorithm
void searchPattern(string &pattern, string &text)
{
    string concat = pattern + "$" + text;
    vector<int> Z = computeZArray(concat);
    int patLen = pattern.length();
    for (int i = patLen + 1; i < concat.length(); ++i)
    {
        if (Z[i] == patLen)
            cout << "Pattern found at index " << (i - patLen - 1) << endl;
    }
}

int main()
{
    string text = "abxabcabcaby";
    string pattern = "abc";
    searchPattern(pattern, text);
    return 0;
}
