
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
#pragma warning(disable:4996)

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
#define MAX_LEN 100
#define ROW 5
#define COL 5

int x_start = 0, y_start = 0, tc = 0;
char buf[MAXN][MAXN], c[MAXN], ops[MAXN];
bool all_finished = false, ops_finised = false, ops_illegal = false;

void print()
{
	REP(y, ROW)
	{
		REP(x, COL) {
			printf("%c", buf[x][y]); if (x != COL - 1) printf(" ");
		}

		printf("\n");
	}
}

bool move(char op)
{

	switch (op)
	{
	case 'A':
		if (y_start - 1 < 0) return false;
		swap(buf[x_start][y_start], buf[x_start][y_start - 1]);
		y_start = y_start - 1;
		break;
	case 'B':
		if (y_start + 1 >= ROW) return false;
		swap(buf[x_start][y_start], buf[x_start][y_start + 1]);
		y_start = y_start + 1;
		break;

	case 'R':
		if (x_start + 1 >= COL) return false;
		swap(buf[x_start][y_start], buf[x_start + 1][y_start]);

		x_start = x_start + 1;
		break;
	case 'L':
		if (x_start - 1 < 0) return false;
		swap(buf[x_start][y_start], buf[x_start - 1][y_start]);
		x_start = x_start - 1;
		break;
	case '0':
		ops_finised = true;
		break;
	default:
		return false;

	}
	return true;
}

void op()
{
	REP(i, strlen(ops)) if (!move(ops[i])) { ops_illegal = true; break; }
	return;
}

void solve()
{
	while (!all_finished)
	{
		
		ops_finised = false;
		ops_illegal = false;
		memset(buf, 0, sizeof(buf));
		REP(i, ROW)
		{
			memset(c, 0, sizeof(c));
			//scanf("%s", c);

			int len = 0;
			while (cin.getline(c, MAX_LEN))
			{
				if (strlen(c) == 0) continue;

				break;
			}
			//judge if will finsihed
			if (strlen(c) == 1 && i == 0 && c[0] == 'Z') { all_finished = true; break; }

			REP(j, COL)
			{
				buf[j][i] = ((c[j] == 0) ? ' ' : c[j]);
				if (' ' == buf[j][i]) { x_start = j; y_start = i; }
			}

		}

		printf("Puzzle #%d:\n", ++tc);
		while (scanf("%s", ops)) {
			op();
			memset(ops, 0, sizeof(ops));
			if (ops_illegal) { printf("This puzzle has no final configuration.\n");  break; }
			if (ops_finised) { print(); break; }
		}

		
	}

}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	solve();
	return 0;
}
