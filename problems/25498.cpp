#include <bits/stdc++.h>
using namespace std;

class my
{
private:
int N;
string A;
vector<vector<int>> EDGE;
public:
my(){
    cin>>N;
    cin>>A;
    EDGE.assign(N, vector<int>());
    for(int i = 1;i<N;i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        EDGE[u].push_back(v);
        EDGE[v].push_back(u);
    }
}
void Ution(){
    vector<bool> visit(N, false);
    visit[0] = true;
    Handle(vector<int>(1, 0), visit);
}
void Handle(vector<int> nodes, vector<bool> &visit){
    if(nodes.empty())return;
    cout<<A[nodes[0]];
    char max_char = 'a'-1;
    for(auto node:nodes){
        for(auto next_node:EDGE[node]){
            if(visit[next_node])continue;
            max_char = max(max_char, A[next_node]);
        }
    }
    if(max_char=='a'-1)return;
    vector<int> next_nodes;
    for(auto node:nodes){
        for(auto next_node:EDGE[node]){
            if(visit[next_node])continue;
            if(A[next_node]==max_char)next_nodes.push_back(next_node);
            visit[next_node] = true;
        }
    }
    Handle(next_nodes, visit);
}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    my sol;
    sol.Ution();
    
    return 0;
}