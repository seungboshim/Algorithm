import sys
input = sys.stdin.readline

N = int(input())
field = [['']*(N+1)]

for _ in range(N):
  line = list(input().strip())
  field.append(['']+line)

# 머리는 무조건 하나~
# 가다가 머리를 만난뒤 그 바로아래가 심장좌표

findHead = False # 머리 만났니
heartRow = 0
heartCol = 0


for i in range(1, N+1):
  for j in range(1, N+1):
    if (field[i][j] == '*' and not findHead): # 머리 만남
      findHead = True
      heartRow = i+1
      heartCol = j
      break

leftArm = 0
rightArm = 0
body = 0
leftLeg = 0
rightLeg = 0

for i in range(1, N+1):
  if (i<heartCol and field[heartRow][i] == '*'):
    leftArm+=1
  elif (i>heartCol and field[heartRow][i] == '*'):
    rightArm+=1

for i in range(heartRow+1, N+1):
  for j in range(1, N+1):
    if (j==heartCol and field[i][j] == '*'):
      body+=1
    elif (j==heartCol-1 and field[i][j] == '*'):
      leftLeg+=1
    elif (j==heartCol+1 and field[i][j] == '*'):
      rightLeg+=1

print(heartRow, heartCol)
print(leftArm, rightArm, body, leftLeg, rightLeg)