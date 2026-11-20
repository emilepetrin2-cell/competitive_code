#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_map>
using namespace std;
vector<vector<int>> a(5 + 1);
vector<bool> visiter(6, false);
int total = 0;
void dfs(int nodes){
    visiter[nodes] = true;
    for(int voisins: a[nodes]){
        if(!visiter[voisins]){
            dfs(voisins);
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    a[1].push_back(2);
    a[2].push_back(1);
    a[3].push_back(4);
    a[4].push_back(3);
    
    for(int i = 1; i < 6; i++){
        if(!visiter[i]){
            dfs(i);
            total += 1;
        }
    }

    cout<<total;
    
    return 0;
}
