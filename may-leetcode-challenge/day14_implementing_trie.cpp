/** 
Title :  Implement Trie (Prefix Tree)
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/
Idea  :  As long as enough elements are present in string ans, and last element of ans is greater than current element of num, pop it to guarantee that nxt element is smaller than previous one
Time Complexity : O(n) 
*/
class Node
{
public:
    Node *child[26];
    bool isEnd;
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isEnd = false;
    }
};
class Trie
{
public:
    /** Initialize your data structure here. */
    Node *root;
    Node *searchWord(string s)
    {
        Node *node = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (node->child[s[i] - 'a'] != NULL)
            {
                node = node->child[s[i] - 'a'];
                continue;
            }
            return NULL;
        }
        return node;
    }
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->child[word[i] - 'a'] == NULL)
            {
                node->child[word[i] - 'a'] = new Node();
            }
            node = node->child[word[i] - 'a'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = searchWord(word);
        return node != NULL && node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = searchWord(prefix);
        return node != NULL;
    }
};
