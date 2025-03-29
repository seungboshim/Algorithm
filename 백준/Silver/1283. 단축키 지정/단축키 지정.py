import sys
input = sys.stdin.readline

N = int(input().strip())
options = []
for _ in range(N):
  options.append(input().strip())

shortcuts = []
answer = []
for i in range(N):
  option = options[i]
  words = option.split(" ") # 단어 배열

  if len(shortcuts)==0: # 맨 처음
    char = option[0]
    shortcuts.append(char.upper())
    newOption = f'[{char}]' + option[1:]
    answer.append(newOption)
    continue

  for j in range(len(words)): # 단어 첫글자
    char = words[j][0]
    if char.upper() not in shortcuts:
      shortcuts.append(char.upper())
      newWord = f'[{char}]' + words[j][1:]
      newWords = words[:j] + [newWord] + words[j+1:]
      newOption = ' '.join(newWords)
      answer.append(newOption)
      break
  
  if len(shortcuts) <= i: # 모든 철자
    flag = False
    for j in range(len(words)):
      for k in range(len(words[j])):
        char = words[j][k]
        if char.upper() not in shortcuts:
          shortcuts.append(char.upper())
          newWord = words[j][:k] + f'[{char}]' + words[j][k+1:]
          newWords = words[:j] + [newWord] + words[j+1:]
          newOption = ' '.join(newWords)
          answer.append(newOption)
          flag = True
          break
        if flag: break
          

  if len(shortcuts) <= i:
    shortcuts.append("*")
    answer.append(option)

print('\n'.join(answer))