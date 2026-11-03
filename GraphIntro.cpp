#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;//int *arr;

    public:
    Graph(int V){
        this->V=V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){ //undirected graph and storing linked edges.
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdj(){
        for(int i=0;i<V; i++){
            cout<<i<<" : ";
            for(int neigh:l[i]){
                cout<<neigh<<" "; 
            }
            cout<<endl;
        }
    }

    void bfs(){//O(V+E)
        queue<int> Q;
        vector<bool> vis(V, false);

        Q.push(0);//source node
        vis[0]=true;

        while(Q.size()>0){
            int u=Q.front();
            Q.pop();
            cout<<u<<" ";
            for(int v: l[u]){
                if(!vis[v]){
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }

        cout<<endl;
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.printAdj();

    cout<<"BFS TRAVERSAL"<<endl;

    g.bfs();
    return 0;
}