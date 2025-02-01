import sys
input = sys.stdin.readline

N = int(input())

dist = list(map(int, input().split(' ')))
city = list(map(int, input().split(' ')))

#  2 3 1
# 5 2 4 1

amount = city[0] * dist[0] # 0번 도시 -> 1번 도시 필요 기름

for i in range(1, N-1):
  prevAmount = city[i-1] * dist[i]
  tempAmount = city[i] * dist[i] # 1 -> 2
  amount = min(amount+tempAmount, amount+prevAmount)

print(amount)