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
s = input()
count =0
for i in range(len(s) -2):
    if s[i] == "A" and s[i+1] == "B" and s[i+2] == "C":
        count += 1

print(count)
