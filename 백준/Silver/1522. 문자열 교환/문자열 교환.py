import sys
from collections import Counter
input = sys.stdin.readline

arr = list(input().strip())
counter = Counter(arr)
window = counter['a']
result = 1000

for i in range(len(arr)):
  countB = 0
  for j in range(window):
    if arr[(i+j)%len(arr)] == 'b':
      countB+=1
  result = min(result, countB)

print(result)