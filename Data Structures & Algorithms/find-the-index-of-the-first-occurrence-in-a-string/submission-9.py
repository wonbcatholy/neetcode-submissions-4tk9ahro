class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        lps = self.build_lps(needle)
        i = j = 0
        while i<len(haystack):
            if haystack[i]==needle[j]:
                i+=1
                j+=1
                if j==len(needle):
                    return i-j
            elif j!=0:
                j = lps[j-1]
            else:
                i+=1
        return -1
    def build_lps(self,needle:str):
        lps=[0]*len(needle)
        length = 0
        j = 1
        while j<len(needle):
            if needle[length] == needle[j]:
                length+=1
                lps[j]=length
                j+=1
            elif length!=0:
                length = lps[length-1]
            else:
                lps[j]=0
                j+=1
        return lps
        