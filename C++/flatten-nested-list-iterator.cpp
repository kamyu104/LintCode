// Time:  O(n), n is the number of the integers.
// Space: O(h), h is the depth of the nested lists.

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    using IT = vector<NestedInteger>::const_iterator;
    NestedIterator(vector<NestedInteger> &nestedList) {
        depth_.emplace(nestedList.cbegin(), nestedList.cend());
    }

    // @return {int} the next element in the iteration
    int next() {
        return (depth_.top().first++)->getInteger();
    }
    
    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        while (!depth_.empty()) {
            auto& cur = depth_.top();
            if (cur.first == cur.second) {
                depth_.pop();
            } else if (cur.first->isInteger()) {
                return true;
            } else {
                auto& nestedList = cur.first->getList();
                ++cur.first;
                depth_.emplace(nestedList.cbegin(), nestedList.cend());
            }
        }
        return false;
    }

private:
    stack<pair<IT, IT>> depth_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
 
