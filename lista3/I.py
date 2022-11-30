from math import log10

sep = ['(', ')', ',', '.', ':', ';', '!', '?', '\"']

def main():
    totalWords = dict()
    words = []
    line = input()
    while line != '****END_OF_INPUT****':
        if line == '****END_OF_TEXT****':
            for w in words:
                if w in totalWords:
                    totalWords[w] += 1
                else:
                    totalWords[w] = 1

            lam = len(words)
            n = len(totalWords)

            entropy = 0.0
            entropyMax = log10(lam)
            for pi in totalWords.items():
                entropy += pi[1] * (entropyMax - log10(pi[1]))
            entropy /= lam

            print(f'{lam} {round(entropy * 10.0) / 10.0} {round(entropy / entropyMax * 100.0)}')

            words = []
            totalWords.clear()
            
        else:
            for s in sep:
                line = line.replace(s, ' ')
            words.extend([i.lower() for i in line.split()])

        line = input()

if __name__ == '__main__':
    main()
