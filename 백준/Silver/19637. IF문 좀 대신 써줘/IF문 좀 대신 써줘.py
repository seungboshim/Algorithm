import sys
input = sys.stdin.readline

[N, M] = list(map(int, input().strip().split(' ')))
tags = []
for _ in range(N):
  [tag, power] = input().strip().split(' ')
  tags.append([tag, int(power)])

characters = []
for _ in range(M):
  characters.append(int(input().strip()))

def upperBound(init, power, tags):
  # init 부터 이진탐색으로 power 이하를 만족하는 최대 인덱스 리턴!!
  left = init
  right = N-1
  while(left < right):
    mid = (left+right)//2
    if tags[mid][1] < power:
      left = mid+1
    else:
      right = mid
  return left

prev = 0
result = []
for power in characters:
  # 인덱스 리턴
  idx = upperBound(0, power, tags) 
  result.append(tags[idx][0])
  # 이전 인덱스 갱신
  prev = idx

resultStr = '\n'.join(result)
print(resultStr)