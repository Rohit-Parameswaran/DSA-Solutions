// This question is not on A2Z sheet. It is on Leetcode and it is a DFS/BFS question and not a Greedy problem
class Solution {
public:
    bool dfs(vector<int> &arr, int cur) {
        if(cur<0 || cur>=arr.size() || arr[cur] < 0)
            return false;
        if(arr[cur] == 0) return true;

        arr[cur] *= -1;
        if(dfs(arr, cur+arr[cur]) || dfs(arr, cur-arr[cur]))
            return true;
        arr[cur] *= -1;
        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        return dfs(arr, start);        
    }
};
