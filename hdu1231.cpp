
/*
ID: flyzorr1
PROG:sort3
LANG: C++
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

#define MAX_NUM 99999999
int num_count = 0, sum = 0;
int nums[MAX_NUM] = { 0 };
int s[MAX_NUM] = { 0 };

int smax = 0, imax = 1, jmax = 1;

void check_max(int i,int j)
{
	if (s[j] - s[i - 1] > smax) 
	{ 
		smax = s[j] - s[i - 1]; imax = i;  jmax = j; 
	};
}

void solve(bool negative)
{
	/*int sum_max = nums[0];
	REP (i, num_count)
		REP(j, num_count) { sum = 0; for (int k = i; k <= j; k++) { sum += nums[k]; tot++; } ckmax(sum_max, sum); }*/
	//[1,num_count]
	s[0] = 0;
	smax = nums[1];
	FOR(i, 1, num_count + 1)
	{
		s[i] = s[i - 1] + nums[i]; 
	}

	if (negative) { printf("%d %d %d\n", 0, nums[1], nums[num_count]); return;}

	FOR(i, 1, num_count+1)
		FOR(j, i, num_count + 1) { check_max(i, j); }
	

	printf("%d %d %d\n", smax, nums[imax],nums[jmax]);
}


int main()
{
	/*freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);*/
	
	while (scanf("%d", &num_count) == 1 && num_count)
	{
		bool is_all_negative = true;
		FOR(i, 1, num_count + 1) { scanf("%d", &nums[i]); if (nums[i] > 0) is_all_negative = false; }
		solve(is_all_negative);
	}

	return 0;
}
