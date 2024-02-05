from collections import deque

N, K = map(int,input().split())

dq = deque()
time = [0] * 100001
visited = [False] * 100001

def bfs(a):
    dq.append(a)
    while dq:
        v = dq.popleft()
        if (v == K):
            print(time[v])
            break

        for n in [v+1, v-1, 2*v]:
            if ( 0 <= n < 100001 and visited[n] == False):
                time[n] = time[v] + 1
                visited[n] = True
                dq.append(n)

bfs(N)