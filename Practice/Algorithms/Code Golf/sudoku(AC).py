bl=r=c=bk=suc=0
F=False
T=True
def m2d(n,m,v):
 return [[v for j in xrange(m)] for i in xrange(n)]
def dfs(a,idx):
 global suc,bl,r,c,bk
 if suc:
  return
 if idx==len(bl):
  suc=T
  return
 x=bl[idx]/9
 y=bl[idx]%9
 for i in xrange(9):
  if r[x][i] or c[y][i] or bk[x/3*3+y/3][i]:
   continue
  r[x][i]=c[y][i]=bk[x/3*3+y/3][i]=T
  a[x][y]=i+1
  dfs(a,idx+1)
  if suc:
   return
  a[x][y]=0
  r[x][i]=c[y][i]=bk[x/3*3+y/3][i]=F
def fun(a):
 global suc,bl,r,c,bk
 bl=[]
 r=m2d(9,9,F)
 c=m2d(9,9,F)
 bk=m2d(9,9,F)
 for i in xrange(81):
  x=i/9
  y=i%9
  v=a[x][y]
  if v>0:
   r[x][v-1]=T
   c[y][v-1]=T
   bk[x/3*3+y/3][v-1]=T
  else:
   bl.append(i)
 suc=F
 dfs(a,0)
 for i in xrange(9):
  print(' '.join(map(str,a[i])))
t=input()
for ti in range(t):
 a=[]
 for j in range(9):
  a.append(map(int, raw_input().split()))
 fun(a)
