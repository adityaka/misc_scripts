
import os
import sys

def make_anagrams(a,b):
    chars_a = list(a)
    chars_b = list(b)
    chars_a.sort()
    chars_b.sort()
    number_of_deletions_a = 0
    number_of_deletions_b = 0
    seta = set(chars_a)
    setb = set(chars_b)
    char_counts_a = {c:chars_a.count(c) for c in chars_a}
    char_counts_b = {c: chars_b.count(c) for c in chars_b}
    common_chars = seta.intersection(setb)
    uncommon_chars_a = seta - setb
    uncommon_chars_b = setb - seta
    for char in common_chars:
        if char_counts_a[char] > char_counts_b[char]:
            number_of_deletions_a += char_counts_a[char] - char_counts_b[char]
        elif char_counts_b[char] > char_counts_a[char]:
            number_of_deletions_b += char_counts_b[char] - char_counts_a[char]
        else:
            pass

    for char in uncommon_chars_a:
        number_of_deletions_a += char_counts_a[char]
    for char in uncommon_chars_b:
        number_of_deletions_b += char_counts_b[char]

    return number_of_deletions_a + number_of_deletions_b

a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()
"""
Aproach : Minimum deletions from a string would the the deletion of uncommon chars in both the strings
"""
print make_anagrams(a,b)
