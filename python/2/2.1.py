'''
Descripttion: 
version: 
Author: Mao Shunyu
Date: 2022-07-20 23:36:32
LastEditors: Do not edit
LastEditTime: 2022-07-21 00:13:42
'''
# s=input("请输入字符串：").strip(' ')
# from itertools import permutations
# i=0
# for element in permutations(s):
#     a = ''.join(element)
#     #print(a)
#     i+=1
# print("有",i,"个")
s=list(input("请输入字符串：").strip(' '))
perms=[]
def perm(s:list,next:int):
    if(next==len(s)-1):
        perms.append(s)
        return
    for i,j in enumerate(s[next:]):
        _s=s[:]
        _s[next],_s[i]=_s[i],_s[next]
        perm(_s,next+1)
perm(s,0)
perms=[''.join(x) for x in perms]
i=0
for element in perms:
    #print(element)
    i+=1
print("有",i,"个")