import sys
input = sys.stdin.readline

[N,M] = list(map(int, input().split(' ')))
memos = set()
for _ in range(N):
  memos.add(input().strip())

for _ in range(M):
  keywords = input().strip().split(',')
  for k in keywords:
    memos.discard(k)
  print(len(memos))