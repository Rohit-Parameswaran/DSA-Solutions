class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> hash;
        unordered_map<int, int> fc;
        priority_queue<int> freq_dec;
        vector<int> ans;

        for(auto it: nums) ++fc[it];
        for(auto it: fc) {
            hash[it.second].push_back(it.first);    
        }
        for(auto it: hash) freq_dec.push(it.first);

        while(k) {
            auto chf = freq_dec.top();
            freq_dec.pop();

            ans.insert(ans.end(), hash[chf].begin(), hash[chf].end());
            k-=hash[chf].size();
        }

        return ans;
    }
};
