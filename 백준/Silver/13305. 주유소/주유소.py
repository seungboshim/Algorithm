import sys
input = sys.stdin.readline

N = int(input())

dist = list(map(int, input().split(' ')))
city = list(map(int, input().split(' ')))

#  2 3 1
# 5 2 4 1

minOil = city[0]
amount = 0

for i in range(0, N-1):
  minOil = min(city[i], minOil)
  tempAmount = minOil * dist[i]
  amount += tempAmount
  

print(amount)