from queue import PriorityQueue, Queue

T = input()
for _ in range(int(T)):
  ran, key = map(int, input().split())
  q = Queue()
  pq = PriorityQueue()
  cnt = 0

  values = list(map(int, input().split()))
  for j in range(ran):
    value = values[j]
    q.put({'key': j, 'value': value})
    pq.put(-value)
  
  while not q.empty():
    temp = q.get()
    top = pq.get()

    if temp['value'] < -top:
      q.put(temp)
      pq.put(top)
    else:
      cnt += 1
      if temp['key'] == key: break

  print(cnt)