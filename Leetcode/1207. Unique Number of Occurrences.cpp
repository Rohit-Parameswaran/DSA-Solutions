class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> countVals;
        vector<int> count(2001, 0);

        for(auto it: arr) {
            ++count[it+1000];
        }

        for(auto it: count) {
            if(it > 0) {
                if(countVals.count(it))
                    return false;
                countVals.insert(it);
            }
        }

        return true;
    }
};
