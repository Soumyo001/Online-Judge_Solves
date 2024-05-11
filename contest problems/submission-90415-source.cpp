#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace:: std;
using namespace:: __gnu_pbds;

#define READ                                 freopen("in.txt", "r", stdin)
#define WRITE                                freopen("out.txt", "w", stdout)

#define FAST                                 ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)


#define All(v)                               v.begin(), v.end()
#define SZ(a)                                a.size()
#define Sort(v)                              sort(All(v))
#define ED(v)                                Sort(v), v.erase(unique(All(v), v.end())
#define Common(a, b)                         Sort(v), Sort(b), a.erase(set_intesection(All(a), All(b), a.begin(), a.end()))
#define UnCommon(a, b)                       Sort(v), Sort(b), a.erase(set_symmetric_difference(All(a), All(b), All(a)))


#define max3(a, b, c)                        max(a, max(b, c))
#define min3(a, b, c)                        min(a, min(b, c))
#define maxAll(v)                            *max_element(All(v))
#define minAll(v)                            *min_element(All(v))


#define AllUpper(a)                          transform(All(a), a.begin(), :: toupper)
#define AllLower(a)                          transform(All(a), a.begin(), :: tolower)
#define Rev(a)                               reverse(All(a))



#define memo(a, b)                           memset(a, b, sizeof(a))

#define ff                                   first
#define ss                                   second
#define PII                                  pair <int, int>

#define inf                                  1 << 28

template <typename T>string toString (T Number)    { stringstream st; st << Number; return st.str(); }
int toInteger (string s)                           { int p; istringstream st(s); st>>p ; return p; }
int Set(int N, int pos)                            { return N = N | (1 << pos); }
int Reset(int N, int pos)                          { return N = N & ~(1 << pos); }
bool Check(int N, int pos)                         { return (bool)(N & (1 << pos)); }


//int dr[] = {1, -1, 0, 0};                // 4 Direction
//int dc[] = {0, 0, 1, -1};

//int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};  // 8 Direction
//int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};

//int dr[] = {-1, 1, -2, -2, -1, 1, 2, 2}; // knight Moves
//int dc[] = {-2, -2, -1, 1, 2, 2, 1, -1};


#define Exp                                  exp(1.0)
#define PIE                                  2*acos(0.0)
#define Sin(a)                               sin(((a)*PI)/180.0)
#define mod                                  1000000007
#define EPS                                  1e-9

#define sqr(a)                               ((a)*(a))
#define gcd(a,b)                              __gcd(a,b)
#define lcm(a,b)                             (a*(b/gcd(a,b)))


#define trace1(x)                           cerr << #x << ": " << x << endl;
#define trace2(x, y)                        cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)                     cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)                  cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)               cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)            cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;


typedef long long                            ll;
typedef vector <int>                         VII;
typedef vector <ll>                          VLL;

#define PB                                   push_back
#define MK                                   make_pair


inline int nxtINT()                            { int a; scanf("%d", &a); return a; }
inline int nxtLL()                             { ll a; scanf("%lld", &a); return a; }
inline int nxtDD()                             { double a; scanf("%lf", &a); return a; }

#define PF                                   printf
#define PFTC1(t)                             printf("Case %d: ", t)
#define PFTC2(t)                             printf("Case #%d: ", t)
#define PFII(n)                              printf("%d", n)
#define PFLL(n)                              printf("%lld", n)

#define NEWLINE                              puts("")

static const int mx = 100000 + 5;
static const int MAXN = 1e6 + 5;
static const int MAXLG = 15;


int main()
{
    //READ;


    int tc = nxtINT();

    for (int tcase = 1; tcase <= tc; tcase++)
    {
        int N = nxtINT();

        PFTC1(tcase);

        if (N == 1 or N == 2)
        {
            PF("Tie"); NEWLINE;
        }

        else if (N & 1)
        {
            PF("CodeNewtons"); NEWLINE;
        }

        else
        {
            PF("CodeMask"); NEWLINE;
        }
    }
}
