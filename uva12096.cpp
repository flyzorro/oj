
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
template<class T> void ckmin(T &a, const T &b) { if (b<a) a = b; }
template<class T> void ckmax(T &a, const T &b) { if (b>a) a = b; }

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
void print(int id)
{
	int size = IDCache[id].size();
	size = size > 0 ? size - 1 : 0;
	printf("%d\n", size);
}


void push()
{
	stacks.push(0);
	SI si;
	si.insert(0);

	if (SetCache[si] == 0) { IDCache.push_back(si); SetCache[si] += 1; }
}

void dup()
{
	if (stacks.empty()) return;
	stacks.push(stacks.top());
}

void ops_add()
{

	int l = 0, r = 0;
	if (stacks.size() < 2) return;
	l = stacks.top();
	stacks.pop();
	r = stacks.top();
	stacks.pop();

	SI si = IDCache[r];
	si.insert(l);

	if (SetCache[si] == 0) { IDCache.push_back(si); SetCache[si] += 1; }
}

void ops_union()
{
	int l = 0, r = 0;
	if (stacks.size() < 2) return;
	l = stacks.top();
	stacks.pop();
	r = stacks.top();
	stacks.pop();
	SI si;
	set_union(ALL(IDCache[l]), ALL(IDCache[r]),inserter(si, si.begin()));
	if (SetCache[si] == 0) { IDCache.push_back(si); SetCache[si] += 1; }

}

void ops_intersect()
{
	int l = 0, r = 0;
	if (stacks.size() < 2) return;
	l = stacks.top();
	stacks.pop();
	r = stacks.top();
	stacks.pop();

	SI si;
	set_intersection(ALL(IDCache[l]), ALL(IDCache[r]),  inserter(si, si.begin()));
	if (SetCache[si] == 0) { IDCache.push_back(si); SetCache[si] += 1; }
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

	print(stacks.top());

}

int main()
{
	scanf("%d", &tcs);
	REP(i, tcs)
	{
		while (scanf("%d", &ops) == 1 && ops)
		{
			memset(cmds, 0, sizeof(cmds));
			REP(i, ops) { scanf("%s", cmds); solve(); }
		}

		printf("%s\n", "***");

		IDCache.clear();
		stack<int>().swap(stacks);
		SetCache.clear();

	}
	return 0;
}
