class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        # Sort unique values
        sorted_unique = sorted(set(arr))
        
        # Create mapping from value to rank (1-based)
        rank_map = {val: i + 1 for i, val in enumerate(sorted_unique)}
        
        # Replace each element with its rank
        return [rank_map[x] for x in arr]