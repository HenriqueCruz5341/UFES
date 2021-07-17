# Don't work :(

def split_numbers(numbers):
    splitted = numbers.split(' ')

    return (splitted[0], splitted[1:])


n_tests = int(input())
count = 0

while count < n_tests:
    print("Case {0}:".format(count+1), end="")
    n_friends = int(input())
    count_friends = 0
    friends = []

    while count_friends < n_friends:
        numbers = input()
        (n_stamps, stamps) = split_numbers(numbers)
        friend = {"id": count_friends, "n_stamps": n_stamps,
                  "stamps": set(stamps), "uniques": 0}
        friends.append(friend)
        count_friends += 1

    uniques = []
    for i in range(51):
        uniques.append(0)

    for friend in friends:
        flag = True
        common = set()
        for friend1 in friends:
            if(friend['id'] != friend1['id']):
                if(flag):
                    common = friend['stamps'] - friend1['stamps']
                    flag = False
                elif(not flag):
                    common = common - friend1['stamps']

        friend['uniques'] = len(common)
        uniques[len(common)] += 1

    print("(AMX: {0})".format(n_stamps))
    for friend in friends:
        print("(QTD: {0})".format(friend['uniques']), end=" - ")
        percent = (friend['uniques'] / int(n_stamps))*100
        print(" {0}%".format(percent), end="")

    print()

    count += 1
