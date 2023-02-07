M, N = [int(x) for x in input().split(' ')]

word_values = {}

for _ in range(M):
    line = input().split(' ')
    word, value = line[0], int(line[1])
    word_values[word] = value

for _ in range(N):
    desc = ''
    value = 0
    line = ''

    while line != '.':
        line = input()
        desc += line + ' '
        
    for word in desc.split(' '):
        if word in word_values:
            value += word_values[word]
            
    print(value)