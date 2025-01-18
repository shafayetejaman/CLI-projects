t = int(input())

for _ in range(t):

    n, _ = map(int, input().split())

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    m = max(b)

    a[n-m:] = sorted(a[n-m:]) 

    for i in a:
        print(i, end=" ")

    print()
