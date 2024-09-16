class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for (auto it : asteroids) {
            if(it < 0) {
                while(!s.empty() && s.top() > 0 && s.top() < -it) {
                    s.pop();
                }
                if(s.empty() || s.top() < 0) s.push(it);
                else if(s.top() == -it) s.pop();
            }
            else s.push(it);
        }

        vector<int> ans(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};
