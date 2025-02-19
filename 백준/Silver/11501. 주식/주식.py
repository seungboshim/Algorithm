import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
  N = int(input())
  stock = list(map(int, input().strip().split(' ')))
  maxVal = stock[N-1]
  profit = 0
  for s in reversed(stock):
    if s >= maxVal:
      maxVal = s
    else:
      profit += (maxVal-s)
  print(profit)
