import sys
input = sys.stdin.readline

S = input()

zero = 0
one = 0
for s in S:
  if s == '0': zero+=1
  else: one+=1

zero //= 2
one //= 2

result = '0'*zero + '1'*one
print(result)