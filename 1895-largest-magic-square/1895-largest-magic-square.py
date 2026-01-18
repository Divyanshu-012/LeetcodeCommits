class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        def isMagic(i, j, size):
            nonlocal prefix_row, prefix_col

            # consider the square with the horizontal edge btw (i, j) to (i, j + size)
            target = prefix_row[i][j + size] - prefix_row[i][j]

            diag, anti = 0, 0

            # check diagonal matrix
            for d in range(size):
                # sum cells in (i, j) to (i + size, j + size)
                diag += grid[i + d][j + d]

                # sum cells in (i, size - 1 - j) to (i + size, j)
                anti += grid[i + d][size - 1 - (d - j)]

            # stop; not possible
            if diag != anti or diag != target:
                return False

            # for each row, search if each row has the same sum
            for r in range(size):
                # freeze the row and search btw [j: j + size] columns
                summ = prefix_row[i + r][j + size] - prefix_row[i + r][j]

                # stop; 
                if  summ != target:
                    return False

            # for each column, search if each column has the same sum
            for c in range(size):
                # freeze the column and search btw [i: i + size] rows
                summ = prefix_col[i + size][j + c] - prefix_col[i][j + c]

                # stop
                if summ != target:
                    return False

            return True

        m, n = len(grid), len(grid[0])

        # prefix_row[i][j + 1] := total sum in the ith row by the end of index j
        prefix_row = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

        # prefix_col[i + 1][j] := total sum in the jth column by the end of index i 
        prefix_col = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m):
            for j in range(n):
                # freeze i and update prefix_row[i][j + 1]
                prefix_row[i][j + 1] = prefix_row[i][j] + grid[i][j]

                # freeze j and update prefix_col[i + 1][j]
                prefix_col[i + 1][j] = prefix_col[i][j] + grid[i][j]

        res = 1

        # search for maximum length 
        for size in range(2,  min(m, n) + 1):
            for i in range(m - size + 1):
                for j in range(n - size + 1):

                    # update res once found a valid block
                    if isMagic(i, j, size):
                        res = max(res, size)
        return res