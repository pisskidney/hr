#!/usr/bin/python


def pretty_print(ar):
    print ' '.join([str(x) for x in ar])


def partition(ar, i, j):
    p = ar[0]
    lesser = [x for x in ar[i+1:j+1] if x <= p]
    greater = [x for x in ar[i+1:j+1] if x > p]
    ar[i:j+1] = (lesser + [p] + greater)
    return len(lesser) + i


def qs(ar, i, j):
    if i < j:
        r = partition(ar, i, j)
        import pdb; pdb.set_trace()
        qs(ar, i, r-1)
        qs(ar, r+1, j)


m = input()
ar = [int(i) for i in raw_input().strip().split()]
qs(ar, 0, len(ar) - 1)
pretty_print(ar)
