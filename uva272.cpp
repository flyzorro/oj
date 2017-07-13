
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
#include <iterator>
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
#define INS(a) inserter((a),(a).begin())

template<class T> T sqr(const T &x) { return x*x; }
template<class T> T lowbit(const T &x) { return (x ^ (x - 1))&x; }
template<class T> int countbit(const T &n) { return (n == 0) ? 0 : (1 + countbit(n&(n - 1))); }
template<class T> void ckmin(T &a, const T &b) { if (b<a) a = b; }
template<class T> void ckmax(T &a, const T &b) { if (b>a) a = b; }

#define MAX_N 10000
char s[MAX_N] = { '\0' };
void solve()
{
	char c;
	int start = 1, pos = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			s[pos++] = c;
			printf("%s", s);
			pos = 0;
			memset(s, '\0', sizeof(s));
			continue;
		}

		if (c == '"')
		{
			char c1 = start ? '`' : '\'';
			s[pos] = s[pos + 1] = c1;
			start = !start;
			pos += 2;
			continue;
		}

		s[pos++] = c;

	}
}


int main()
{
	freopen("test.in", "rb", stdin);
	freopen("test.out", "wb", stdout);

	solve();
	return 0;
}
