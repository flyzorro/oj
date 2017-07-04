
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

typedef deque<int> QI;
vector<QI> queues;
bool finished = false;

void  handle_queue(int m)
{
	bool in = false;
	for (auto q : queues)
	{
		in = binary_search(ALL(q), m);
		if (in) break;
	}

	if (!in) queues[queues.size() - 1].push_back(m);
}

void handle_deque()
{
	for (auto &q : queues)
	{
		if (!q.empty()) { 
			cout << q.front() << endl;
			q.pop_front(); 
			return; }
	}
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
		printf("Scenario #%d\n", ++cnt);
		REP(i, teams)
		{
			int nums;
			QI q;
			cin >> nums;
			REP(i, nums) {
				int id;
				scanf("%d", &id);
				q.push_back(id);
			}

			sort(ALL(q));
			queues.push_back(q);
		}

		solve();
		queues.clear();

		printf("\n");
	}
	return 0;
}
