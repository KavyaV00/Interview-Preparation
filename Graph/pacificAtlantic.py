import collections

class Solution:
    
    def pacificAtlantic(self, heights) :
        
        def bfs(q, seen):
            while q:
                r,c  = q.popleft()

                for x, y in ((r-1,c),(r+1,c),(r,c-1),(r,c+1)):
                    if not(0<=x<row and 0<=y<col) or heights[x][y]<heights[r][c] or (x,y) in seen:
                        continue
                    else:
                        q.append((x,y))
                        seen.add((x,y))
        
        row = len(heights)
        col = len(heights[0])
        
        pacific_q = collections.deque()
        pacific_seen = set()
        
        atlantic_q = collections.deque()
        atlantic_seen = set()
        
        for i in range(0, row):
            pacific_q.append((i, 0))
            pacific_seen.add((i, 0))
            
            atlantic_q.append((i, col-1))
            atlantic_seen.add((i, col-1))
        
        for i in range(0, col):
            pacific_q.append((0, i))
            pacific_seen.add((0, i))
            
            atlantic_q.append((row-1, i))
            atlantic_seen.add((row-1, i))
        
        bfs(pacific_q, pacific_seen)
        bfs(atlantic_q, atlantic_seen)
        
        return atlantic_seen&pacific_seen