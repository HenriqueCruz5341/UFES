qtd = int(input())
count = 0

while (count < qtd):
    numbers = input()
    separated = numbers.split(' ')
    num1 = int(separated[0])
    num2 = int(separated[1])

    if(num1 == num2):
        print('=')
    elif(num1 < num2):
        print('<')
    elif(num1 > num2):
        print('>')

    count += 1
