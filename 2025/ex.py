tests = int(input())

# tests = [
#     'Foulupukki mielellaan saa kirjetta. doulupukkA.',
#     'Joulupukku saapuu sinne huomenna. Joulupukke rakastaa sinua ja siskosi.'
# ]

for _ in range(tests):
    text = input().split()
    # text = text.split()
    final = []
    for word in text:
        endchar = ''
        if len(word) < 10:
            final.append(word)
            continue

        if len(word) > 11:
            final.append(word)
            continue

        if len(word) == 11:
            if word[-1] == '.':
                test = word[0:10]
                # print(test)
                endchar = '.'
            else:
                final.append(word)
                continue

        else:
            test = word
      
        if test[1:9] == 'oulupukk':
            test = 'Joulupukki' + endchar

        final.append(test)

    print(' '.join(final))
    