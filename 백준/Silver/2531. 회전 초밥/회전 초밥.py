import sys
from collections import deque
from collections import Counter

input = sys.stdin.readline

[N, d, k, c] = list(map(int, input().strip().split(' ')))
sushiBelt = deque()
for _ in range(N):
  sushiBelt.append(int(input().strip()))

# k개의 접시, 먹을수 있는 최대 가짓수
# window 크기 k

# 벨트에 쿠폰초밥 없는경우 False
isCouponSushi = False
for sushi in list(sushiBelt):
  if sushi == c:
    isCouponSushi = True
    break

init = list(sushiBelt)[:k]
counter = Counter(init)
result = len(counter)

for i in range(N):
  prev = sushiBelt[0]
  if N <= k:
    next = sushiBelt[0]
  else:
    next = sushiBelt[k]

  counter[prev]-=1
  counter[next]+=1
  if counter[prev] == 0:
    del counter[prev]

  currDish = len(counter)
  if counter[c] == 0 and isCouponSushi:
    currDish+=1
  result = max(result, currDish)

  temp = sushiBelt.popleft()
  sushiBelt.append(temp)

if not isCouponSushi:
  result += 1

print(result)