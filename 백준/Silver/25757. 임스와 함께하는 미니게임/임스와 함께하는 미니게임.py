import sys
input = sys.stdin.readline

init = input().strip().split(' ')
N = int(init[0])
game = init[1]
capa = 1 if game=='Y' else 2 if game=='F' else 3 if game=='O' else None

waiting = []

for _ in range(N):
  waiting.append(input().strip())

count = 0
queue = set()
history = set()

for i in waiting:
  if i in history: continue

  queue.add(i)
  history.add(i)

  if len(queue) == capa:
    count+=1
    queue.clear()

print(count)