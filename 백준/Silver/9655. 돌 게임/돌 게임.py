import sys

input = sys.stdin.readline
N = int(input())

dp = []
dp.append(0) # 0이면 상근이가 이김
dp.append(0)
dp.append(1)
dp.append(0)

for i in range(4, N+1):
  if (dp[i-1] == 0 or dp[i-3] == 0):
    dp.append(1)
  else:
    dp.append(0)

if (dp[N] == 0):
  print('SK')
else:
  print('CY')