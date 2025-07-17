class Solution(object):
    
        def findNonMinOrMax(self, A):
            return -1 if len(A) < 3 else sum(A[:3]) - min(A[:3]) - max(A[:3])
        