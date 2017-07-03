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

#define MAX_NUM 300
//num of black blocks
multimap <char,int> blacks;
//num of white blocks for each blocks
map<char,int> hashset_black;
map<int, char> character_map;
int w = 0, h = 0,id = 0;
int w_actual = 0, max_w = 0;
char data[MAX_NUM][MAX_NUM]= {{0,0}};
char converted_data[MAX_NUM][MAX_NUM] = {{0,0}};
int  visited[MAX_NUM][MAX_NUM] = {{0,0}};

char binary_conv[16][16] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};

void dfs(int r, int c ,int id,bool scanBlack,char fill_val)
{
    int pivot = scanBlack ? '1' : '0';
    if (r < 0 || r > h+1 || c < 0 || c > max_w+1) return;
    if (visited[r][c] || converted_data[r][c] != pivot) return;

    converted_data[r][c] = fill_val;
    visited[r][c] = 1;
    FOR (i, -1, 2)
        FOR(j , -1, 2)
        {
            if (abs(i) ==abs(j)) continue;
            dfs(r+i,c+j,id,scanBlack, fill_val);
        }
}

void print()
{
	 REP (i, h+1)
	 {
        REP (j, max_w+1) {printf("%c", converted_data[i][j]);}
		
		printf("\n");
	 }
		
}

void solve()
{

	int black_id = 0;
	char pivot = '0';
    blacks.clear();
    hashset_black.clear();
    //flood fill white graph
    REP (i, h+1)
        REP (j, max_w+1)
        {
//            
           if (converted_data[i][j] == '0') 
               
		   {
               printf("pos i=%d, j=%d,find white and pivot=%c  \n", i,j,pivot);
			   if (pivot != '0') hashset_black[pivot] ++;
			   dfs(i, j ,0,false,'2');
			   print();

		   }
		   else if (converted_data[i][j]== '1') 
		   {
			   int k = 3+black_id;
			   char c = (k < 10 ? k + '0' : ('A' + k - 10));
			   dfs(i, j, black_id++,true,c); 
			   blacks.insert(MP(c,1));
		   }else if (blacks.count(converted_data[i][j]) > 0) {pivot = converted_data[i][j] ; }
        }


	vector<char> result;
	//printf("number of black graph=%d\n", blacks.size());
	for (auto p: blacks)
	{
		result.push_back(character_map[hashset_black[p.first]]);
	}
	sort(ALL(result));
	for(auto p: result) printf("%c",p);
	printf("\n");
}

int main()
{

	//init character map,
	character_map[1] = 'A';
	character_map[3] = 'J';
	character_map[5] = 'D';
	character_map[4] = 'S';
	character_map[0] = 'W';
	character_map[2] = 'K';

    while (scanf("%d %d",&h,&w)== 2 && w && h)
    {
		max_w = 0;
        memset(data, 0 , sizeof(data));
        memset(converted_data, '0',sizeof(converted_data));
        memset(visited, 0 , sizeof(visited));

		REP (i, h)
			scanf("%s", data[i]);


        //surround original data with '0' data to ensure white graph parsed correctly
        FOR(i , 1 , h+1)
		{
			w_actual = 1;
            FOR (j, 1, w+1)
            {   
                char c = data[i-1][j-1];
                if (c == '0' || c == '1') { converted_data[i][w_actual] = c;w_actual += 1;}
                //convert to binary data for hex data
				else
                {
                    int start = isalpha(c) ? c + 10 - 'a' : c - '0';
                    REP (k, 4) converted_data[i][w_actual+k] = binary_conv[start][k];
                    w_actual += 4;
                }                

            }   
			ckmax(max_w, w_actual);
		}
		
		printf("original data\n\n");
		print();



        solve();

    }



    return 0;
}
