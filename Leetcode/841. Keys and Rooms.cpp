class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> checked(rooms.size(), false);
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            checked[q.front()] = true;
            for(auto it: rooms[q.front()]) {
                if(!checked[it])
                    q.push(it);
            }
            q.pop();
        }

        for(auto it: checked) if(!it) return false;
        return true;
    }
};
