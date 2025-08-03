class Solution {
    pair<char, char> INVALID_ORDER_SENTINEL = {'#', '#'};
    pair<char, char> NO_RELATION_SENTINEL = {'\0', '\0'};
public:
    pair<char, char> getFirstNonMatchingChars(const string &a, const string &b) {
        int n = min(a.size(), b.size());
        for(int i=0 ; i<n ; ++i)
            if(a[i] != b[i])
                return {a[i], b[i]};
        if(a.size() <= b.size()) return NO_RELATION_SENTINEL;
        return INVALID_ORDER_SENTINEL;
    }

    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        queue<char> q;
        string res;
        char cur;

        int n = words.size();

        for(auto word: words)
            for(auto letter: word)
                indegree[letter] = 0;

        for(int i=1 ; i<n ; ++i) {
            pair<char, char> p = getFirstNonMatchingChars(words[i-1], words[i]);
            if(p == INVALID_ORDER_SENTINEL) return "";
            if(p != NO_RELATION_SENTINEL) {
                adj[p.first].push_back(p.second);
                ++indegree[p.second];
            }
        }

        for(auto it: indegree){
            if(it.second == 0)
                q.push(it.first);
        }

        while(!q.empty()) {
            cur = q.front();
            q.pop();
            for(auto it: adj[cur]) {
                --indegree[it];
                if(indegree[it] == 0) q.push(it);
            }
            res.push_back(cur);
        }
        return res.size() == indegree.size() ? res : "";
    }
};
