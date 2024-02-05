from collections import deque

F, S, G, U, D = map(int, input().split())

# 위로 U 층
# 아래로 D층
# S에서 G으로
# 최고층은 F

time = [0] * 1000001
visited = [False] * 1000001
flag = False

def bfs(a):
    dq = deque()
    dq.append(a)

    while dq:
        v = dq.popleft()
        visited[v] = True

        if (v == G):
            flag = True
            print(time[v])
            return

        for n in [v + U, v - D]:
            if (1 <= n <= F and not visited[n]):
                time[n] = time[v]+1
                visited[n] = True
                dq.append(n)
    print("use the stairs");

bfs(S)