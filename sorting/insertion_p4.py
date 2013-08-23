#!/usr/bin/python


def insertionSort(ar):
    shifts = 0
    if len(ar) == 1:
        print shifts
        return
    for i in xrange(1, len(ar)):
        e = ar[i]
        k = i - 1
        while k >= 0 and ar[k] > e:
            ar[k+1] = ar[k]
            k -= 1
            shifts += 1
        ar[k+1] = e
    print shifts


m = input()
ar = [int(x) for x in raw_input().strip().split()]
insertionSort(ar)
