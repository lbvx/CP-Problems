def check(moves:str):
    pos = [0, 0]
    for m in moves:
        if m == 'U':
            pos[1] += 1
        elif m == 'D':
            pos[1] -= 1
        elif m == 'R':
            pos[0] += 1
        elif m == 'L':
            pos[0] -= 1
        
        if pos == [1, 1]:
            return True
    return False

t = int(input())
for _ in range(t):
    input()
    moves = input()
    if check(moves):
        print('YES')
    else:
        print('NO')