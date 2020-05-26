 /*UVA-10986-Sending email*/
#include <bits/stdc++.h>

#define endl '\n'
#define maxn 20001
using namespace std;



struct node {
  int id, w; // id := 點編號, w := 連結到此點的權重 (邊權重)
  bool operator<(const node &rhs) const {
    return w > rhs.w; // 使 priority_queue 為 min heap
  }
};

struct edge {
  int u, v, w; // u := 起端編號, v := 終端編號, w := 權重
  bool operator<(const edge &rhs) const {
    return w > rhs.w; // 使 priority_queue 為 min heap
  }
};

vector<node> E[maxn]; // 邊集合
int s[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	/*implement your code*/
	
    int u,v,w,n,m,t,source;
    cin>>n>>m>>source>>t;//n 點個數,m 線段個數,source 起點,t 終點
    
    for(auto i=0;i<m;i++){
        cin>>u>>v>>w;
        /*無向邊=>插入2個有向邊*/
        E[u].push_back({v,w});
        E[v].push_back({u,w});
    }
    /*Dijkstra*/
    memset(s, 0x3f, sizeof(s)); // 源點到任意點的成本初始為無限大
    priority_queue<node> Q; // 為從未解集挑出已解的狀態
    
    Q.push({source, s[source] = 0});
    while (!Q.empty()) {
      node u = Q.top(); Q.pop();
      
      for (node v: E[u.id]) { // v := 鄰點
        int update = u.w + v.w; // 源點到 u 的最小成本 + u 到 v 的成本
        if (update < s[v.id])
          Q.push({v.id, s[v.id] = update /* relaxation */});
      }
    }
    //s[t] 代表從source到target t的最短距離 若沒有更新則代表沒s->t路徑
    if(s[t]!=0x3f3f3f3f)
        cout<<s[t];
    else
        cout<<"unreachable";
	/*implement your code*/
	return 0;
}
