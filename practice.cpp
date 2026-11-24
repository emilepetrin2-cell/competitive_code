#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;
vector<vector<int>> graphe;
vector<bool> etat;
int maxx = 0, minx = 0, maxy = 0, miny = 0;
struct coordo{
    int x,y;
};
vector<coordo> vache;
void dfs(int debut){
    stack<int> pile;
    pile.push(debut);
    etat[debut] = true;
    maxx = vache[debut].x;
    minx = vache[debut].x;
    maxy = vache[debut].y;
    miny = vache[debut].y;
    while(!pile.empty()){
        int u = pile.top();
        pile.pop();
        for(int voisins: graphe[u]){
            if(!etat[voisins]){
                etat[voisins] = true;
                pile.push(voisins);
                int xx = vache[voisins].x;
                int yy = vache[voisins].y;
                maxx = max(maxx, xx);
                minx = min(minx, xx);
                maxy = max(maxy, yy);
                miny = min(miny, yy);
            }
        }
    }
}


int main() {
    long long rep = LLONG_MAX;
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vache.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>vache[i].x>>vache[i].y;
    }
    graphe.resize(n + 1);
    etat.assign(n + 1, false);
    for(int i = 1; i <= m; i++){
        int a,b;
        cin>>a>>b;
        graphe[a].push_back(b);
        graphe[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!etat[i]){
            dfs(i);
            long long perimetre = 2 * (maxx - minx) + 2*(maxy - miny);
            rep = min(rep, perimetre);
        }
    }
    cout<<rep;

    


    

    return 0;
}