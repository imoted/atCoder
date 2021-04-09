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

n = int(input())
p = list(map(str,input().split()))
q = list(map(str,input().split()))

import itertools

strn = "".join([str(c) for c in range(1,n+1)])

for i, x in enumerate(itertools.permutations(strn)):
    tmp = list(x)
    if list(x) == p:
        a = i
    if list(x) == q:
        b = i

print(abs(a-b))

