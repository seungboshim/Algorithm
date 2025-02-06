import sys
input = sys.stdin.readline

string = input().strip()
n = 0

while len(string) > 0:
  n+=1
  for s in str(n):
    if len(string) == 0: break
    if string[0] in s:
      # print(f'match! {n} 의 {s}, {string[0]}')
      string = string[1 : len(string)]
  # print(n, string)
  
print(n)