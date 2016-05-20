#!/usr/bin/python
ans = 0
for i in range (26):
    for j in range (26):
        for k in range (26):
            if (i == 0 and j == 0):
                ans += 1
            elif (j == 0 and k == 0):
                ans += 1

print ans
