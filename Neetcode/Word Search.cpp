class Solution {
    vector<pair<int, int>> directions;
    char temp;
public:
    Solution() {
        directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    }

    bool existUtil(vector<vector<char>>& board, int &m, int &n, int i, int j, string &word, int curpos) {
        if(curpos == word.size()) return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != word[curpos]) return false;

        temp = board[i][j];
        board[i][j] = '*';
        for(auto dir: directions)
            if(existUtil(board, m, n, i+dir.first, j+dir.second, word, curpos+1))
                return true;
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(board[i][j] == word[0] && existUtil(board, m, n, i, j, word, 0))
                    return true;
        return false;
    }
};
