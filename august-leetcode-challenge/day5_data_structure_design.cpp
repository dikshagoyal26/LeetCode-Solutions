/** 
Title :   Add and Search Word - Data structure design
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3413/
Idea  :   Trie
Time Complexity : O(n)
*/
/*
    Design a data structure that supports the following two operations:
    void addWord(word)
    bool search(word)
    search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

    Example:
    addWord("bad")
    addWord("dad")
    addWord("mad")
    search("pad") -> false
    search("bad") -> true
    search(".ad") -> true
    search("b..") -> true
    Note:
    You may assume that all words are consist of lowercase letters a-z.
*/
class TrieNode
{
public:
    vector<TrieNode *> next;
    bool isWord = false;
    TrieNode()
    {
        next.resize(26, NULL);
    }
};
class WordDictionary
{
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (!current->next[ch - 'a'])
            {
                current->next[ch - 'a'] = new TrieNode();
            }
            current = current->next[ch - 'a'];
        }
        current->isWord = true;
    }
    bool searchHelper(string word, TrieNode *current)
    {
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (ch != '.')
            {
                if (!current->next[ch - 'a'])
                    return false;
                current = current->next[ch - 'a'];
            }
            else
            {
                for (int j = 0; j < 26; j++)
                {
                    if (current->next[j] && searchHelper(word.substr(i + 1), current->next[j]))
                    {
                        return true;
                    }
                }
                return false;
            }
        }
        return current->isWord;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return searchHelper(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */