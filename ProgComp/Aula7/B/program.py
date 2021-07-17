def split_words(words):
    splitted = words.split(' ')
    if(len(splitted) > 1):
        return (splitted[0], splitted[1])

    return (splitted[0], False)


dictionary = {}
first = True

while True:
    try:
        words = input()
        (english, foreign) = split_words(words)

        if(foreign != False):
            dictionary[foreign] = english
        elif(first):
            first = False
        else:
            translate = dictionary.get(english)
            if(translate):
                print(translate)
            else:
                print("eh")

    except EOFError:
        break
