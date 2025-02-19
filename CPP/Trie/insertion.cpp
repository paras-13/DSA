// Insertion in Trie
// To insert a string into a trie,
// we start from the root node and check if the current character is present in the children of the current node.
// If it is present, we move to the next node. If it is not present, we create a new node and add it to the children of the current node.
// We repeat this process until we reach the end of the string, and then mark the last node as the end of the string.

/*
Time Complexity:
- The time complexity for inserting a string of length L into the trie is O(L), where L is the length of the string.
- This is because we need to process each character of the string once.

Space Complexity:
- The space complexity is O(A*L), where A(26) is the size of the alphabet and L is the length of the string.
- In the worst case, we may need to create a new node for each character of the string.
*/

#include <iostream>
#include <vector>
using namespace std;
class TrieNode
{
public:
    TrieNode *children[26];
    bool isEndOfWord;
    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

void insert(TrieNode *root, string word)
{
    TrieNode *node = root;
    for (char ch : word)
    {
        int ind = ch - 'a';
        if (node->children[ind] == NULL)
            node->children[ind] = new TrieNode();
        node = node->children[ind];
    }
    node->isEndOfWord = true;
}
int main()
{
    int n;
    cout << "Enter number of strings to insert: ";
    cin >> n;
    vector<string> words(n);
    cout << "Enter strings to insert: ";
    for (int i = 0; i < n; i++)
        cin >> words[i];
    TrieNode *root = new TrieNode();
    for (string st : words)
        insert(root, st);
}