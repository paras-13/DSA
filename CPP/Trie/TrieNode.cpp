// Representation of Trie Node
// Trie consist of nodes connected by edges
// Each node represents a character or a part of a string
// Each node contains an array of pointers to its children
// Each node contains a boolean variable to indicate the end of a string

// Structure of Trie Node
#include <iostream>
class TrieNode
{
public:
    // pointer array for child nodes of each node
    TrieNode *children[26]; // 26 characters in English alphabet

    // boolean variable to indicate the end of a string
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};