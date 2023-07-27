from math import sqrt

def main():
    L = int(input())    

    BHP, IVHP, EVHP = (int(i) for i in input().split())

    ss = []
    for _ in range(3):
        ss.append([int(i) for i in input().split()])

    HP = (IVHP + BHP + sqrt(EVHP) / 8 + 50) * L
    HP /= 50
    HP += 10
    HP = int(HP)

    SS = []
    for i in range(3):
        S = (ss[i][1] + ss[i][0] + sqrt(ss[i][2]) / 8) * L
        S /= 50
        S += 5
        S = int(S)
        SS.append(S)

    print(HP, *SS)

if __name__ == '__main__':
    main()