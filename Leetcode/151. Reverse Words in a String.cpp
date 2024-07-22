class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(), j=n-1;
        string curword, res;
        while(j>=0) {
            if(s[j] != ' '){
                curword = s[j] + curword;
            }
            else if(curword != "") {
                res.append(curword + " ");
                curword="";
            }
            j--;
        }
        if(curword != "")
            res.append(curword);
        if(res[res.size()-1] != ' ')
            return res;
        return res.substr(0, res.size()-1);
    }
};
