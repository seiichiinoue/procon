#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;

int main() {
  	int n; cin >> n;
  	if (n%2==1) {
    	cout << (double)(n/2+1)/(double)n << endl;
    } else {
    	cout << 0.5 << endl;
    }
    return 0;
}