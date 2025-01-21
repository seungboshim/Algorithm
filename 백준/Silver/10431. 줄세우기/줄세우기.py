import sys
input = sys.stdin.readline
P = int(input())

def bubbleSort(arr):
  count = 0
  for _ in range(len(arr)):
    for j in range(len(arr)-1, 0, -1):
      if (arr[j] < arr[j-1]):
        arr[j], arr[j-1] = arr[j-1], arr[j]
        count+=1
  return count



for _ in range(P):
  # inputs = list(input().split())
  inputs = list(map(int, input().split())) # string -> int
  P = inputs[0]
  kids = inputs[1:] # 1부터 끝까지 spread 느낌?
  print(P, bubbleSort(kids)) # P, count 출력
  