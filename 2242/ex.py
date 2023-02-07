S = input()
S = ''.join([c for c in S if c in 'aeiou'])

print('S') if S == S[::-1] else print('N')