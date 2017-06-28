
/*
ID: flyzorr1
PROG:sort3
LANG: C++
*/

#pragma warning(disable:4996)

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

struct node
{
	int l, r, sum;
	node() {};
	node(int x, int y, int z) :l(x), r(y), sum(z) {};

};

node cal_max_nums(int x, int y)
{
	if (y - x == 1) return  node(x,y, nums[x]);
	int mid = x + (y - x) / 2;

	//[i,j)
	node x_mid = cal_max_nums(x, mid);
	node mid_y = cal_max_nums(mid, y);
	node max_half = x_mid.sum > mid_y.sum ? x_mid : mid_y;
	//cal from mid for maxl
	int lsum = 0, lmax = nums[mid - 1], l = mid - 1;
	for (int i = mid - 1; i >= x; i--) 
	{ 
		lsum += nums[i]; 
		if (lsum > lmax) { lmax = lsum; l = i; }
	}
	int rsum = 0, rmax = nums[mid], r = mid;
	for (int i = mid; i < y; i++) 
	{ 
		rsum += nums[i]; 
		if (rsum > rmax) { rmax = rsum; r = i; };
	};

	if (max_half.sum > lmax + rmax) return max_half;

	return node(l,r,lmax+rmax);
	


}

void solve(bool negative)
{
	if (negative) { printf("%d %d %d\n", 0, nums[0], nums[num_count-1]); return; }


	node n = cal_max_nums(0, num_count);

	printf("%d %d %d\n", n.sum, nums[n.l], nums[n.r]);
}


int main()
{
	/*freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);*/

	while (scanf("%d", &num_count) == 1 && num_count)
	{
		bool is_all_negative = true;
		FOR(i, 0, num_count) { scanf("%d", &nums[i]); if (nums[i] > 0) is_all_negative = false; }
		solve(is_all_negative);
	}

	return 0;
}
