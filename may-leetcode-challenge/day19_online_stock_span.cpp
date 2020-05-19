/** 
Title :  Online Stock Span
Link  :  https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3334/
Idea  :  Took two stacks, one for prices and another for weights, and traversing and combining all smaller ptices along with their weights.
Time Complexity : O(n) where n is number of queries 
*/
class StockSpanner
{
public:
    stack<int> prices, weights;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int count = 1;
        while (!prices.empty() && prices.top() <= price)
        {
            prices.pop();
            count += weights.top();
            weights.pop();
        }
        prices.push(price);
        weights.push(count);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */