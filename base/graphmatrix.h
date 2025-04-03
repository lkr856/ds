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
   GraphMatrix() { _n = _e = 0; } //_n:图内节点个数
   ~GraphMatrix() { //
      for ( int j = 0; j < _n; j++ ) //遍历所有边删除
         for ( int k = 0; k < _n; k++ ) 
            delete E[j][k]; //二维数组会由Vector处理删除逻辑
   }
   virtual VStatus& status( int i){return V[i].status;}//返回节点的状态
   virtual exists(int j,int j){return (0<=i) &&  ( i < _n ) && ( 0 <= j ) && ( j < _n ) && E[i][j] != NULL;}//i，j没超出范围且边存在
   virtual int nextNbr ( int i, int j){ while((-1 < j) && (!exists(i , --j))); return j;} //只要第i个节点的第j条边不存在就继续往前探直到找到存在的边，返回i点的第j条边的序号j
   virtual int firstNbr(int i){return nextNbr(i,_n); } //从序号大到小找第一个边
   virtual EType& type( int i, int j){return E[i][j]->type;} //默认边是存在的
   virtual int& parent( int i){return V[i].parent;} //可以更新父亲根据访问顺序
   virtual int& dTime ( int i ) { return V[i].dTime; } //发现第i个结点的时间
   virtual int& fTime ( int i ) { return V[i].fTime; } //访问结束第i个结点的时间
   virtual Tv& vertex ( int i ) { return V[i].data; }
}