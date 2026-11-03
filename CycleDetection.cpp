#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int V){
        this->V=V;
        l=new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdj(){
        for(int i=0;i<V;i++){
            cout<<i<<" : ";
            for(int neigh:l[i]){
                cout<<neigh<<" ";
            }

            cout<<endl;
        }
    }

    void dfsHelper(int u, vector<bool>& vis){
        cout<<u<<" ";
        vis[u]=true;
        for(int v: l[u]){
            if(!vis[v]) dfsHelper(v, vis);
        }
    }

    void dfs(){
        vector<bool> vis(V, false);
        for(int i=0;i<V;i++){//for disconnected graph we select multiple source node.
            if(!vis[i]) dfsHelper(i, vis);
        }
    }

    bool cycleDetect(int src, vector<bool>&vis, int parent){ //O(V+E)
        vis[src]=true;
        list<int> neighbors = l[src];
        for(int v:neighbors){
            if(!vis[src]){
                if(cycleDetect(v,vis,src)) return true; 
            }
            else if(v!=parent) return true;
        }

        return false;
    }

    bool directedCycle(int curr, vector<bool> &vis, vector<bool> &recPath){
        vis[curr]=true;
        recPath[curr]=true;

        for(int v:l[curr]){
            if(!vis[v]){
                if(directedCycle(v,vis,recPath)) return true;
            }
            else if(recPath[v]) return true;
        }

        recPath[curr]=false;
        return false;
    }
    
    bool cycle(){
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycleDetect(i,vis,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.printAdj();

    cout<<"DFS Traversal"<<endl;

    g.dfs();

    cout<<"\n"<<"Cycle Detection"<<endl;
    cout<<g.cycle()<<endl;
    return 0;
}