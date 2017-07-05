
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
template<class T> void ckmin(T &a, const T &b) { if (b < a) a = b; }
template<class T> void ckmax(T &a, const T &b) { if (b > a) a = b; }

typedef struct CmpQ CmpQ;
typedef struct node node;

struct node
{
	int t, q, v;
	node(int team, int q_pos, int value) :t(team), q(q_pos), v(value)
	{
	}
};

struct CmpQ
{
	bool operator ()(const node& a, const node& b) const
	{
		if (a.t == b.t) return a.q < b.q;
		return a.q < b.q;
	}
};

map<int, int> tIDCaches;
priority_queue<node, vector<node>, CmpQ> team_queue;
bool finished = false;
int q_id = 0;

void  handle_queue(int m)
{
	team_queue.push(node(tIDCaches[m], q_id++, m));
}

void handle_deque()
{
	if (team_queue.empty()) return;
	node n = team_queue.top(); team_queue.pop();
	printf("%d\n", n.v);
}


void solve()
{
	string cmd;
	finished = false;
	while (!finished &&  cin >> cmd)
	{
		switch (cmd[0])
		{
		case 'E':
			int m;
			cin >> m;

			handle_queue(m);
			break;
		case 'D':
			handle_deque();
			break;
		case 'S':
			finished = true;
			break;
		default:
			break;
		}
	}
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int teams = 0, cnt = 0;
	while (scanf("%d", &teams) == 1 && teams)
	{
		q_id = 0;
		tIDCaches.clear();
		priority_queue<node, vector<node>, CmpQ>().swap(team_queue);
		printf("Scenario #%d\n", ++cnt);
		REP(i, teams)
		{
			int nums;
			cin >> nums;
			REP(j, nums) {
				int id;
				scanf("%d", &id);

				tIDCaches[id] = i + 1;
			}

		}

		solve();

		printf("\n");
	}
	return 0;
}
