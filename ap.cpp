#include<iostream>
#include <list>
#include <sstream>

#define NIL -1

using namespace std;
 
class Graph{
    int V;   
    list<int> *adj;  
    void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    int AP();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v); 
}

void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]){
    static int time = 0;
 
    int children = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;
 
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;
        if (!visited[v]){
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);
 
            low[u]  = min(low[u], low[v]);

            if (parent[u] == NIL && children > 1)
               ap[u] = true;
 
            if (parent[u] != NIL && low[v] >= disc[u])
               ap[u] = true;
        }
 
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
int Graph::AP(){
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V]; 
 
    for (int i = 0; i < V; i++){
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }
 
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);
    
    int points = 0;

    for (int i = 0; i < V; i++)
        if (ap[i] == true)
            points++;
    
    return points;
}
 

int main(){
    int nodes;
    while(cin >> nodes && nodes){
        Graph g(nodes);

        string buffer;

        while(getline(cin, buffer) && buffer != "0"){
            if(buffer.size() == 0) continue;

            stringstream in(buffer);

            int index, next;
            in >> index;

            while(in >> next){
                g.addEdge(index-1, next-1);
            }
        }

        cout << g.AP() << endl;
    }
    return 0;
}
