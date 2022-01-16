# 入力
N = int(input())
T = list(map(int, input().split()))

S = sum(T)
# dp[i][j] := T1~Tiからいくつか選んだ和をjにすることができるか
dp = [[False] * (S + 1) for _ in range(N + 1)]
dp[0][0] = True # 1個も選ばないと　和が０

for i in range(N):
    for j in range(S + 1):
        dp[i + 1][j] |= dp[i][j]   #
        if j + T[i] <= S:          #
            dp[i + 1][j + T[i]] |= dp[i][j]

# S/2以上で最小のものを求める
for i in range((S + 1) // 2, S+1):
    if dp[N][i]:
        print(i)
        break

# 0 = {list: 26} [True, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False]
# 1 = {list: 26} [True, False, False, False, False, False, False, False, True, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False]
# 2 = {list: 26} [True, False, False, True, False, False, False, False, True, False, False, True, False, False, False, False, False, False, False, False, False, False, False, False, False, False]
# 3 = {list: 26} [True, False, False, True, False, False, False, True, True, False, True, True, False, False, False, True, False, False, True, False, False, False, False, False, False, False]
# 4 = {list: 26} [True, False, True, True, False, True, False, True, True, True, True, True, True, True, False, True, False, True, True, False, True, False, False, False, False, False]
# 5 = {list: 26} [True, False, True, True, False, True, False, True, True, True, True, True, True, True, True, True, True, True, True, False, True, False, True, True, False, True]

#  i = 0 は何も入れないので、　すべてDPは０
#  i = 1 〜5は何を入れるか？　
# 　→　i = 1は、１番目の料理を選択した時、その時間でできるか、bool
# 　→　i = 2は、１番目の料理か、２番めの料理を選択した時、その時間でできるか、ORのbool
# 　→　i = 3は、１番目の料理か、２番めか、３番目の料理ができるか、ORのbool

