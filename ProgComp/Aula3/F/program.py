qtd = int(input())
count = 0

while count < qtd:
    number = input()
    separated = number.split(' ')
    biggest = 0
    for i in separated:
        if(int(i) > biggest):
            biggest = int(i)
    print("Case {0}: {1}".format(count+1, biggest))

    count += 1
