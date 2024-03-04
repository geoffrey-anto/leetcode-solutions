class Solution:
    def minimumOperations(self, num: str) -> int:
        v = [
            [5, 2],
            [0, 5],
            [5, 7],
            [0, 0]
        ]

        if len(num) == 1:
            return 0 if num[0] == '0' else 1

        n = len(num)
        i1, i2, i3, i4 = 0, 0, 0, 0

        for i in range(n - 1, -1, -1):
            if v[0][i1] == int(num[i]):
                i1 += 1

            if v[1][i2] == int(num[i]):
                i2 += 1

            if v[2][i3] == int(num[i]):
                i3 += 1

            if v[3][i4] == int(num[i]):
                i4 += 1

            if len(v[0]) == i1:
                return n - i - i1

            if len(v[1]) == i2:
                return n - i - i2

            if len(v[2]) == i3:
                return n - i - i3

            if len(v[3]) == i4:
                return n - i - i4

        return n - num.count('0')
