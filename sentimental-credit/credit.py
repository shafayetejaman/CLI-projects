while True:
    try:
        n = int(input("Number: "))
        if n >= 0:
            break
    except ValueError:
        print("not an int")

n1 = int(n % 10)
n2  = int((n % 100) / 10)
n3  = int((n % 1000) / 100)
n4  = int((n % 10000) / 1000)
n5  = int((n % 100000) / 10000)
n6  = int((n % 1000000) / 100000)
n7  = int((n % 10000000) / 1000000)
n8  = int((n % 100000000) / 10000000)
n9  = int((n % 1000000000) / 100000000)
n10 = int((n % 10000000000) / 1000000000)
n11 = int((n % 100000000000) / 10000000000)
n12 = int((n % 1000000000000) / 100000000000)
n13 = int((n % 10000000000000) / 1000000000000)
n14 = int((n % 100000000000000) / 10000000000000)
n15 = int((n % 1000000000000000) / 100000000000000)
n16 = int((n % 10000000000000000) / 1000000000000000)


n2x = int((n2 * 2) % 10) + int((n2 * 2) / 10)
n4x = int((n4 * 2) % 10) + int((n4 * 2) / 10)
n6x = int((n6 * 2) % 10) + int((n6 * 2) / 10)
n8x = int((n8 * 2) % 10) + int((n8 * 2) / 10)
n10x = int((n10 * 2) % 10) + int((n10 * 2) / 10)
n12x = int((n12 * 2) % 10) + int((n12 * 2) / 10)
n14x = int((n14 * 2) % 10) + ((n14 * 2) / 10)
n16x = int((n16 * 2) % 10) + ((n16 * 2) / 10)

sum = n1 + n2x + n3 + n4x + n5 + n6x + n7 + n8x + n9 + n10x + n11 + n12x + n13 + n14x + n15 + n16x


if sum % 10 == 0:
    if (n15 == 3 and n14 == 4) or (n15 == 3 and n14 == 7):
        print("AMEX")
    elif (n16 == 5 and n15 == 1) or (n16 == 5 and n15 == 2) or (n16 == 5 and n15 == 3) or (n16 == 5 and n15 == 4) or (n16 == 5 and n15 == 5):
        print("MASTERCARD")
    elif n13 == 4 or n16 == 4:
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
