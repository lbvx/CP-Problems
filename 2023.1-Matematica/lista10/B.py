# Stack 'em Up 
from itertools import product

SUITS = 'CDHS'
VALUES = '23456789TJQKA'

def card_str(card):
    st = ''
    if card[1] == 'T':
        st += '10'
    elif card[1] == 'J':
        st += 'Jack'
    elif card[1] == 'Q':
        st += 'Queen'
    elif card[1] == 'K':
        st += 'King'
    elif card[1] == 'A':
        st += 'Ace'
    else:
        st += card[1]

    st += ' of '
    if card[0] == 'C':
        st += 'Clubs'
    if card[0] == 'D':
        st += 'Diamonds'
    if card[0] == 'H':
        st += 'Hearts'
    if card[0] == 'S':
        st += 'Spades'

    return st

def print_deck(deck):
    for c in deck:
        print(card_str(c))
    # print()

def compare_card(card):
    return SUITS.index(card[0]) * 1000 + VALUES.index(card[1])

def create_deck():
    return list(product(SUITS, VALUES))

def main():
    t = int(input())
    input() # blank line

    for ti in range(t):
        deck = create_deck()
        deck.sort(key=compare_card)

        n = int(input())
        shuffles = []
        ni = 0
        while ni < 52*n:
            shuffles.extend([int(i) - 1 for i in input().split()])
            ni = len(shuffles)

        k = input()
        while k != '':
            k = int(k)
            
            s = shuffles[(k-1)*52:k*52]
            deck = [deck[i] for i in s]
            try:
                k = input()
            except EOFError:
                k = ''

        # print(deck)
        print_deck(deck)
        if ti != t - 1:
            print()

if __name__ == '__main__':
    main()
