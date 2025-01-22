import sys
input = sys.stdin.readline

N = int(input())
people = []

for _ in range(N):
  person = list(map(int, input().split()))
  people.append(person)

rank = [1] * N

for i in range(N):
  for j in range(N):
    if people[i][0] < people[j][0] and people[i][1] < people[j][1]:
      rank[i] += 1

for i in rank:
  print(i, end=' ')