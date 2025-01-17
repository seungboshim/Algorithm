import sys

input = sys.stdin.readline
N = int(input())

S = set()

for _ in range (1, N+1):
  command = input().split()
  if (command[0] == 'add'):
    S.add(command[1])
  elif (command[0] == 'remove'):
    S.discard(command[1])
  elif (command[0] == 'check'):
    if (command[1] in S): print(1)
    else: print(0)
  elif (command[0] == 'toggle'):
    if (command[1] in S): S.discard(command[1])
    else: S.add(command[1])
  elif (command[0] == 'all'):
    S = set([str(i) for i in range(1, 21)])
  elif (command[0] == 'empty'):
    S = set()
