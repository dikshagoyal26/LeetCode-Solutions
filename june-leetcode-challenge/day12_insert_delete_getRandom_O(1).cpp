/** 
Title :   Insert Delete GetRandom O(1)
Link  :   https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3358/
Idea  :   Created a map and a vector and inserted values in vector and in map along with its index and before inserting cecking if its present in map the return false, while removing checking if its present in map or not, and if present get its index and swap that index with last index and removing last index from vector and map. to get random value, a random number is generated and returned the value at its index
Time Complexity : O(n)
*/
/**
    Design a data structure that supports all following operations in average O(1) time.
    insert(val): Inserts an item val to the set if not already present.
    remove(val): Removes an item val from the set if present.
    getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 */

class RandomizedSet
{
private:
    vector<int> nums;
    unordered_map<int, int> positions;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (positions.find(val) != positions.end())
            return false;
        nums.push_back(val);
        positions.insert({val, nums.size() - 1});
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (positions.find(val) == positions.end())
            return false;
        int pos = positions[val];
        nums[pos] = nums[nums.size() - 1];
        positions[nums[pos]] = pos;
        nums.pop_back();
        positions.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */