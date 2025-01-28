import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
  N = int(input().strip())
  data = list(map(int, input().strip().split(' ')))

  # rank = {}
  # for i in range(1, N+1):
  #   rank[i] = data[i-1]

  # table = {}
  # for i in range(1, N+1):
  #   team = rank[i]
  #   table[team] += []

  table = {}
  for i in range(1, N+1):
    team = data[i-1]
    if team not in table.keys(): table[team] = []
    table[team].append(i)

  scoreBoard = {}
  finalScore = {}
  score = 1
  for i in range(1, N+1):
    team = data[i-1]
    if (len(table[team]) < 6): continue

    if team not in scoreBoard.keys(): 
      scoreBoard[team] = []
      finalScore[team] = 0

    # print(f'{i}번루프: {team}에 {score}점')
    scoreBoard[team].append(score)
    
    if len(scoreBoard[team]) < 5:
      finalScore[team] += score

    score+=1

  minScore = min(finalScore.values())
  winners = []

  for team in scoreBoard.keys():
    if finalScore[team] == minScore:
      winners.append(team)

  winner = 0
  if len(winners) == 1:
    print(winners[0])
  else:
    min5thScore = 1000
    for team in winners:
      if min5thScore > scoreBoard[team][4]:
        min5thScore = scoreBoard[team][4]
        winner = team
    print(winner)
  