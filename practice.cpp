#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> liste(n);
    for (int i = 0; i < n; i++) {
        cin >> liste[i];
    }


  
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
        if (liste[i][j] == 'x' && liste[i][j + 1] == 'x') {
            cout << "Faucet " << i + 1 << "\n";
            return 0;
        }
    }
}


for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
        if (liste[i][j] == 'x' && liste[i + 1][j] == 'x') {
            cout << "Drain " << j + 1 << "\n";
            return 0;
        }
    }
}

    return 0;
}