def main():
    r, v = (float(i) for i in input().split())
    i, j = (float(i) for i in input().split())

    semanas = 0
    v_poupanca = 0.0
    v_carro = v
    while semanas <= 52 * 70 and v_poupanca < v_carro:
        semanas += 1
        v_poupanca *= 1.0 + i / 100.0
        v_poupanca += r
        v_carro *= 1 - j / 100.0

    print(semanas if semanas <= 52 * 70 else -1)

if __name__ == '__main__':
    main()