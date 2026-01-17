class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:

      n = len(bottomLeft)
      max_area = 0

      
      for i in range(n):
          for j in range(i + 1, n):
              
              ax1, ay1 = bottomLeft[i]
              ax2, ay2 = topRight[i]

              
              bx1, by1 = bottomLeft[j]
              bx2, by2 = topRight[j]

              # find overlap rectangle
              left = max(ax1, bx1)
              right = min(ax2, bx2)
              bottom = max(ay1, by1)
              top = min(ay2, by2)

              # check if overlap exists
              width = right - left
              height = top - bottom

              if width > 0 and height > 0:
                  side = min(width, height)
                  max_area = max(max_area, side * side)

      return max_area
          