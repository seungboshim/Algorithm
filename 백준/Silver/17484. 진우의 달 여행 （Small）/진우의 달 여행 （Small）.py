import sys
input = sys.stdin.readline

[N, M] = list(map(int, input().strip().split(' ')))

space = []
dp = [[[0]*3 for _ in range(M)] for _ in range(N)]
for i in range(N):
  line = list(map(int, input().strip().split(' ')))
  space.append(line)

for i in range(N):
  for j in range(M):
    dp[i][j] = [space[i][j]]*3
    if j == 0:
      dp[i][j][0] = 1000
    if j == M-1:
      dp[i][j][2] = 1000

# 0 1 2 -> 왼 위 오른쪽에서 오는 경우를 다 저장
# 0 : [i-1][j-1]에서 [1][2] 에 오는것
for i in range(1,N):
  for j in range(M):
    if j != 0:
      dp[i][j][0] += min(dp[i-1][j-1][1], dp[i-1][j-1][2])
    dp[i][j][1] += min(dp[i-1][j][0], dp[i-1][j][2])
    if j != M-1:
      dp[i][j][2] += min(dp[i-1][j+1][0], dp[i-1][j+1][1])

result = 1000
for i in range(M):
  result = min(result, min(dp[N-1][i]))
print(result)