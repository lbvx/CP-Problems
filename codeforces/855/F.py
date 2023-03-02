from itertools import combinations_with_replacement

def lengthOdd(s):
    return len(s) % 2 == 1

def diffLetters(s):
    sset = set(s)
    if len(set(s)) != 25:
        return False
    
    for c in sset:
        if s.count(c) % 2 == 0:
            return False
        
    return True

def main():
    n = int(input())
    words = set()
    for _ in range(n):
        words.add(input())

    comb = combinations_with_replacement(words, 2)
    
    nightmares = 0
    for c in comb:
        s = c[0] + c[1]
        if lengthOdd(s) and diffLetters(s):
            nightmares += 1

    print(nightmares)

if __name__ == '__main__':
    main()