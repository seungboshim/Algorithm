import sys
input = sys.stdin.readline

N = int(input())
balls = list(input().strip())

# 왼쪽으로 몰것인가? 오른쪽으로 몰것인가?
# R을 넘길래? B를 넘길래?
# 끝이 R일때, R이면 무시 // left[0],curr
# 끝이 R일때, B를 만나면 flag=true
# 이후로는 R을 만나도 넘겨야 함

def leftBalls(balls):
  Acount = 0 # 기준과 같은 색을 옮기는 횟수
  Bcount = 0
  isChanged = False

  for i in range(1,N):
    curr = balls[i]

    if not isChanged:
      if curr != balls[0]:
        isChanged = True
        Bcount+=1
      continue

    if curr == balls[0]:
      Acount+=1
    else:
      Bcount+=1
  return min(Acount, Bcount)

def rightBalls(balls):
  Acount = 0
  Bcount = 0
  isChanged = False

  for i in range(1,N):
    curr = balls[N-1-i]

    if not isChanged:
      if curr != balls[N-1]:
        isChanged = True
        Bcount+=1
      continue

    if curr == balls[N-1]:
      Acount+=1
    else:
      Bcount+=1
  return min(Acount, Bcount)

result = min(leftBalls(balls), rightBalls(balls))
print(result)