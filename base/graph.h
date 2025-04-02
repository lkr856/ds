using VStatus = enum {UNDISCOVERED, DISCOVERED, VISITED};
using EType = enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD };

class Graph{

    private:
        void reset(){

        }
    void BFS(); //宽搜
    void DFS(); //深搜
    void BCC(); //双连通
    void TSort(); //拓扑排序
    void PFS(); //优先级搜索
    
    public:
    void bfs( Rank ); //广度优先搜索算法
    void dfs( Rank ); //深度优先搜索算法
    void bcc( Rank ); //基于DFS的双连通分量分解算法
    Stack<Tv>* tSort( Rank ); //基于DFS的拓扑排序算法
    void prim( Rank ); //最小支撑树Prim算法
    void dijkstra( Rank ); //最短路径Dijkstra算法
    template <typename PU> void pfs( Rank, PU ); //优先级搜索框架
}

template <typename PU>
inline void Graph::pfs(Rank, PU)
{
}
