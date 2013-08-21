#!/usr/bin/python


def pretty(ar):
    return ' '.join(str(x) for x in ar)


def insertionSort(ar):
    if len(ar) == 1:
        print ar[0]
        return
    e = ar[-1]
    k = len(ar) - 2
    while k >= 0 and ar[k] > e:
        ar[k+1] = ar[k]
        k -= 1
        print pretty(ar)
    ar[k+1] = e
    print pretty(ar)
    return


m = input()
ar = [int(i) for i in raw_input().strip().split()]
insertionSort(ar)
