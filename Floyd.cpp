/*uva-10048 – Audiophobia*/
#include <bits/stdc++.h>

#define endl '\n'
#define MAXN 101
using namespace std;

int s[101][101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	/*implement your code*/
	int N,ednum,q; //N vertices,ednum edge, q num of source & target cases
	cin>>N>>ednum>>q;
    
	/*s[i][j]=>用相鄰矩陣紀錄 點i到j 的 weight* (點從1 to c)/
	/*if i==j => s[i][j]=0 , 其餘紀錄真實weight ,沒被記錄則default 0x3f*/
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            s[i][j]=0x3f3f3f3f;
    for(int i=1;i<=N;i++)
        s[i][i]=0;
    //輸入邊
	int spt,ept,w;
    for(int i=0;i<ednum;i++){
        cin>>spt>>ept>>w;
        s[ept][spt]=s[spt][ept]=w;
    }
    
    for (int k = 1; k <= N; k++)
      for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++){
            //if(s[i][k]!=0x3f3f3f3f&&s[k][j]!=0x3f3f3f3f)//此題材要(代表沒有此邊=>下面用min=>應該不用)
                s[i][j]=min(s[i][j],max(s[i][k],s[k][j]));//此題 求s[i][j]最短的路徑(路徑長=其重最長邊)
            //s[i][j] = min(s[i][j], s[i][k] + s[k][j]); //=>求s[i][j]之最短路徑
        }
    //輸出
    for(int i=0;i<q;i++){
        cout<<"Case #"<<i<<": ";
        cin>>spt>>ept;
        cout<<s[spt][ept]<<endl;
    }
	/*implement your code*/
	return 0;
}
