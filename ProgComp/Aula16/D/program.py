word = input()

cont = 0
tam = len(word)

while cont < tam:
    if(word[-1-cont::-1] != word[0:tam-cont]):
        break
    cont += 1

print(tam-cont)
