def countMin(string):
    if string != '' and\
       ((string[0] == '0' and string[-1] == '1') or\
       (string[0] == '1' and string[-1] == '0')):
       return countMin(string[1:-1])
    
    return len(string)

t = int(input())
for _ in range(t):
    input()
    string = input()
    print(countMin(string))