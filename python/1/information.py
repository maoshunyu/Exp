'''
Descripttion: 
version: 
Author: Mao Shunyu
Date: 2022-07-20 16:35:32
LastEditors: Do not edit
LastEditTime: 2022-07-20 19:50:53
'''
from __future__ import annotations
import linecache
import numpy as np
from math import log2, exp
from rich.console import Console
import json


def sigmoid(x):
    return (1/(1+exp(-x)))


fr = open("freq.json", "r")
data: dict[str, int] = json.loads(fr.read())
fr.close()

word_list = data.keys()
freq = data.values()

r = zip(*sorted(zip(word_list, freq), key=lambda x: x[1]))
sorted_word_list, sorted_freq = [list(x) for x in r]

TOTAL = len(word_list)
hx = []

x_width = 10
c = x_width * (-0.5 + 3000 / len(word_list))
xs = np.linspace(c - x_width / 2, c + x_width / 2, len(word_list))
priors = dict()
for word, x in zip(sorted_word_list, xs):
    priors[word] = sigmoid(x)
hx = [float(i.strip('\n')) for i in linecache.getlines('information.txt')]


def get_pattern(a: str, b: str) -> tuple(str, float):
    outcome = []
    for i, my in enumerate(a):
        if(b[i] == my):
            outcome.append('2')
        elif(my in b):
            outcome.append('3')
        else:
            outcome.append('0')
    return ''.join(outcome),


def check_pattern(pat: str, ans: str, words: list[str], ent: list[float]):
    l = []
    hx = []
    for i, word in enumerate(words):
        ok = True
        for j, s in enumerate(pat):
            if(not ((s == '0' and (ans[j] not in word)) or (s == '2' and (ans[j] == word[j])) or (s == '3' and (ans[j]!=word[j])and(ans[j] in word)))):
                ok = False
                break
        if ok:
            l.append(word)
            hx.append(ent[i])
    return (l, hx)




#######################################################
# num = 0
# sum = sum(priors.values())
# for k, v in priors.items():
#     priors[k] = priors[k]/sum
# for word in word_list:
#     patterns = {}
#     for p in word_list:
#         pat = get_pattern(word, p)
#         if pat in patterns:
#             patterns[pat] += priors[p]
#         else:
#             patterns[pat] = priors[p]
#     sum = 0
#     for k, v in patterns.items():
#         sum += (-v)*log2(v)
#     hx.append(sum)
#     num += 1
#     if(num % 100 == 0):
#         print(num)
# for i in hx:
#     f.write(str(i)+'\n')


# Console.print(sorted_word_list)
# Console.print(hx)
# f.close()
#################################################
