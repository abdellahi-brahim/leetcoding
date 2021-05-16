from sys import stdin,stdout

inf = 99999999999

class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if len(self.queue) < 1:
            return None
        return self.queue.pop(0)

    def size(self):
        return len(self.queue)

def matrix(n):
    m = []

    for _ in range(n):
        line = []
        for _ in range(n):
            line.append(1)
        m.append(line)
    
    return m

def bfs(s, t, cap, adj):
    parent = [-1]*len(cap)

    parent[s] = -2

    q = Queue()

    q.enqueue({s, inf})

    while q.size():
        v, fv = q.dequeue()

        for u in adj[v]:
            if parent[u] == -1 and cap[v][u] > 0:
                parent[u] = v
                fu = min(fv, cap[v][u])

                if u == t:
                    return fu, parent
                
                q.enqueue((u, fu))

    return 0, parent

def max_flow(s, n, adj):
    flow_max = 0

    cap = matrix(n)

    t = n-1

    while(True):
        fp, parent = bfs(s, t, cap, adj)

        if fp <= 0:
            break
        
        flow_max += fp
        u = t

        while u != s:
            v = parent[u]
            cap[v][u] -= fp
            cap[u][v] += fp
            u = v
    
    return flow_max

def main():
    data = stdin.readlines()

    while len(data):
        m, n = map(int, data.pop(0).split(" "))

        adj = [[] for _ in range(n)]

        for _ in range(m):
            a, b = map(int, data.pop(0).split(" "))
            adj[a-1].append(b-1) 
            adj[b-1].append(a-1)

        print(max_flow(0, n, adj))

if __name__ == "__main__":
    main()