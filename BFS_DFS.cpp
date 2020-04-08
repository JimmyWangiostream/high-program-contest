//DFS
#define graph_size 9
bool adj[graph_size][graph_size];   // 設一個圖形，資料結構為：adjacency matrix。
bool visit[graph_size];             // 用於記錄圖上的點是否遍歷過，遍歷過為true。
 
void DFS(int i) {
    int j;
    for ( j=0; j < graph_size; j++ ){
        if (adj[i][j] && !visit[j]) {
            visit[j] = true;    // 標記為已遍歷
            DFS(j);
        }
    }
}
 
void traversal() {
    int i;
    // 將全部的點初始化為未遍歷
    for ( i=0; i < graph_size; i++ )
        visit[i] = false;
 
    for ( i=0; i < graph_size; i++ ){
        if (!visit[i]){
            visit[i] = true;
            DFS(i);
        }
    }
}
//BFS
#define graph_size 9
bool adj[graph_size][graph_size];   // 設一個圖形，資料結構為：adjacency matrix。
bool visit[graph_size];             // 用於記錄圖上的點是否遍歷過，遍歷過為true。
 
void BFS() {
    int i,j,k;
    // 建立一個queue。
    queue<int> q;
    // 全部的點都初始化為尚未遍歷
    for ( i=0; i < graph_size; i++ )
        visit[i] = false;
 
    for ( k=0; k < graph_size; k++ ) {
        if (!visit[k]) {
            // 1. 把起點放入queue。
            q.push(k);
            visit[k] = true;
            // 2. 重複下述兩點( 3 & 4 )，直到queue裡面沒有東西為止：
            while (!q.empty()) {
                // 3. 從queue當中取出一點。
                i = q.front(); q.pop();
                // 4. 找出跟此點相鄰且尚未遍歷的點，依照編號順序通通放入queue。
                for ( j=0; j < graph_size; j++ ){
                    if (adj[i][j] && !visit[j]) {
                        q.push(j);
                        visit[j] = true;
                    }
                }
            }
        }
    }
}
