count_q = count_d = count_n = count_p = 0

def main():
    while True:
        try:
            n = float(input("Change owed: "))
            if n >= 0:
                break
        except ValueError:
            print("in dollars")
    ans = calculate(n)
    print(f"{ans}")
    return 0

def calculate(n):
    n *= 100
    q = quarter(n)
    d = dime(q)
    ni = nickel(d)
    penny(ni)

    coin = count_q + count_d + count_n + count_p
    return coin


def quarter(n):
    global count_q
    while(n >= 25):
        n -= 25
        count_q += 1
    return n


def dime(n):
    global count_d
    while(n >= 10):
        n -= 10
        count_d += 1
    return n

def nickel(n):
    global count_n
    while(n >= 5):
        n -= 5
        count_n += 1
    return n

def penny(n):
    global count_p 
    while(n >= 1):
        n -= 1
        count_p += 1
    return

main()