import sys

def checkPassword(password):
  containVowel = False
  throwFlag = False

  vowel = []
  consonant = []

  for i in range(len(password)):
    curr = password[i]
    
    # 이전과 같은 글자 처리
    if (i != 0):
      if (curr == password[i-1]):
        if (curr not in ['e', 'o']):
          throwFlag = True

    # 모음/자음 연속 처리
    if (curr in ['a', 'e', 'i', 'o', 'u']): # 모음일때
      containVowel = True
      vowel.append(curr)
      if (len(vowel) >= 3): # 모음 3개 연속
        throwFlag = True
      else:
        consonant = []
    else: # 자음일때
      consonant.append(curr)
      if (len(consonant) >= 3):
        throwFlag = True
      else:
        vowel = []

  if (not containVowel or throwFlag): return False
  else: return True

while True:
  input = sys.stdin.readline().strip()
  if input == 'end':
    break
  if checkPassword(input):
    # print('<' + input.strip() + '> is acceptable.')
    print(f'<{input}> is acceptable.')
  else:
    # print('<' + input.strip() + '> is not acceptable.')
    print(f'<{input}> is not acceptable.')