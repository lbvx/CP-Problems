GUESS_LIMIT = 7

def solve(solution, guess):
    sol_set = set(solution)
    right_set = set()
    wrong_set = set()
    for c in guess:
        if c in sol_set:
            right_set.add(c)
        else:
            wrong_set.add(c)

        if len(wrong_set) == GUESS_LIMIT:
            return -1
        
        if len(right_set) == len(sol_set):
            return 1

    return 0

def main():
    round = int(input())
    while round != -1:
        solution = input()
        guess = input()

        res = solve(solution, guess)
        print('Round', round)
        if res == 1:
            print('You win.')
        elif res == 0:
            print('You chickened out.')
        else:
            print('You lose.')

        round = int(input())

if __name__ == '__main__':
    main()
