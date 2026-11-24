#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> graphe;
vector<bool> etat;
int total = 0;
struct cow{
    int x,y,p;
};


void dfs(int node){
    
    etat[node] = true;
    total += 1;
    for(int voisins: graphe[node]){
        if(!etat[voisins]){
            
            dfs(voisins);
        }
    }
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int rep = 0;
    int n;
    cin>>n;
    vector<cow> stat(n);
    graphe.resize(n);
    for(int i = 0; i < n; i++){
        cin>>stat[i].x>>stat[i].y>>stat[i].p;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            long long dx = stat[i].x - stat[j].x;
            long long dy = stat[i].y - stat[j].y;
            long long d_total = dx * dx + dy * dy;
            long long p_total =  1LL * stat[i].p * stat[i].p;
            if(p_total >= d_total){
                graphe[i].push_back(j);
            }
        }
    }
    etat.assign(n, false);
    for(int i = 0; i < n; i++){
        dfs(i);
        rep = max(total, rep);
        etat.assign(n, false);
        total = 0;
    }
    cout<<rep;


    

    return 0;
}