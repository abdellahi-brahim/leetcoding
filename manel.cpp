#include <iostream>
#include <vector>

int best;

void solve(int **cost, bool *active, int *link, int n, int k, int v, int c){
    if(c >= best)
        return;

    if(v == n){
        best = c;
        return;
    }

    for(int i = 0; i < n; ++i){

        if(active[i] && link[i] < k){

            for(int j = 0; j < n; ++j){

                if(!active[j]){

                    if(cost[i][j] >= 0){
                        active[j] = true;
                        link[i]++;
                        link[j]++;
                        solve(cost, active, link, n, k, v+1, c + cost[i][j]);
                        active[j] = false;
                        link[j]--;
                        link[i]--;
                    }
                }
            }
        }
    }
}

int main() {
    int n, m, k;

    while(std::cin >> n >> m >> k){   
        best = INT32_MAX;

        int **cost = new int*[n];
        for(int i = 0; i < n; ++i)
            cost[i] = new int[n];
            
        bool *active = new bool[n];
        int *link = new int[n];

        for(int i = 0; i < n; ++i){
            active[i] = false;
        }

        active[0] = true;

        for(int i = 0; i < n; ++i){
            link[i] = 0;
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cost[i][j] = -1;
            }
        }

        for(int i = 0; i < m; ++i){
            int x, y;

            std::cin >> x >> y;
            std::cin >> cost[x-1][y-1];
            cost[y-1][x-1] = cost[x-1][y-1];
        }

        solve(cost, active, link, n, k, 1, 0);
        
        if(best == INT32_MAX){
            std::cout << "NO WAY!" << std::endl;
        }
        else{
            std::cout << best << std::endl;
        }

        delete[] active;

        for(int i = 0; i < n; ++i)
            delete[] cost[i];
        delete[] cost;

        delete[] link;
    }

    return 0;
}
