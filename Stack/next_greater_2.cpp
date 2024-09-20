#include<bits/stdc++.h>
using namespace std;

#define    nl            <<endl
#define    sz            size()
#define    ll            long long
#define    vi            vector<int>
#define    lld           long double
#define    all(a)        a.begin(), a.end()
#define    ull           unsigned long long
#define    read(arr,n)   for(int i=0 ; i<n;i++) cin>>arr[i]
#define    pb(x)         push_back(x)
#define    SACHIN        ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
 
#ifndef    ONLINE JUDGE
#define    debug(x)      cerr<< #x << "->" ; _print(x); cerr << endl;
#define    debug1(x,y)   cerr<< #x << "->"<<x<< " "  <<#y << "->" <<y<<endl<<endl;
#else
#define    debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//---------------------code begins here---------------------
 
 
vector<int> nextGreaterElements(vector<int>& nums) {

    stack <int> s;
    int n = nums.size();
    vector < int > v(n);

    for(int i=n-2;i>=0;i--){
        s.push(nums[i]);
    }

    for(int i = n-1 ; i >= 0 ; i--){
            // debug(nums[i]);
            // debug(s.top());
            
        while(!s.empty() && s.top()<=nums[i]){

            // debug1(s.top(),nums[i]);
            s.pop();
        }

        if(!s.empty())v[i]=s.top();

        else v[i]=-1;

        s.push(nums[i]);
        debug(v);
    }

    return v;
}
 
int main(){
  
  int n;
  cin>>n;

  vi arr(n);
  read(arr,n);

  vector<int> ans = nextGreaterElements(arr);

  for(auto i: ans){
    cout << i<<" ";
  }

  return 0;
}