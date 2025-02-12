import sys
from collections import defaultdict

input = sys.stdin.readline

T = int(input().strip())

# 한 문제에 대한 풀이를 여러 번 제출 -> 그 중 최고 점수가 그 문제에 대한 최종 점수가 된다. 
# (만약 어떤 문제에 대해 풀이를 한번도 제출하지 않았으면 그 문제에 대한 최종 점수는 0점이다.) 

# 당신 팀의 최종 점수는 각 문제에 대해 받은 점수의 총합이고, 
# 당신의 순위는 (당신 팀보다 높은 점수를 받은 팀의 수)+1 이다. 

# [동점팀 처리]
# 최종 점수가 같은 경우, 풀이를 제출한 횟수가 적은 팀의 순위가 높다. 
# 최종 점수도 같고 제출 횟수도 같은 경우, 마지막 제출 시간이 더 빠른 팀의 순위가 높다. 

for _ in range(T):
  # 팀 n개, 문제 k개, 우리팀 t, 제출수 m
  [n, k, t, m] = list(map(int, input().strip().split(' ')))
  table = []

  for _ in range(m):
    table.append(list(map(int, input().strip().split(' '))))

  teamScore = [{'team': 0, 'score': defaultdict(int), 'sum': 0, 'submit': 0, 'last': 0} for _ in range(n+1)] # {@번 문제: @점, @회}
  for idx in range(m):
    # [팀ID i, 문제번호 j, 점수 s]
    [i, j, s] = table[idx]

    teamScore[i]['team'] = i
    teamScore[i]['score'][j] = max(teamScore[i]['score'][j], s)
    teamScore[i]['submit'] += 1
    teamScore[i]['last'] = idx

  for i in range(1,n+1):
    score = sum(teamScore[i]['score'].values())
    teamScore[i]['sum'] = score

  teamScore.sort(key=lambda x: (-x['sum'], x['submit'], x['last']))

  rank = 0
  for score in teamScore:
    rank+=1
    if score['team'] == t: 
      print(rank)
      break