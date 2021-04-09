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


n,k,m = map(int,(input().split()))
a = list(map(int,input().split()))
suma = sum(a)
is_break = False
for i in range(k+1):
   if (suma + i) / n >= m:
        print(i)
        is_break = True
        break
if not is_break:
    print(-1)
