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

a,b,k = map(int,input().split())

if k <= a:
    print(a -k , " " ,b)
elif a < k and k <= a+b:
    print(0, " ", b-(k-a) )
else:
    print( 0 , " ", 0)