#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll N = 55;
const ll mo = 1e9 + 7;
const ll INF = 1e9;
struct Dinic {
    struct Edge {
        int from;
        int to;
        int flow;
    };
    vector<Edge> elist;
    vector<int> adj[N];
    int saiz;
    int ptr[N];
    int dist[N];
    int source,sink;
    int num;
    Dinic(int _s = 0,int _t = 0,int _num = 0) {
        source = _s;
        sink = _t;
        num = _num;
        reset();
    }
    void reset() {
        for(int i = 0 ; i <= num ; i++)
            adj[i].clear();
        elist.clear();
        saiz = 0;
    }
    void add_edge(int from,int to,int flow) {
        adj[from].push_back(saiz++);
        adj[to].push_back(saiz++);
        elist.push_back((Edge){from,to,flow});
        elist.push_back((Edge){to,from,0});
    }
    bool BFS() {
        for(int i = 0 ; i <= num ; i++)
            dist[i] = -1;
        queue<int> q;
        q.push(source);
        dist[source] = 0;
        while(!q.empty() && dist[sink] == -1) {
            int now = q.front();
            q.pop();
            for(int idx : adj[now]) {
                int to = elist[idx].to;
                int flow = elist[idx].flow;
 
                if(dist[to] == -1 && flow > 0) {
                    dist[to] = dist[now] + 1;
                    q.push(to);
                }
            }
        }
 
        return dist[sink] != -1;
    }
    int augment(int now,int f) {
        if(now == sink)
            return f;
        for(int &i = ptr[now] ; i < adj[now].size() ; i++) {
            int idx = adj[now][i];
            int to = elist[idx].to;
            int flow = elist[idx].flow;
            if(dist[to] == dist[now] + 1 && flow > 0) {
                int res = augment(to,min(f,flow));
                if(res > 0) {
                    elist[idx].flow -= res;
                    elist[idx ^ 1].flow += res;
                    return res;
                }
            }
        }
        return 0;
    }
    int maxFlow() {
        int mf = 0;
        while(BFS()) {
            for(int i = 0 ; i <= num ; i++)
                ptr[i] = 0;
            int add = augment(source, INF);
            while(add > 0) {
                mf += add;
                add = augment(source, INF);
            }
        }
        return mf;
    } 
};
ll solve(vector<ll> entrance, vector<ll> exits, vector<vector<ll> > path)
{
    ll n = path.size();
    Dinic dinic(n, n + 1, n + 2);
    for(auto node : entrance)
        dinic.add_edge(n, node, INF);
    for(auto node : exits)
        dinic.add_edge(node, n + 1, INF);
    for(ll i = 0; i < n; i++)
    {   
        for(ll j = 0; j < n; j++)
        { 
            dinic.add_edge(i, j, path[i][j]);
        }
    }
    return dinic.maxFlow();
}   
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<ll> entrance = {0, 1};
    vector<ll> exits = {4, 5};
    vector<vector<ll> > path = {
        {0, 0, 4, 6, 0, 0}, 
        {0, 0, 5, 2, 0, 0}, 
        {0, 0, 0, 0, 4, 4},
        {0, 0, 0, 0, 6, 6},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    cout << solve(entrance, exits, path) << "\n";
}