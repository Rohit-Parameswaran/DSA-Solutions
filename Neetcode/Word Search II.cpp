class TrieNode {
public:
    bool endWord;
    unordered_map<char, TrieNode*> children;

    TrieNode() : endWord(false) {}

    bool hasChild(char letter) {
        return children.count(letter);
    }

    void insert(string word) {
        TrieNode* curnode = this;
        for(auto letter: word) {
            if(!curnode->hasChild(letter)) {
                curnode->children[letter] = new TrieNode();
            }
            curnode = curnode->children[letter];
        }
        curnode->endWord = true;
    }
};

class Solution {
    TrieNode *root;
    vector<string> result;
    unordered_set<string> formedWords;
    int m, n;
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    void buildTrie(vector<string> &words) {
        root = new TrieNode();
        for(auto word: words)
            root->insert(word);
    }

    void dfs(vector<vector<char>> &board, TrieNode* curnode, int i, int j, string curStr) { 
        if(curnode->endWord && formedWords.count(curStr) == 0) {
            result.push_back(curStr);
            curnode->endWord = false;
        }
        if(i<0 || i>=m || j<0 || j>=n || board[i][j] == '#') return;

        if(curnode->hasChild(board[i][j])) {
            auto temp = board[i][j];
            curStr.push_back(temp);
            board[i][j] = '#';
            for(auto dir: dirs) {
                dfs(board, curnode->children[temp], i+dir[0], j+dir[1], curStr);
            }
            board[i][j] = temp;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTrie(words);
        m=board.size(), n=board[0].size();
        int i, j;

        for(i=0 ; i<m ; ++i) {
            for(j=0 ; j<n ; ++j) {
                if(root->hasChild(board[i][j]))
                    dfs(board, root, i, j, "");
            }
        }

        return result;
    }
};
