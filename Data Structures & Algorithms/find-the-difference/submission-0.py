class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        countS, countT = Counter(s),Counter(t)
        for c in countT:
            if c not in countS or countS[c] < countT[c]:
                return c