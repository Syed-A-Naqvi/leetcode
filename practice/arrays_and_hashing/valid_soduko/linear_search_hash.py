from typing import List, Union

class Solution:
    
    def isValidSudoku(self, board: List[List[Union[str,int]]]) -> bool: 
        
        for r in board:
            seen = set()
            for v in r:
                if v == '.':
                    continue
                if(v in seen):
                    return False
                else:
                    seen.add(v)
        
        for c in range(len(board[0])):
            seen = set()
            for r in range(len(board)):
                if board[r][c] == '.':
                    continue
                if board[r][c] in seen:
                    return False
                else:
                    seen.add(board[r][c])
        
        for square in range(9):
            seen = set()
            for r in range(3):
                for c in range(3):
                    row = (square//3) * 3 + r
                    col = (square%3) * 3 + c
                    
                    if (board[r][c] == "."):
                        continue
                    elif (board[r][c] in seen):
                        return False
                    else:
                        seen.add(board[r][c])
        
        return True



board = [["1","2",".",".","3","3",".",".","."],
         ["4",".",".","5",".",".",".",".","."],
         [".","9","8",".",".",".",".",".","3"],
         ["5",".",".",".","6",".",".",".","4"],
         [".",".",".","8",".","3",".",".","5"],
         ["7",".",".",".","2",".",".",".","6"],
         [".",".",".",".",".",".","2",".","."],
         [".",".",".","4","1","9",".",".","8"],
         [".",".",".",".","8",".",".","7","9"]]

print(Solution().isValidSudoku(board))
