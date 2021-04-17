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

n = input()
out = n
is_yes = False
if out == out[::-1]:
    print("Yes")
    is_yes = True
else:
    for i in range(10):
        out = '0' + out
        if out == out[::-1]:
            print("Yes")
            is_yes = True
    if not is_yes:
        print("No")