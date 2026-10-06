class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_ = 0
        add = 0
        for c in s:
            if c == '(':
                open_ += 1
            else:
                if open_ > 0:
                    open_ -= 1
                else:
                    add += 1
        return add + open_