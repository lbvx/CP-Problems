def findBase(x, y):
    for b1 in range(2, 37):
        for b2 in range(2, 37):
            try:
                if int(x, b1) == int(y, b2):
                    return (b1, b2)
            except ValueError:
                pass
    return None

def main():
    try:
        while True:
            x, y = input().split()

            bs = findBase(x, y)
            if bs is None:
                print(f'{x} is not equal to {y} in any base 2..36')
            else:
                print(f'{x} (base {bs[0]}) = {y} (base {bs[1]})')
            
    except EOFError:
        pass

if __name__ == '__main__':
    main()
