def main():
    try:
        while (True):
            line = input()
            ans = []
            pancakes = [int(e) for e in line.split()]
            original = pancakes.copy()
            order = pancakes.copy()
            order.sort()
            while order:
                maior = order.pop()
                pos = pancakes.index(maior)
                if pos != len(order):
                    if not pos == 0:
                        pancakes[0:pos+1] = pancakes[0:pos+1][::-1]
                        ans.append(len(pancakes) - pos)
                        # print(pancakes)
                    pancakes[0:len(order)+1] = pancakes[0:len(order)+1][::-1]
                    ans.append(len(pancakes) - len(order))
                    # print(pancakes)
            
            ans.append(0)
            # print(ans)
            [print(i, end=' ') for i in original]
            print()
            [print(i, end=' ') for i in ans]
            print()

    except EOFError:
        pass

if __name__ == '__main__':
    main()
