// Implementacao da trie copiada de https://www.geeksforgeeks.org/trie-insert-and-search/

// C++ implementation of search and insert
// operations on Trie
#include <iostream>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 27;

// trie node
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl->isEndOfWord);
}

int countKeystrokes(struct TrieNode *root, string key) {
    int count = 1;
    struct TrieNode *pCrawl = root;

    pCrawl = pCrawl->children[key[0] - 'a']; // pula primeira letra ja que sempre devemos digitar

    for (int i=1; i<key.length(); i++) {
        int index = key[i] - 'a';
        for (int j=0; j<ALPHABET_SIZE; j++) {
            if ((j != index && pCrawl->children[j]) || pCrawl->isEndOfWord){ // eh uma bifurcacao
                count++;
                break;
            }
        }
        pCrawl = pCrawl->children[index];
    }

    return count;
}

// Driver
int main()
{
    int N;
    while (cin >> N) {
        vector<string> v;

        for (int i=0; i<N; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        struct TrieNode *root = getNode();
        for (string s : v)
            insert(root, s);        

        float total = 0;
        for (string s : v) {
            total += countKeystrokes(root, s);
        }

        // cout << total/v.size() << endl;
        printf("%.2f\n", total/v.size());
    }

    return 0;
}
