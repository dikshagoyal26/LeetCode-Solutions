/** 
Title :   Word Search II
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/543/week-5-june-29th-june-30th/3376/
Idea  :   Trie and DFS 
Time Complexity : O(n^l)
*/
/**
    Given a 2D board and a list of words from the dictionary, find all words in the board.
    Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
    Example:
    Input: 
    board = [
    ['o','a','a','n'],
    ['e','t','a','e'],
    ['i','h','k','r'],
    ['i','f','l','v']
    ]
    words = ["oath","pea","eat","rain"]
    Output: ["eat","oath"]
    Note:
    All inputs are consist of lowercase letters a-z.
    The values of words are distinct.
*/
class Solution
{
    struct TrieNode
    {
        TrieNode *children[26];
        string word;

        TrieNode() : word("")
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = buildTrie(words);
        vector<string> result;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

    /** Inserts a word into the trie. */
    TrieNode *buildTrie(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (int j = 0; j < words.size(); j++)
        {
            string word = words[j];
            TrieNode *curr = root;
            for (int i = 0; i < word.length(); i++)
            {
                char c = word[i] - 'a';
                if (curr->children[c] == nullptr)
                {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result)
    {
        char c = board[i][j];
        if (c == '#' || !p->children[c - 'a'])
            return;
        p = p->children[c - 'a'];
        if (p->word.size() > 0)
        {
            result.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        if (i > 0)
            dfs(board, i - 1, j, p, result);
        if (j > 0)
            dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1)
            dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1)
            dfs(board, i, j + 1, p, result);
        board[i][j] = c;
    }
};