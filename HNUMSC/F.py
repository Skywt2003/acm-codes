n, m = map(int,input().split())

a = [0 for _ in range(n+2)]
ans = [0 for _ in range(n)]

for i in range(m):
	x, y = map(int,input().split())
	a[x] += 1
	a[y+1] -= 1

for i in range(n):
	ans[i] = ans[i-1] + a[i+1]

ans.sort()
print(ans[n//2])
