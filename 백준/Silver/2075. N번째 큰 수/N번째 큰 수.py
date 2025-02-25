import sys
import heapq
input = sys.stdin.readline

N = int(input())
board = []

for _ in range(N):
  line = list(map(int, input().split(' ')))
  for l in line:
    if len(board) < N:
      heapq.heappush(board, l)
    elif board[0] < l:
      heapq.heappop(board)
      heapq.heappush(board, l) 

print(board[0])