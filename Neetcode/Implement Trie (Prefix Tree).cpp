class PrefixTree {
    bool isEnd;
    vector<PrefixTree*> children;
public:
    PrefixTree() {
        isEnd = false;
        children = vector<PrefixTree*> (26, nullptr);
    }
    
    void insert(string word) {
        auto *curNode = this;
        for(auto c: word) {
            if(!curNode->children[c-'a'])
                curNode->children[c-'a'] = new PrefixTree();
            curNode = curNode->children[c-'a'];
        }
        curNode->isEnd = true;
    }
    
    bool search(string word, bool prefixCheck=false) {
        auto *curNode = this;
        for(auto c: word) {
            if(curNode->children[c-'a'])
                curNode = curNode->children[c-'a'];
            else return false;
        }
        return prefixCheck || curNode->isEnd;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
