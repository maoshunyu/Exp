'''
Descripttion: 
version: 
Author: Mao Shunyu
Date: 2022-07-17 14:58:39
LastEditors: Do not edit
LastEditTime: 2022-07-21 12:44:40
'''
from math import ceil
'''
msg: 计算需要几个月
param {*} a 月税后收入
param {*} b 月消费总额
param {*} c 月存款总额
param {*} d 月投资平均收益
param {*} e 目标首付款
param {*} f 年化存款利率
return {*} 需要的时间（月）
'''


def calc(a, b, c, d, e,f):
    n=0
    sum=0
    ck=0
    while(sum<=e):
        ck+=c
        sum+=a-b+d+ck*f/(12*100)
        n+=1
    return n


while(1):
    try:

        a, b, c, d, e,f = int(input("请输入月税后收入:")), int(input("请输入月消费总额:")), int(
            input("请输入月存款总额:")), int(input("请输入月投资平均收益:")), int(input("请输入目标首付款:")),float(input("请输入年化存款利率:"))
        break
    except ValueError as e:
        print("请输入正确的数值！")


month = ceil(calc(a, b, c, d, e,f))
if month < 0:
    print("凑不够！！")
else:
    year = 2021+month//12
    month = 1+month % 12
    print("可以在", year, "年", month, "月凑够首付款")
