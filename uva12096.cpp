
/*
ID: flyzorr1
PROG: numtri
LANG: C++11
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
template<class T> void ckmin(T &a, const T &b) { if (b < a) a = b; }
template<class T> void ckmax(T &a, const T &b) { if (b > a) a = b; }

#define MAX_N 100

enum COMMANDS
{
	PUSH = 1,
	DUP = 2,
	ADD = 3,
	INTERSECT = 4,
	UNION = 5
};

int tcs = 0, ops = 0;
char cmds[MAX_N] = { 0 };

typedef set<int> SI;
vector<SI> IDCache;
map<SI, int> SetCache;
stack<int> stacks;
int set_cache(SI si)
{
	if (SetCache.count(si) == 0) { IDCache.push_back(si); SetCache[si] = IDCache.size() - 1; return IDCache.size() - 1; }

	return SetCache[si];
}

void print()
{
	if (stacks.empty()) return;
	printf("%d\n", (int)IDCache[stacks.top()].size());
}


void push()
{
	SI si;
	stacks.push(set_cache(si));
}

void dup()
{
	if (stacks.empty()) return;
	stacks.push(stacks.top());
}

void ops_add()
{

	SI l, r;
	if (stacks.size() < 2) return;
	l = IDCache[stacks.top()];
	stacks.pop();
	r = IDCache[stacks.top()];
	stacks.pop();

	SI si = r;
	si.insert(set_cache(l));
	stacks.push(set_cache(si));

}

void ops_union()
{
	SI l, r;
	if (stacks.size() < 2) return;
	l = IDCache[stacks.top()];
	stacks.pop();
	r = IDCache[stacks.top()];
	stacks.pop();

	SI si;
	set_union(ALL(l), ALL(r), inserter(si, si.begin()));

	stacks.push(set_cache(si));
}

void ops_intersect()
{
	SI l, r;
	if (stacks.size() < 2) return;
	l = IDCache[stacks.top()];
	stacks.pop();
	r = IDCache[stacks.top()];
	stacks.pop();

	SI si;
	set_intersection(ALL(l), ALL(r), inserter(si, si.begin()));

	stacks.push(set_cache(si));
}

COMMANDS parseCmd(char* cmds)
{

	if (strcmp(cmds, "PUSH") == 0) return PUSH;
	if (strcmp(cmds, "ADD") == 0) return ADD;
	if (strcmp(cmds, "DUP") == 0) return DUP;
	if (strcmp(cmds, "INTERSECT") == 0) return INTERSECT;
	if (strcmp(cmds, "UNION") == 0) return UNION;
}

void solve()
{



	switch (parseCmd(cmds))
	{
	case PUSH:
		push();
		break;
	case DUP:
		dup();
		break;
	case UNION:
		ops_union();
		break;
	case ADD:
		ops_add();
		break;
	case INTERSECT:

		ops_intersect();
		break;
	default:
		break;
	}

	print();

}

int main()
{
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);

	int cnt = 0;
	scanf("%d", &tcs);

	while (scanf("%d", &ops) == 1 && cnt++ != tcs)
	{
		REP(i, ops) {
			memset(cmds, 0, sizeof(cmds));
			scanf("%s", cmds);
			solve();
		}
		printf("%s\n", "***");

		IDCache.clear();
		stack<int>().swap(stacks);
		SetCache.clear();
	}
	return 0;
}
