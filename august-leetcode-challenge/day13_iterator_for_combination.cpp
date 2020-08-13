/** 
Title :   Iterator for Combination
Link  :   https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3422/
Idea  :   Iterating and storing combinations in a vector
Time Complexity : O(n)
*/
/*
    Design an Iterator class, which has:
    A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
    A function next() that returns the next combination of length combinationLength in lexicographical order.
    A function hasNext() that returns True if and only if there exists a next combination.
    
    Example:
    CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.
    iterator.next(); // returns "ab"
    iterator.hasNext(); // returns true
    iterator.next(); // returns "ac"
    iterator.hasNext(); // returns true
    iterator.next(); // returns "bc"
    iterator.hasNext(); // returns false
    
    Constraints:
    1 <= combinationLength <= characters.length <= 15
    There will be at most 10^4 function calls per test.
    It's guaranteed that all calls of the function next are valid.
*/
class CombinationIterator
{
    vector<char> vec;
    int n;
    vector<string> ans;
    int top;

public:
    CombinationIterator(string characters, int combinationLength)
    {
        for (auto ele : characters)
            vec.push_back(ele);
        n = combinationLength;
        top = -1;
        getCombinations("", n);
    }

    string next()
    {
        return ans[++top];
    }

    bool hasNext()
    {
        return top != ans.size() - 1;
    }
    void getCombinations(string str, int &n)
    {
        if (str.size() > 1 && str[str.size() - 2] >= str[str.size() - 1])
            return;
        if (str.size() == n)
            ans.push_back(str);
        else if (str.size() < n)
        {
            for (int i = 0; i < vec.size(); i++)
            {
                getCombinations(str + vec[i], n);
            }
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */