import decimal as d

def check(guess, op, total):
    if op == '>':
        return guess > total
    if op == '>=':
        return guess >= total
    if op == '<':
        return guess < total
    if op == '<=':
        return guess <= total
    if op == '=':
        return guess == total
    return False

def main():
    parties = {}
    operators = set([">", ">=", "<", "<=", "="])
    p, g = [int(i) for i in input().split()]

    for _ in range(p):
        name, pct = input().split()
        parties[name] = d.Decimal(pct)

    for i in range(g):
        guess = d.Decimal(0)
        line = input().split()
        for l in line:
            if l in operators:
                total = d.Decimal(line[-1])
                correct = check(guess, l, total)
                break
            elif l != '+':
                guess += d.Decimal(parties[l])

        print('Guess #', i+1, ' was ', sep='', end='')
        if correct:
            print('correct.')
        else:
            print('incorrect.')

if __name__ == '__main__':
    main()
