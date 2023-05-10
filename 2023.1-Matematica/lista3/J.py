def convert(x, base):
    if x == 0:
        return '0'
    res = ''
    while x > 0:
        x, r = divmod(x, base)
        if r < 10:
            res += str(r)
        elif r == 10:
            res += 'A'
        elif r == 11:
            res += 'B'
        elif r == 12:
            res += 'C'
        elif r == 13:
            res += 'D'
        elif r == 14:
            res += 'E'
        elif r == 15:
            res += 'F'

    return res[::-1]

def main():
    try:
        while True:
            b1, b2, xb1 = input().split()
            b1 = int(b1)
            b2 = int(b2)
            try:
                x = int(xb1, b1)
            except ValueError:
                print(f'{xb1} is an illegal base {b1} number')
                continue

            print(f'{xb1} base {b1} = {convert(x, b2)} base {b2}')
            
    except EOFError:
        pass

if __name__ == '__main__':
    main()
