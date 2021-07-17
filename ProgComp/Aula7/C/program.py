import re


def split_words(line):
    splitted = line.split(' ')

    return (splitted)


words = []

while True:
    try:
        line = input()
        word_l = split_words(line)

        for word in word_l:
            compose = re.compile(r'[^a-z]').split(word.lower())
            if(len(compose) > 1):
                for sub in compose:
                    word_l.append(sub)
                continue
            formated = re.sub(r'[^a-z]', '', word.lower())
            if(formated != ''):
                words.append(formated)

    except EOFError:
        break
word_set = set(words)
words = list(word_set)
words.sort()
for word in words:
    print(word)
