import sys
input = sys.stdin.readline

N = int(input().strip())
cities = list(map(int, input().strip().split(' ')))
M = int(input().strip())

cities.sort()

left = 0
right = cities[N-1]
limit = 0

while(left <= right):
  total = 0
  mid = (left+right) // 2

  for city in cities:
    total += min(city, mid)

  if total > M:
    right = mid-1
  elif total <= M:
    limit = mid
    left = mid+1
  else:
    limit = mid
    break

print(limit)