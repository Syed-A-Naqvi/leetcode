# Hash Set Method
    # maintain a hash set for the rows, columns and subsquares of the board
    # iterate over the entire board once
    # during each iteration, check if the elment exisits in its corresponding row set, column set or subsquare set
        # if yes return false
        # if no, insert value into each respective set
    # Time: O(n^2) -> need to iterate of n^2 cells where n = length of board
    # Space: O(3n^2) -> in the worst case (board is valid) will end up with 3 default dicts, each with 9x9 (n^2) elements

from typing import List
from collections import defaultdict

class Solution:

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        squares = defaultdict(set)
        rows = defaultdict(set)
        cols = defaultdict(set)
        
        for r in range(9):
            for c in range(9):
                val = board[r][c]
                
                if val == ".":
                    continue
                
                if (val in rows[r]) or (val in cols[c]) or (val in squares[(r//3,c//3)]):
                    return False
                else:
                    rows[r].add(val)
                    cols[c].add(val)
                    squares[(r//3,c//3)].add(val)
        
        return True

board = [["1","2",".",".","3",".",".",".","."],
         ["4",".",".","5",".",".",".",".","."],
         [".","9","8",".",".",".",".",".","3"],
         ["5",".",".",".","6",".",".",".","4"],
         [".",".",".","8",".","3",".",".","5"],
         ["7",".",".",".","2",".",".",".","6"],
         [".",".",".",".",".",".","2",".","."],
         [".",".",".","4","1","9",".",".","8"],
         [".",".",".",".","8",".",".","7","9"]]

print(Solution().isValidSudoku(board))
