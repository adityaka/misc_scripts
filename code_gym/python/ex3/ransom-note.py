from collections import defaultdict

def ransom_note(magazine, ransom):
    result = True
    word_counts_magazine  = defaultdict()

    return result


m, n = map(int, raw_input().strip().split(' '))
magazine = raw_input().strip().split(' ')
ransom = raw_input().strip().split(' ')
answer = ransom_note(magazine, ransom)
if (answer):
    print "Yes"
else:
    print "No"