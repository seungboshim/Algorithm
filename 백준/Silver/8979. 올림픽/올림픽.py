import sys
input = sys.stdin.readline

# N, K = input().split()
# N, K = int(N), int(K)
N, K = map(int, input().split()) # string -> int

medals = []

for _ in range(N):
  medal = list(map(int, input().split())) # string -> int, 배열로 만들기
  medals.append(medal)
  
medals.sort(key=lambda x: (-x[1], -x[2], -x[3]))

for i in range(N):
  if medals[i][0] == K:
    if i == 0:
      print(1)
    else:
      if (medals[i][1] == medals[i-1][1] and medals[i][2] == medals[i-1][2] and medals[i][3] == medals[i-1][3]):
        print(i)
      else: print(i+1)
    break