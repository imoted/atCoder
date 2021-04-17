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

is_ok = False
s0  = input()
s1  = input()
s2  = input()

dic = Counter()

for c in s0:
   dic[c] =1
for c in s1:
   dic[c] =1
for c in s2:
   dic[c] =1
sum =0
for d in dic.values():
   sum += d
if sum > 10:
   print("UNSOLVABLE")
else:
   import itertools
   s = ""
   for i in range(10):
      s += str(i)

   dic2 = {}
   dickey = list(dic.keys())

   for x in itertools.permutations(s):
      for i in range(len(dic)):
         dic2[dickey[i]] = x[i]
      n1 = ""
      n2 = ""
      n3 = ""
      for c in s0:
         n1 += dic2[c]
      for c in s1:
         n2 += dic2[c]
      for c in s2:
         n3 += dic2[c]

      if int(n1) + int(n2) == int(n3) and n1[0] != "0" and n2[0] != "0" and n3[0] != "0":
         print(n1)
         print(n2)
         print(n3)
         is_ok = True
         break

if not is_ok:
   print("UNSOLVABLE")


# pass
# for i in math.factorial(len(dic)):
#    dic2[i] +=

# for n in range( len(s1)   ):

# for c1,c2,c3 in zip( s1,s2,s3):
#     for nc1 in range( 10**len(s1) , 100**len(s1) -1):
#         if c1 == c2:
#             nc2 = nc1
#         else:
#
#         if c2 == c3:
#             nc2 = nc3
#         if c1 == c3:
#             nc3 = nc1
#         n2 += nc2
#         n3 += nc3



