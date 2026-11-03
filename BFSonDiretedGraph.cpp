#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int V){
        this->V=V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){ //to make directed graph we can just keep l[u].push_back(v);
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printG(){
        for(int i=0;i<V; i++){
            cout<<i<<" : ";
            for(int neigh:l[i]){
                cout<<neigh<<" "; 
            }
            cout<<endl;
        }
    }

    void bfs(){
        queue<int> Q;
        vector<bool> vis(V, false);

        Q.push(0);
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

    bool cycleDetect(int src, vector<bool>&vis){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src]=true;

        while(!q.empty()){
            int u=q.front().first;
            int parent=q.front().second;
            for(int neigh: l[u]){
                if(!vis[neigh]){
                    q.push({neigh, u});
                    vis[neigh]=true;
                }
                else if( neigh!=parent) return true;// mtlb agr neigh visited hai but uska parent abhi jo current node hai usse match nhi kr raha iska mtlb Back edge (loop) hai.
            }
            q.pop();
        }
        return false;
    }

    bool cycle(){
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycleDetect(i,vis)){
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

    g.printG();

    cout<<"BFS Traversal"<<endl;

    g.bfs();

    cout<<"BFS Cycle detection"<<endl;
    cout<<g.cycle()<<endl;
    return 0;
}