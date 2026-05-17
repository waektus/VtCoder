#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

ll to_binary(ll n){
    if(n == 0) return 0;
    ll base = 1, res = 0;
    while(n > 0){
        res += (n % 2) * base;
        base *= 10;
        n /= 2;
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    ll ans = to_binary(N);
    printf("%010d", ans);
}