import heapq

INF = int(1e18)

n, m = map(int, input().split())
adjList = [[] for i in range(n)]
edges = []
for i in range(m):
    a, b, d, c = map(int, input().split())
    edges.append((d, c, a-1, b-1)) # change to sorting order
edges.sort()

def dijkstra(a, b):
    dis = [INF]*n
    dis[a] = 0
    pq = [(0, a)]

    while pq:
        d1, n1 = heapq.heappop(pq)
        if d1 != dis[n1]: continue

        for n2, d in adjList[n1]:
            d2 = d1+d
            if d2 < dis[n2]:
                dis[n2] = d2
                heapq.heappush(pq, (d2, n2))

    return dis[b]

ans = 0
for d, c, a, b in edges:
    if d < dijkstra(a, b):
        adjList[a].append((b, d))
        adjList[b].append((a, d))
        ans += c

print(ans)
