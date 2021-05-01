#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef pair<int,unsigned long long> PII;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;

int solve(int source_node, int node_count, int dst_node, VVPII& graph) {
    const long long INF = 999999999999;
    vector<unsigned long long> dist(node_count, INF);
    set<PII> set_length_node;
    
    dist[source_node] = 0;
    set_length_node.insert(PII(0,source_node));

    while (!set_length_node.empty()) {

        PII top = *set_length_node.begin();
        set_length_node.erase(set_length_node.begin());

        int current_source_node = top.second;

        for (auto& it : graph[current_source_node]) {

            int adj_node = it.first;
            int length_to_adjnode = it.second;
    
            if (dist[adj_node] > length_to_adjnode + dist[current_source_node]) {
    
                if (dist[adj_node] != INF) {
                   set_length_node.erase(set_length_node.find(PII(dist[adj_node],adj_node))); 
                }
                dist[adj_node] = length_to_adjnode + dist[current_source_node];
                set_length_node.insert(PII(dist[adj_node], adj_node));
            }
        }
    }   

    return dist[dst_node];
}

int main(){
    int places, dst;

    while(cin >> places >> dst){
        vector<VPII> graph;

        for(int i = 0; i < places; ++i){
            int id;
            cin >> id;
            VPII v;
            for(int j = 0; j < places; ++j){
                int weight;
                cin >> weight;
                if(weight != -1){
                    v.push_back({j, weight});
                }
            }
            graph.push_back(v);
        }

        cout << solve(0, places, dst-1, graph) << endl;
    }
}
