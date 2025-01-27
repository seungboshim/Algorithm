import sys

N = int(sys.stdin.readline().strip())

switches = list(map(int, sys.stdin.readline().strip().split(' ')))
switches = [-1] + switches # 인덱스 맞추기용..

K = int(sys.stdin.readline().strip())
for _ in range (K):
  [gender, s] = list(map(int, sys.stdin.readline().strip().split(' ')))
  
  if gender == 1:
    for i in range(1, N+1):
      if i%s == 0:
        switches[i] = 1 - switches[i] # 0 <-> 1

  elif gender == 2:
    switches[s] = 1 - switches[s]
    for i in range(1, N+1):
      if (s-i < 1 or s+i > N): break # 범위 췍
      if switches[s+i] == switches[s-i]:
        switches[s+i] = 1 - switches[s+i]
        switches[s-i] = 1 - switches[s-i]
      else:
        break
  
    
for i in range(1, N+1):
  if i%20 == 0:
    print(switches[i])
  else:
    print(switches[i], end=' ')