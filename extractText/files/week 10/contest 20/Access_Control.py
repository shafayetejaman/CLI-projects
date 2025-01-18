t = int(input())

for _ in range(t):

    n, k = map(int, input().split())
    s = input()

    cnt = 0
    flag = False

    for i in range(n):
        if s[i] == '1':
            cnt = k
        else:
            cnt -= 1

        if cnt < 0:
            flag = True

    if flag:
        print("NO")
    else:
        print("YES")
