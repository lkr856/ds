#include "vector.h"
#include "graph.h"

template <tyoename Tv> struct Vertex { //节点
    Tv data; int inDegree, outDegree; VStatus status;
    int dTime, fTime; //发现时间 完成访问时间
    int parent; int priority; //父节点索引 结点的优先级
    Vertex ( Tv const& d = ( Tv ) 0 ) : //初始化默认值转成模板类别
    data ( d ), inDegree ( 0 ), outDegree ( 0 ), status ( UNDISCOVERED ),
    dTime ( -1 ), fTime ( -1 ), parent ( -1 ), priority ( INT_MAX ) {} //入度出度为初始为0 发现结束时刻无效 父节点索引无 点的优先级无穷
};
template <typename Te> struct Edge { //边
    Te data; int weight; EType type; //边的类型
    Edge ( Te const& d, int w ) : data ( d ), weight ( w ), type ( UNDETERMINED ) {} //默认边类型未知
};
template <typename Tv, typename Te> //节点TV 边Te
class GraphMatrix : public Graph<Tv, Te> { //邻接矩阵实现图类
private:
   Vector< Vertex< Tv > > V; //节点列表
   Vector< Vector< Edge< Te > * > > E; //节点对应的边列表
public:
   GraphMatrix() { n = e = 0; } //n:图内节点个数
   ~GraphMatrix() { //
      for ( int j = 0; j < n; j++ ) //遍历所有边删除
         for ( int k = 0; k < n; k++ ) 
            delete E[j][k]; //二维数组会由Vector处理删除逻辑
   }
   
}