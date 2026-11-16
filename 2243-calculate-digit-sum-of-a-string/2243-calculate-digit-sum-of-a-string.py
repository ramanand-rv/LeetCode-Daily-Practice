class Solution:
    def digitSum(self, s: str, k: int) -> str:
        # Keep shrinking the string until its length is at most k
        while len(s) > k:
            next_s = []

            # Process the string in chunks of size k
            for i in range(0, len(s), k):
                chunk = s[i : i + k]
                # Sum the digits in the current chunk
                total = sum(int(d) for d in chunk)
                # Append the sum to the next string
                next_s.append(str(total))

            # Update s for the next round
            s = "".join(next_s)

        return s
