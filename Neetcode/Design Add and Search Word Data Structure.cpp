// BFS Solution
class TrieNode {
    public:
        bool endWord = false;
        unordered_map<char, TrieNode*> children;
};

class WordDictionary {
    TrieNode *root = new TrieNode();
public:
    WordDictionary() {}
    
    void addWord(string word) {
        auto curNode = root;
        for(auto letter: word) {
            if(curNode->children.count(letter) == 0)
                curNode->children[letter] = new TrieNode();
            curNode = curNode->children[letter];
        }
        curNode->endWord = true;
    }
    
    void pushMatchesToQueue(queue<TrieNode*> &q, auto curNode, int letter) {
        if(letter == '.')
            for(auto it: curNode->children)
                q.push(it.second);
        else if(curNode->children.count(letter))
            q.push(curNode->children[letter]);
    }
    
    bool search(string word) {
        queue<TrieNode*> q;
        pushMatchesToQueue(q, root, word[0]);
        int pos=1, n=word.size();
        q.push(NULL);
        while(!q.empty() && pos<n) {
            auto curNode = q.front();
            q.pop();
            if(curNode == NULL) {
                ++pos;
                if(!q.empty()) q.push(NULL);
            }
            else pushMatchesToQueue(q, curNode, word[pos]);
        }
        while(!q.empty()) {
            if(q.front() && q.front()->endWord) return true;
            q.pop();
        }
        return false;
    }
};
