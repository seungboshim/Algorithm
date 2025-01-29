import sys
import math

input = sys.stdin.readline

N = int(input())
M = int(input())
position = list(map(int, input().split(' ')))
position = [0] + position + [N]
# print(position)
maxLength = 0

for i in range(M+1):
  length = position[i+1] - position[i]
  # print(position[i], position[i+1], length, round(length))
  if 0 < i < M:
    length = math.ceil(length/2)

  maxLength = max(maxLength, length)

print(maxLength)