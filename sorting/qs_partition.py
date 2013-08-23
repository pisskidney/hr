#!/usr/bin/python


def pretty_print(ar):
    print ' '.join([str(x) for x in ar])


#not in place
'''
def partition(ar):
    if len(ar) <= 1:
        return ar
    j = 1
    p = ar[0]
    for i in xrange(1, len(ar)):
        if ar[i] < p:
            ar[j], ar[i] = ar[i], ar[j]
            j += 1
    for i in xrange(0, j - 1):
        ar[i] = ar[i+1]
    ar[j - 1] = p
    return ar
'''


def partition(ar):
    if len(ar) <= 1:
        return ar
    p = ar[0]
    lesser = [x for x in ar[1:] if x <= p]
    greater = [x for x in ar[1:] if x > p]
    ar[:] = (lesser + [p] + greater)


m = input()
ar = [int(i) for i in raw_input().strip().split()]
partition(ar)
pretty_print(ar)
