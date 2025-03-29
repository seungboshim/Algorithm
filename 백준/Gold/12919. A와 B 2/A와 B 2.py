import sys
input = sys.stdin.readline

S = input().strip()
T = input().strip()

result = 0

def recur(s,t):
  global result
  if s==t:
    result = 1
    return
  if len(s)>=len(t):
    return
  
  if t[-1] == 'A': # 맨 뒤가 A면 빼기
    # print('1: ',t,t[0:-1])
    recur(s, t[0:-1])
  if t[0] == 'B': # 맨 앞이 B면 빼고 뒤집기
    temp = t[1:]
    # print("2: ",t,temp)
    recur(s, temp[::-1])

recur(S,T)
print(result)