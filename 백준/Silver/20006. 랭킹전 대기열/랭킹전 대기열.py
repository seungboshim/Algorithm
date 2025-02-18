import sys
input = sys.stdin.readline

[p, m] = list(map(int, input().strip().split(' ')))

rooms = []
for i in range(p):
  [level, nickname] = input().strip().split(' ')
  level = int(level)

  if i == 0:
    rooms.append([[level, nickname]])
  else:
    for i in range(len(rooms)):
      room = rooms[i]
      initLevel = room[0][0]
      if len(room) < m: # 덜찬 방
        if initLevel-10 <= level <= initLevel+10: # 레벨 범위 안
          room.append([level, nickname]) # 입장
          break
        else: # 레벨 범위 밖
          if i < len(rooms)-1:
            continue
          else: # 마지막 루프는 방 생성
            rooms.append([[level, nickname]])
            break
      else:
        if i == len(rooms)-1:
          rooms.append([[level, nickname]])
          break

for room in rooms:
  result = []
  room.sort(key=lambda x:x[1])
  if len(room) == m:
    result.append('Started!')
  else:
    result.append('Waiting!')
  for p in room:
    result.append(f'{str(p[0])} {p[1]}')
  print('\n'.join(result))