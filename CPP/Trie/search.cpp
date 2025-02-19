// Search in Trie
/*
 * Searching in Trie
 * Start from the root node.
 * For each character in the string, check if the character exists as a child node.
 * If it does not exist, the word is not present in the Trie.
 * Move to the child node and repeat the process for the next character.
 * After checking all characters, if the last node is marked as the end of the word, the word is present in the Trie.
 */
// Time: O(L), where L is the length of the string
// Space: O(1)
#include <iostream>
#include <string>
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

bool search(TrieNode *root, string word)
{
    TrieNode *node = root;
    for (char ch : word)
    {
        int ind = ch - 'a';
        if (node->children[ind] == NULL)
            return false;
        node = node->children[ind];
    }
    return node->isEndOfWord;
}
int main()
{
    // As we implemented insertion code in previous snippet, let just append the same code to create trie
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

    // Now lets implement search function
    string word;
    cout << "Enter the word you want to search: ";
    cin >> word;
    bool response = search(root, word);
    if (response)
        cout << "Word found in Trie";
    else
        cout << "Word not found in Trie";
}