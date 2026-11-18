class Solution:
    def minChanges(self, s: str) -> int:
        changes = 0
        # Loop through the string in steps of 2
        for i in range(0, len(s), 2):
            # If the two characters in the pair are different, one change is needed
            if s[i] != s[i + 1]:
                changes += 1
        return changes
