#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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
    int N;
    cin >> N;
    vector<int> A(N - 1), B(N - 2);
    for(int i = 0; i < N - 1; i++) cin >> A[i];
    for(int i = 0; i < N - 2; i++) cin >> B[i];

    // dp[i] := 部屋iにたどり着く最短
    vector<int> dp(N + 1, INF);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        if(0 <= i - 1) dp[i] = min(dp[i], dp[i - 1] + A[i - 1]);
        if(0 <= i - 2) dp[i] = min(dp[i], dp[i - 2] + B[i - 2]);
    }

    cout << dp[N - 1] << endl;
}