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


def f(x):
    res = 0
    while x%2 == 0:
        x /=2
        res +=1
    return 1

def func():
    n,m = map(int,input().split())
    a = list(map(int,input().split()))

    # a -> a'
    for av in a:
        if av %2 == 1:
            print(0)
            return
        av /= 2

    # a -> a''
    t = f(a[0])
    for av in a:
        if f(av) != t:
            print(0)
            return
        av >>= t # 2でT回割る   av /= 2^t
    m >>= t

    l = 1
    for av in a:
        l = math.lcm(l, av)
        if l > m:
            print(0)
            return

    m /= l
    ans = (m +1) /2
    print(ans)
    return

if __name__ == '__main__':
    func()
