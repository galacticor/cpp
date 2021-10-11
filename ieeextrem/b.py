
a = 1
b = 0
c = 0

t = []
mod = 10000
for i in range(100000):
    c = b
    b = a
    a += c % mod
    if (a%mod, c%mod) in t:
        print(i)
        break
    t.append((a%mod, c%mod))

# x = []
# a = 1
# b = 0
# c = 0
# for i in range(60):
#     c = b
#     b = a
#     a += c % 10
#     x.append(a%10)
#     # if (a%10, c%10) in t:
#     #     print(i)
#     #     break

# x = [1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1, 0]

# print (x)
