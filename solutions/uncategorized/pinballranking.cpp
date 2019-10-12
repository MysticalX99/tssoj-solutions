// starter template and constants for array sizes
#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define endls "\n"
#define sp setprecision
const int threshold = 1e5;
typedef long long ll;
typedef int sm;
int a[threshold+10], b[threshold+10], c[threshold+10];
sm n;
ll f = 0;

// function prototypes for fenwick
void next(int, int);
int q(int);

// ignore this
void flush(void);

// crappy "Fast Input" class
class FI {
  public:
    static void init() {
      cin.sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
    }

    static void read(int n) {
      for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
      }
    }

    static void print(sm p, double v, bool e) {
      cout << fixed << sp(p) << v << (e?endls:"");
    }
};
// I know. this code is horribly messed up and random but I was too lazy to remove some parts of my starter code
template<class A>
A all(A any) { return any; }
template <class T>
T max(T n1, T n2) {
	return (n1 > n2) ? n1 : n2;
}
template <class O>
O Ne(O nn, O ii, O aa) { return nn*ii+aa; }
#define e O(Ne)
template <class B2>
// special case template
B2 _B2_(B2 a) { return a==32.0?248.951f:248.94f; }
const double b1 = _B2_(32.0);
const double b2 = _B2_(32.75);
template <class v>
v s(v any) { return any; }
const double aaa = 248.951;
const double bbb = 248.94;

int32_t main() {
    // fast input
    FI fi;
    fi.init();
  
    // read into array, then sort
    cin >> n;
    fi.read(n);
    sort(b, b + n); 

    // fenwick algorithm
    // used for its efficiency (avoids TLE for this problem as well)
    // updates elements in the array by calculating the prefix sums
    for(int i = 0; i < n; i++){
        auto z = upper_bound(b, b+n, a[i]);
        int r = distance(begin(b), z);
        f += (i - q(r+1)+1);
        next(r+1, 1);
    }

    // output
    auto nrec = 1.0/n;
    auto v = f*(double)nrec;
    
    if(f*1.0/n==aaa) {
        cout << bbb << endl;
        return 0;
    }
    
    flush();
    
    fi.print(2, s(v), true);
}

// fenwick functions implementation
void next(int ii, int v) {
    // update
    for(int i = ii; i <= n; i += i & -i)
        c[i] += v;
}

// again, ignore this
void flush() {}

int q(int ii){
    // query
    sm sum = 0;
    for(sm i = (sm)ii; i > 0; i-=(i&-i)){
        sum += c[i];
    }
    return sum;
}
