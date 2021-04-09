## stringで受け取る
# a = input()
# print(a,type(a))

### listで受け取る
# a = list(input())  
# print(a,type(a))

#### int のスペース区切りをlistで受け取る
#### listの各要素に対して一定の処理を行ったモノを使いたい場合はmap関数を使います。
# a = list(map(int,input().split()))   
# print(a,type(a))

#### string のスペース区切りをlistで受け取る
# a = list(input().split())   
# print(a,type(a))

from collections import Counter
n,m = map(int,input().split())
ac_dic = Counter()
wa_dic = Counter()

ac_cnt = 0
wa_cnt = 0

for i in range(m):
    pv, sv = map(str,input().split())
    pv = int(pv)
    if sv == "WA":
        if ac_dic[pv] == 0:
            wa_dic[pv] += 1
    if sv == "AC":
        ac_dic[pv] = 1

for key, wa in wa_dic.items():
    if ac_dic[key]:
        wa_cnt += wa

for ac in ac_dic.values():
    ac_cnt += ac

print(ac_cnt, ' ', wa_cnt)


