import sys
input = sys.stdin.readline

N = int(input())
columns = []
for _ in range(N):
  value = list(map(int, input().strip().split(' ')))
  columns.append(value)

columns.sort(key=lambda x: x[0])

maxColumn = columns[0]
maxIdx = 0
for i in range(N):
  if maxColumn[1] <= columns[i][1]:
    maxColumn = columns[i]
    maxIdx = i

curr = columns[0]
area = 0

for i in range(maxIdx+1):
  # columns[i] = [위치, 높이]
  if curr[1] <= columns[i][1]:
    area += (curr[1] * (columns[i][0] - curr[0]))
    curr = columns[i]

area += maxColumn[1]

curr = columns[N-1]
for i in range(N-1, maxIdx-1, -1):
  if curr[1] <= columns[i][1]:
    area += (curr[1] * (curr[0] - columns[i][0]))
    curr = columns[i]

print(area)