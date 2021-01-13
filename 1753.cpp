#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define N first
#define D second
using namespace std;

// less weight edge go top  
struct cmp
{
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        return a.D > b.D;
    }
};

vector<pair<int, int>> edges[20001];
int dist[20001];

int main(void)
{
    int V, E, K;
    scanf(" %d %d", &V, &E);
    scanf(" %d", &K);
    for (int i = 0; i < E; i++)
    {
        int u, v, w; // start, end, weight
        scanf(" %d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});  // edge u to v has w weight
    }
    for (int i = 1; i <= V; i++)
        dist[i] = 0x7fffffff;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({K, 0});
    dist[K] = 0;
    while (!pq.empty())
    {
        pair<int, int> cur = pq.top(); pq.pop();
        if (dist[cur.N] < cur.D) continue;
        
        for (int i = 0; i < edges[cur.N].size(); i++)
        {
            int distance = dist[cur.N] + edges[cur.N][i].D;
            if (distance < dist[edges[cur.N][i].N])
            {
                pq.push({edges[cur.N][i].N, distance});
                dist[edges[cur.N][i].N] = distance;
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == 0x7fffffff)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
    return 0;
}
