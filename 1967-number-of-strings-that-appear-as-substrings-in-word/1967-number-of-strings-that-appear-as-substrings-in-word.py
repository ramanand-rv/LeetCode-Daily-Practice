class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        substrings = 0
        for s in patterns:
            # if word.find(s) != -1:
            if s in word:
                substrings += 1
        return substrings