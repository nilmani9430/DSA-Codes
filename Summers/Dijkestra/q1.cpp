class Solution
{
public:
    const int N = 1e5 + 10;
    const int INF = 1e9 + 10;
    int dijkistra(int source, int n, vector<pair<int, int>> g[])
    {
        vector<int> dist(N, INF);
        vector<int> vis(N, 0);
        set<pair<int, int>> st;
        st.insert({0, source});
        dist[source] = 0;
        while (st.size() > 0)
        {
            auto node = *st.begin();
            int v = node.second;
            int v_dist = node.first;
            st.erase(st.begin());
            if (vis[v])
                continue;
            vis[v] = 1;
            for (auto child : g[v])
            {
                int child_v = child.first;
                int wt = child.second;
                if (dist[v] + wt < dist[child_v])
                {
                    dist[child_v] = dist[v] + wt;
                    st.insert({dist[child_v], child_v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INF)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> g[N];
        for (auto vec : times)
        {
            g[vec[0]].push_back({vec[1], vec[2]});
        }
        return dijkistra(k, n, g);
    }
};