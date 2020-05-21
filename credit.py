from cs50 import get_int
# get number input from user then convert to string
number = str(get_int("Enter Credit Card Number: "))
# determines length
length = len(number)
multi = 0
add = 0

#for master cards
if length == 13 or length == 15:
    for i in range(1,length-1,2):
        # multiplies the number
        x2 = int(number[i])*2
        
        if (x2 / 10) >= 1:
            split = str(x2)
            multi += int(split[0]) + int(split[1])
            continue
        multi += x2
    # adds the other numbers
    for x in range(0,length,2):
        add += int(number[x])
    total = multi+add
    
# for visas
elif length == 16:
    for i in range(0,length-1,2):
        
        # multiplies the number
        x2 = int(number[i])*2
        
        if (x2 / 10) >= 1:
            split = str(x2)
            multi += int(split[0]) + int(split[1])
            continue
        multi += x2
    # adds the other numbers
    for x in range(1,length,2):

        add += int(number[x])
    total = multi+add
    
# checks the kind of card or invalid
kind = ''
if (length == 16 or length == 13) and number[0] == '4' and total % 10 == 0 :
    kind = "VISA\n"
elif length == 15 and number[0] == '3' and total % 10 == 0:
    kind = "AMEX\n"
elif length == 16 and number[0] == '5' and total % 10 == 0:
    kind = "MASTERCARD\n"
else:
    kind ="INVALID\n"
    
print(kind)
