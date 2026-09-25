class Solution {
public:
    vector<int> build_lps(string needle){
        vector<int> lps(needle.size(),0);
        int length = 0;
        int j = 1;
        while (j<needle.size()){
            if(needle[length]==needle[j])
                lps[j++]=++length;
            else if (length!=0)
                length = lps[length-1];
            else 
                lps[j++]=0;
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        vector<int> lps = build_lps(needle);
        int i = 0;
        int j = 0;
        while(i<haystack.size()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==needle.size())
                    return i-j;
            }
            else if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
        return -1;
    }
        
};