
/*
ID: flyzorr1
PROG: numtri
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

#define MAXN 1000
typedef pair<int, string> word;

int row = 0, col = 0, id = 0,tc = 0;
char c[MAXN][MAXN], buf[MAXN];
int  d[MAXN][MAXN];

vector<word> v1, v2;
bool across(int r1, int c1)
{

	if (c[r1][c1] == '*') return false;
	return (c1 == 0) || (c[r1][c1 - 1] == '*');
}

bool down(int r1, int c1)
{
	if (c[r1][c1] == '*') return false;
	return (r1 == 0) || (c[r1 - 1][c1] == '*');
}

bool start(int r, int c)
{
	return across(r, c) || down(r, c);
}

bool across_end(int r, int c)
{
	if (d[r][c] < 0) return false;
	if (c + 1 >= col) return true;
	if (d[r][c + 1] == -1) return true;

	return false;
}

bool down_end(int r, int c)
{

	if (d[r][c] < 0) return false;
	if (r == row - 1) return true;
	if (d[r + 1][c] == -1) return true;

	return false;
}

void solve()
{
	while (scanf("%d %d\n", &row, &col) == 2 && row && col)
	{
		memset(c, 0, sizeof(c));
		REP(i, row)
		{

			cin.getline(c[i], MAXN, '\n');
		}

		id = 0;
		memset(d, 0, sizeof(d));
		REP(i, row)
			REP(j, col)
		{
			if (c[i][j] == '*') d[i][j] = -1;
			if (start(i, j)) 
				d[i][j] = ++id;
		}

		v1.clear();
		REP(i, row)
		{
			int j = 0, begin = 0,len = 0;


			REP(j, col)
			{
				if (across(i, j)) { begin = j; memset(buf, 0, sizeof(buf)); len = 0; }
				if (d[i][j] >= 0) buf[len++] = c[i][j];
				if (across_end(i, j)) { v1.push_back(MP(d[i][begin], buf)); }
			}

		}


		v2.clear();
		REP(i, col)
		{
			int j = 0, len = 0, begin = 0;


			REP(j, row)
			{
				if (down(j, i)) { begin = j; memset(buf, 0, sizeof(buf)); len = 0; }
				if (d[j][i] >= 0) { buf[len++] = c[j][i]; }
				if (down_end(j, i)) { v2.push_back(MP(d[begin][i], buf)); }
				
			}

		}

		sort(ALL(v1));
		sort(ALL(v2));

		if (tc) printf("\n");
		printf("puzzle #%d:\n", ++tc);

		printf("Across\n");
		for (auto v : v1) { printf(v.first < 10 ? "  " : " "); printf("%d.%s\n",v.first, v.second.c_str()); }
		printf("Down\n");
		for (auto v : v2) { printf(v.first < 10 ? "  " : " "); printf("%d.%s\n", v.first, v.second.c_str()); }



	}
}

int main()
{
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	solve();
	return 0;
}
