#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W, N;
    cin >> H >> W >> N;

    vector imos(H + 1, vector<int>(W + 1));
    for(int i = 0; i < N; i++){
        int A, B, C, D; cin >> A >> B >> C >> D, A--, B--;
        imos[A][B]++;
        imos[A][D]--;
        imos[C][B]--;
        imos[C][D]++;
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            imos[i][j + 1] += imos[i][j];
        }
    }
    for(int j = 0; j < W; j++){
        for(int i = 0; i < H; i++){
            imos[i + 1][j] += imos[i][j];
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << imos[i][j] << " ";
        }
        cout << endl;
    }
}