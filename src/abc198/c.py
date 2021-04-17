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

import math

r,x,y = map(int,(input().split()))

dist = math.sqrt(x**2 + y **2)
# out = -(-dist // r)
out = math.ceil(dist / r)
if dist < r:
    print(2)
else:
    print(int(out) )

