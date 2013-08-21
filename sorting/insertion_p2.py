#!/usr/bin/python


def pretty(ar):
    return ' '.join(str(x) for x in ar)


def insertionSort(ar):
    if len(ar) == 1:
        print pretty(ar)
        return
    for i in xrange(1, len(ar)):
        e = ar[i]
        k = i - 1
        while k >= 0 and ar[k] > e:
            ar[k+1] = ar[k]
            k -= 1
        ar[k+1] = e
        print pretty(ar)


m = input()
ar = [int(x) for x in raw_input().strip().split()]
insertionSort(ar)
