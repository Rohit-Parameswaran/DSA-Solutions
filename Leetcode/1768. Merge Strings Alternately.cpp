class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.size(), n2=word2.size(), i;
        string result;
        for(i=0; i<n1 && i<n2 ; ++i) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        while(i<n1) {
            result.push_back(word1[i++]);
        }
        while(i<n2) {
            result.push_back(word2[i++]);
        }
        return result;
    }
};
