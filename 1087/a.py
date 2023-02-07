while(True):

    test = [int(x) for x in input().split(' ')]
    if test == [0, 0, 0, 0]:
        exit()

    qpos_x, qpos_y = test[0], test[1]
    tpos_x, tpos_y = test[2], test[3]

    if qpos_x == tpos_x and qpos_y == tpos_y:
        print(0)

    elif qpos_x == tpos_x or qpos_y == tpos_y:
        print(1)

    # check diagonal
    elif abs(tpos_x - qpos_x) == abs(tpos_y - qpos_y):
        print(1)

    else:
        print(2)