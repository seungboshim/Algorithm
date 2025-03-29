import sys
input = sys.stdin.readline

T = int(input())
N = []
for _ in range(T):
  N.append(int(input()))
maxN = sorted(N)[-1]

dp = [1 for _ in range(maxN+1)]

# 1
# 1+1 / 0+2
# 1+1+1 / 1+2 / 0+3
# 1+1+1+1 / [1+1+2 / 0+2+2] / 1+3 

for i in range(2,maxN+1):
  dp[i] += dp[i-2]
for i in range(3,maxN+1):
  dp[i] += dp[i-3]

for n in N:
  print(dp[n])