import sys
input = sys.stdin.readline

[N, K] = list(map(int, input().strip().split(' ')))

position = list(input().strip())
ate = 0

for i in range(N):
  if position[i] == 'P':
    # print(f'@@@@position[{i}] 번 자리 사람~~@@@@')
    for j in range(i-K, i+K+1):
      if j < 0 or j >= N: continue
      if position[j] == 'H':
        ate += 1
        position[j] = 'X'
        # print(f'position[{j}] 번에 버거룰 념념!!!!',''.join(position))
        break
      # else:
      #   print(f'position[{j}] 번에 버거가 없넹~')
print(ate)
