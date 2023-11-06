words = input().split()
# words = 'Juca comprou fafarinha na memercearia e papagou 4 reais o quilo. A mamae de Juca pediu para ele comprar mamais 2 quilos.'
# words = 'O papassarinho vovoou para bem longe.'
# words = words.split()

final = []
for word in words:
    # print(word)
    if (len(word) < 4):
        final.append(word)
    
    else:
        # print(word[0:2])
        # print(word[2:4])

        if (word[0:2] == word[2:4]):
            final.append(word[2:])
        else:
            final.append(word)

# print('RESPOSTA')
print(' '.join(final))
        
