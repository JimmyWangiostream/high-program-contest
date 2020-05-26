/*UVA10034*/
#include <bits/stdc++.h>

#define endl '\n'
#define MAXN 102

using namespace std;

int g[MAXN];
vector<pair<double,double>> nte;
struct edge {
  int u, v ; // u := 起端編號, v := 終端編號, w := 權重
  double w;
  bool operator<(const edge &rhs) const {
    return w > rhs.w; // 使 priority_queue 為 min heap
  }
};

vector<edge> MST;
vector <edge> pqeg;
void init(int N){
    for(auto i=1;i<=N;i++) g[i]=i;
}

int Find(int a){
    if(a==g[a]) return a;
    //Find & Union (改變同一個連通圖的構造,讓之後同個連通圖的Find更快)
    return g[a]=Find(g[a]);
}

void Union(int a,int b){
    if(Find(a)!=Find(b)) g[Find(a)]=Find(b);
}

double Kruskal(vector<edge> &pq){
    double cost=0;
    for (auto e: pq) {
      //用Union find 判斷是否在同一個連通圖
      int a = Find(e.u), b = Find(e.v);
      if (a != b) {
        Union(e.u, e.v);
        cost += e.w;
        MST.push_back({e.u, e.v, e.w});
      }
    }
    return cost;
}

double GetDistance(double x,double y,double x1,double y1){
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	/*implement your code*/
	int N;
	double x,y,ans;
	cin>>N;
	init(N);
	for(int i=0;i<N;i++){
	    cin>>x>>y;
	    nte.push_back(make_pair(x,y));
	}
	//to calculate edge
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            pqeg.push_back({i,j,GetDistance(nte[i-1].first,nte[i-1].second,nte[j-1].first,nte[j-1].second)});
        }
    }
    
    sort(pqeg.begin(),pqeg.end(),[&](edge x, edge y) { return x.w < y.w; });
    //for(auto i=0;i<3;i++) cout<<'\n'<<pqeg[i].u<<" "<<pqeg[i].v<<" "<<pqeg[i].w;
    ans=Kruskal(pqeg);
    printf("%.2lf",ans);
	/*implement your code*/
	return 0;
}
