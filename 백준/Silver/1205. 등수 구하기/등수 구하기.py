import sys
input = sys.stdin.readline()

init = list(map(int, input.strip().split(" ")))
[N, score, P] = init

scoreBoard = []
rank = 1
overFlow = False

if N > 0:
  input = sys.stdin.readline()
  scoreBoard = list(map(int, input.strip().split(" ")))
  for i in range(len(scoreBoard)):
    if score > scoreBoard[i]:
      break
    else:
      if i+1 >= P:
        overFlow = True
        break
      if score == scoreBoard[i]:
          continue
      else:
        rank = i+2

if overFlow:
  print(-1)
else:
  print(rank)