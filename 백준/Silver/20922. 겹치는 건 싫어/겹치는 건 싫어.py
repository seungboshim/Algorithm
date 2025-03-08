import sys
from collections import defaultdict
input = sys.stdin.readline

[N, K] = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))

result = 0
curr = []
freq = defaultdict(int)

for i in range(N):
  curr.append(a[i])
  freq[a[i]]+=1

  if freq[a[i]] > K:
    while freq[a[i]] > K:
      temp = curr.pop(0)
      freq[temp]-=1

  result = max(result, len(curr))
  
print(result)