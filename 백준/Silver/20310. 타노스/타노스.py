import sys
input = sys.stdin.readline

S = list(input().strip())
length = len(S)

zero = 0
one = 0
for s in S:
  if s == '0': zero+=1
  else: one+=1

left = 0
zerodel = 0
onedel = 0
delIdx = []
for left in range(len(S)):
  if zerodel == zero/2 and onedel == one/2:
    break
  
  right = len(S)-left-1
  # print(left,right,S)

  if S[left] == '1' or S[right] == '0':
    if S[left] == '1' and onedel < one/2:
      delIdx.append(left)
      onedel+=1
    if S[right] == '0' and zerodel < zero/2:
      delIdx.append(right)
      zerodel+=1

delIdx.sort(reverse=True)
for idx in delIdx:
  del S[idx]

print(''.join(S))