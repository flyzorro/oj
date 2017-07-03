
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
#include <sstream>
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

#define MAXN 300

map<string, int> cnt;
vector<string> book;

string convert_to_lower(const string& s)
{
	string to = s;
	REP(i, s.length()) to[i] = tolower(s[i]);
	sort(ALL(to));
	return to;
}

void solve()
{
	string s;
	
	while (cin >> s && s != "#")
	{
		istringstream iss(s);
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(book));
	}

	for (auto p : book)
	{
		cnt[convert_to_lower(p)] += 1;
	}
	sort(ALL(book));

	for (auto p : book) if (cnt[convert_to_lower(p)] <= 1) cout << p << endl;
}


int main()
{
	solve();
	return 0;
}
