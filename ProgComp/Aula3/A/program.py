def split_numbers(numbers):
    separated = numbers.split(' ')
    num1 = int(separated[0])
    num2 = int(separated[1])

    return num1, num2


numbers = input()
qtd_req, qtd_prop = split_numbers(numbers)
i = 0

while True:
    if(qtd_req == 0 or qtd_prop == 0):
        break

    if(i > 0):
        print()

    j = 0
    requirements = []

    while(j < qtd_req):
        req = input()
        requirements.append(req)
        j += 1

    j = 0

    prop = {'name': '', 'value': -1, 'qtd_req': -1}
    while(j < qtd_prop):
        new_name = input()
        numbers = input()
        separated = numbers.split(' ')
        new_value = float(separated[0])
        new_qtd_req = int(separated[1])
        k = 0

        while(k < new_qtd_req):
            trash = input()
            k += 1

            if(prop['name'] == ''):
                prop['name'] = new_name
                prop['value'] = new_value
                prop['qtd_req'] = new_qtd_req
                continue

            if(new_qtd_req >= prop['qtd_req']):
                if((new_qtd_req > prop['qtd_req']) or (new_value < prop['value'])):
                    prop['name'] = new_name
                    prop['value'] = new_value
                    prop['qtd_req'] = new_qtd_req

        j += 1

    print("RFP #{0}".format(i+1))
    print(prop['name'])
    numbers = input()
    qtd_req, qtd_prop = split_numbers(numbers)
    i += 1
