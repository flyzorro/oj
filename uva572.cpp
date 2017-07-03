
/*
ID: flyzorr1
PROG: numtri
LANG: C++11
*/


#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 

using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef pair<int, int> ipair;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi = acos(-1.0);
const double eps = 1e-11;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()

template<class T> T sqr(const T &x) { return x*x; }
template<class T> T lowbit(const T &x) { return (x ^ (x - 1))&x; }
template<class T> int countbit(const T &n) { return (n == 0) ? 0 : (1 + countbit(n&(n - 1))); }
template<class T> void ckmin(T &a, const T &b) { if (b<a) a = b; }
template<class T> void ckmax(T &a, const T &b) { if (b>a) a = b; }
#define MAX_NUM 110
int id = 0,  m = 0, n = 0;
char idx[MAX_NUM][MAX_NUM] = {{0,0}};
int visited[MAX_NUM][MAX_NUM] = {{0,0}};
void dfs(int r,int c, int id)
{

    if (visited[r][c]&& idx[r][c] != '@') return ;

    visited[r][c] = 1;
    idx[r][c] = id;
    FOR(i,-1,2)
        FOR(j,-1,2)
        {
            if (i == 0 && j == 0) continue;
            if (r+i >= 0 && r+i < m && c+j>=0&& c+j<n&& !visited[r+i][c+j] && idx[r+i][c+j] == '@') 
            {
                //printf("(%d,%d) visited, id=%d\n",r+i,c+j,id );
                dfs(r+i,c+j,id);
            

            }

        }
    
}
void solve()
{
    memset(idx, 0 , sizeof(idx));
    memset(visited, 0, sizeof(visited));
    id = 0;
    REP(i, m)scanf("%s", idx[i]);
    //REP(i, m){
    //    REP(j, n) printf("%c",idx[i][j]);
    //    printf("\n");
    //}
    
    REP(i, m)
        REP(j, n)
            if (idx[i][j] == '@') dfs(i, j, ++id);
               
    printf("%d\n", id);


	
}


int main()
{
//	freopen("numtri.in", "r", stdin);
//	freopen("numtri.out", "w", stdout);
//
    
    while (scanf("%d %d",&m,&n)== 2)
    {
        if (m == 0 && n == 0) break;
        solve();
    }
    //printf("m=%d,n=%d\n", m,n);
    	return 0;
}
