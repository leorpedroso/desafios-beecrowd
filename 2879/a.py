a = int(input())
entries = []
wins = 0

for i in range(a):
    b = input()
    entries.append(b)

for entry in entries:
    if int(entry) != 1:
        wins += 1

print(wins)