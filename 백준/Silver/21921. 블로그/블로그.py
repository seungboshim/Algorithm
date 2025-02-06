import sys
input = sys.stdin.readline

[N, X] = list(map(int, input().strip().split(' ')))
visits = list(map(int, input().strip().split(' ')))

# 슬라이딩 윈도우~

sum = 0

for i in range(X):
  sum += visits[i]

results = [sum]

for i in range(N-X):
  sum = sum - visits[i] + visits[i+X]
  results.append(sum)

results.sort(reverse=True)

if results[0] == 0: print('SAD')
else:
  maxCnt = 0
  for r in results:
    if r == results[0]:
      maxCnt+=1
    else: break
  print(f'{results[0]}\n{maxCnt}')