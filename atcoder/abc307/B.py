# racecar 
def main():
    n = int(input())
    ss = []
    for _ in range(n):
        ss.append(input())

    for i in range(n):
        for j in range(n):
            if i != j:
                cc = ss[i] + ss[j]
                if cc == cc[::-1]:
                    print('Yes')
                    return
            
    print('No')

if __name__ == '__main__':
    main()
