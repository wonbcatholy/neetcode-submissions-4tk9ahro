class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> countS(26,0),countT(26,0);
        for(char c:t) countT[c-'a']++;
        for(char c:s) countS[c-'a']++;
        for(int i = 0;i<26;i++){
            if(countS[i]<countT[i]) return i+'a';
        }
        return ' ';
    }
};