
typedef enum { 
    UNDISCOVERED, // 未发现
    DISCOVERED, // 发现
    VISITED // 已访问 
} VStatus; //节点的状态 
typedef enum { 
    UNDETERMINED, //未定边
    TREE, // 树边
    CROSS, // 跨边
    FORWARD, //前向边
    BACKWARD //后向边
} EType; //边的类型     

template <typename Tv, typename Te> //节点TV 边Te
class Graph{

    private:
        void reset(){//初始化图
            for(int i = 0 ; i < n ; i++ ){
                //遍历所有节点
                status(i) = UNDETERMINED; dTime(i) = fTime(i) = -1//重置图状态 发现访问结束时间-1
                parent(i) = -1; priority(i) = INT_MAX;//节点父亲-1 结点的优先级最大
                for(int j = 0 ; i < n ; j ++ ){
                    //遍历所有边
                    if(exits(i , j)){type(i,j) = UNDETERMINED;} //边存在 未定边
                }
            }
        }
        void BFS ( int, int& ); //连通图内部宽搜
        void DFS ( int, int& ); //连通图内部深搜
        void BCC ( int, int&, Stack<int>& ); //����ͨ�򣩻���DFS��˫��ͨ�����ֽ��㷨
        bool TSort ( int, int&, Stack<Tv>* ); //����ͨ�򣩻���DFS�����������㷨
        template <typename PU> void PFS ( int, PU ); //����ͨ�����ȼ��������
     
    
    public:
        virtual VStatus& status( int ) = 0; //第i个节点状态
        virtual EType& type( int , int ) = 0 //i->j边的类型
        virtual int& parent( int ) = 0; //第i个节点的父亲节点索引
        virtual int& dTime ( int ) = 0; //发现节点的时刻
        virtual int& fTime ( int ) = 0; //结束访问后节点的时刻
        virtual int& priority( int ) = 0;//节点优先级

        virtual bool exits( int , int ) = 0; //(i->j) 边是否存在
        
        void bfs( int ); //广度优先搜索算法
        void dfs( int ); //深度优先搜索算法
        void bcc( int ); //基于DFS的双连通分量分解算法
        // Stack<Tv>* tSort( int ); //基于DFS的拓扑排序算法
        void prim( int ); //最小支撑树Prim算法
        void dijkstra( int ); //最短路径Dijkstra算法
        template <typename PU> void pfs( int, PU ); //优先级搜索框架
}

