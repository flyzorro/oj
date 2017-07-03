
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
#include <iterator>
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

#define MAX_NUM 10010

int nums[MAX_NUM];
int num_to_find[MAX_NUM];
int num_cnt = 0, n = 0, id = 0;
void  solve(int id)
{
	printf("CASE# %d:\n", id);
	vector<int> v(nums, nums + num_cnt);
	sort(ALL(v));
	REP(i, n)
	{
		auto iter = lower_bound(v.begin(), v.end(), num_to_find[i]);
		if (iter != v.end() && *iter == num_to_find[i]) printf("%d found at %d\n", num_to_find[i], iter - v.begin() +1 );
		else printf("%d not found\n", num_to_find[i]);
	}

}
int main()
{
	while (scanf("%d %d", &num_cnt, &n) == 2 && num_cnt && n)
	{

		memset(nums, 0, sizeof(nums));
		memset(num_to_find, 0, sizeof(num_to_find));
		REP(i, num_cnt) scanf("%d", &nums[i]);
		REP(i, n) scanf("%d", &num_to_find[i]);
		solve(++id);
	}
	return 0;
}
