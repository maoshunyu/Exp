'''
Descripttion: 
version: 
Author: Mao Shunyu
Date: 2022-07-19 12:30:09
LastEditors: Do not edit
LastEditTime: 2022-07-21 12:59:54
'''
# 274926行
import linecache
import random
word = linecache.getline("hangman.txt", random.randint(1, 274926)).strip('\n')
word="success"
length=len(word)
print('_ '*length)
num = 0
cur=['_' for _ in word]
suc=False
while(num<7):
    if not cur.count('_'):
        suc=True
        break
    guess = input("请输入猜测:")
    if guess in word:
        for i,w in enumerate(word):
            if w==guess:
                cur[i]=guess
        print(' '.join(cur))
        
    else:
        print("没有这个字母")
        num += 1

print("答案是:", word)

if not suc:print("你失败了！")