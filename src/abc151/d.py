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

xa = [ -1 , 0 , 1,  0]
ya = [ 0 , -1 , 0 , 1]
#
# def dfs(x, y, ans):
#     if x < 0 or w < x or y < 0 or h < y:
#         return ans
#     if s[y][x] == "#":
#         return ans
#     for dx, dy in zip(xa, ya):
#         x += dx
#         y += dy
#         ans = max(ans, dfs(x, y, ans) +1 )

h,w = map(int,input().split())
s = []
for i in range(h):
    s.append(input())

x = 0
y = 0
ans = 0

for y in range(h):
    for x in range(w):

        pos = []
        pos.append([x, y])
        dist = [[10e10] * w] * h
        dist[y][x] = 0
        while len(pos) > 0: #探索可能ならTrue
            tx, ty = pos.pop(0)  #リストから探索する位置を取得
            for dx, dy in zip(xa, ya):
                tx += dx
                ty += dy
                if tx < 0 or w <= tx or ty < 0 or h <= ty:
                    continue
                if s[ty][tx] == "#":
                    continue
                if dist[ty][tx] == 10e10:
                    continue
                pos.append([tx, ty])
                dist[ty][tx] = dist[ty - dy][tx - dx] +1

        for y in h:
            for x in w:
                if dist[y][x] == 10e10:
                    continue
                ans = max(ans,dist[y][x])
print(ans)
