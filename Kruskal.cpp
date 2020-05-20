#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define MAXN 10005
int g[MAXN];

struct edge {
  int u, v, w; // u := 起端編號, v := 終端編號, w := 權重
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

int Kruskal(vector<edge> &pq){
    int cost=0;
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int ori_ans=0,ans=0,N,K,M,input,u,v,w;
    cin >>N;
    //init grp
    init(N);
    for(auto i=0;i<N-1;i++) cin>>u>>v>>input,ori_ans+=input;
    //Update lines
    cin >>K;
    for(auto i=0;i<K;i++){
        cin >>u>>v>>w;
        pqeg.push_back({u,v,w});
    }
    cin >>M;
    for(auto i=0;i<M;i++){
        cin >>u>>v>>w;
        pqeg.push_back({u,v,w});
    }
    //sort to priority_queue by weights of edge
    sort(pqeg.begin(),pqeg.end(),[&](edge x, edge y) { return x.w < y.w; });
    //use Kruskal to find MST
    ans=Kruskal(pqeg);
    cout<<"original ans: "<<ori_ans<<"updated ans: "<<ans;
}
