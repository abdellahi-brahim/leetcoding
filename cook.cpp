#include <iostream>
#include <queue>
#include <vector>

using namespace std;


bool solve(int v, vector<vector<int>>adj, vector<int>color){
    queue<int> q = queue<int>();

    color[v-1] = 1;

    q.push(v);

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(int u: adj[t-1]){
            if(color[u-1] == -1){
                color[u-1] = 1 - color[t-1];
                q.push(u);
            }
            else if(color[u-1] == color[t-1])
                return false;
        }
    }
    return true;
}

int main(){

    int n, m;

    while(cin >> n >> m){
        vector<vector<int>>adj(n, vector<int>());
        vector<int>color(n, -1);
        int a, b;
        while(m--){
            cin >> a >> b;
            adj[a-1].push_back(b);
            adj[b-1].push_back(a);
        }

        bool result = true;

        for(int i = 1; i <= n; ++i){
            if(color[i] == -1){
                result = solve(i, adj, color);
                if(!result)
                    break;
            }
        }

        result?cout<<"NOT SURE"<<endl:cout<<"NO"<<endl;  
    }

    return 0;
}
