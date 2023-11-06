
while(True):
    try:
        tag = input()
        code = int(input())
        text = input()

        #percorrer texto
        is_open = False
        final = ''
        curr = ''
        index = 0
        for c in text:
            if (not is_open) and c == '<':
                is_open = True
                index = 0

            if is_open and c == '>':
                is_open = False
                index = 0

            if is_open and (c.lower() == tag[index].lower()):
                index += 1
                curr += c
                if index == len(tag):
                    final += str(code)
                    curr = ''
                    index = 0
            else:
                curr += c
                final += curr
                index = 0
                curr = ''

        # print('RESPOSTA')
        print(final)
        
    except Exception as e:
        break
