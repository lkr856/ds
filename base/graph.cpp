#include "graph.h"
#include "queue.h"
#include "stack.h"

template <typename Tv, typename Te> //
void Graph<Tv, Te>::BFS ( int v, int& clock ) {
    Queue<int> Q;
    status(v) = DISCOVERED; Q.enqueue(v);
    while( !Q.empty()){
        int v = Q.dequeue(); dTime(v) = clock;//为第v个顶点赋予发现时间
        for(int u = firstNbr(v) ; -1 < u ; u = nextNbr(v,u)){//v,u的下一个边 从大小找
            if(UNDISCOVERED == status(u)){//未发现的点才记录
                status(u) = DISCOVERED;
                Q.enqueue(u);
                type(v ,u) = TREE;//更新边类型 v->u
                parent(u) = v; //更新父亲
            }else{ //如果已经发现的节点，说明在更早层已经发现
                type(v ,u) = CROSS;
            }
        }
        status(v) = VISITED;//v点所有的临边都已查询到，v访问完毕
    }
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int & clock)
{
    dTime(v) = ++clock; status(v) = DISCOVERED;
    for(int u = firstNbr(v) ; -1 < u ; u = nextNbr(v,u)){
        switch(status(u)){
            case UNDISCOVERED:
                type(v,u) = TREE; parent(u) = v; DFS(u,clock); break;
            case DISCOVERED:
                type(v,u) = BACKWARD; break;
            default:
                type(v,u) = dTime(v) < dTime(u) ? FORWARD : CROSS; break;
        }
    }
    status(u) = VISITED; fTime(v) = ++clock;
}



template <typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(int v, int & clock, Stack<Tv> * S)
{
    dTime(v) = ++clock; status ( v ) = DISCOVERED;
    for(int u = firstNbr(v) ; u > -1 ; u = nextNbr(v)){
        switch(status(u)){
            case UNDISCOVERED:
                type(v,u) = TREE; parent(u) = v; 
                if(!TSort(u, clock,S)){return false;}break;
            case DISCOVERED:
                type(v,u) = BACKWARD; return false;//出现后向边说明有环不能拓扑排序
            default:
                type(v,u) = dTime(v) < dTime(u) ? FORWARD : CROSS; break;
        }
    }
    status(v) = VISITED;
    S->push( vertex(v)); //将已经访问结束的节点压入栈
    return true;
}

//宽搜森林
template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s)
{
    reset();//对整个森林初始化
    int clock = 0;//当前步骤的时刻
    int v = s; //s起始访问节点 v当前访问节点
    do{
        if(status(v) == UNDISCOVERED){//只有当 当前节点v未访问过才会访问该图
            BFS(v , clock); //clock时刻访问v连通图
        }
    } while(s != (v = (++v % _n))); //v模n遍历确保所有节点都能判断一遍
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s)
{
    reset();//对整个森林初始化
    int clock = 0;//当前步骤的时刻
    int v = s; //s起始访问节点 v当前访问节点
    do{
        if(status(v) == UNDISCOVERED){//只有当 当前节点v未访问过才会访问该图
            DFS(v , clock); //clock时刻访问v连通图
        }
    } while(s != (v = (++v % _n))); //v模n遍历确保所有节点都能判断一遍

}



template <typename Tv, typename Te>
Stack<Tv> *Graph<Tv, Te>::tSort(int s)
{
    reset(); int clock = 0 ; int v= s; //s起始节点
    Stack<Tv> S = new Stack<Tv>;
    do{
        if(UNDISCOVERED == status(v)){//没访问过的v对其子联通图拓扑排序
            
            if(!TSort(v, clock, S)){ //说明有环无法拓扑排序
            //   当前子图结束访问全部栈里元素删除掉
                while( !S->empty()){
                    S->pop();
                }
                break; //退出循环结束
            }
        }
    }while( s!=(v = (++v % _n)));
    return S;//栈的弹出顺序就是拓扑排序
}

// Stack<Tv> *Graph::tSort(int s)
// {
//     return nullptr;
// }
template <typename Tv, typename Te>
void Graph<Tv, Te>::bcc(int s)
{
    reset(); int clock = 0; int v = s; Stack<int> S;
    do
    {
        if(UNDISCOVERED == status(v)){ //未访问
            BCC(v,clock ,S );

        }
        /* code */
    } while ( s != (v = (++v % _n)));
    
}

#define hca(x) (fTime(x)) // 访问完成的时间
template <typename Tv, typename Te>
void Graph<Tv, Te>::BCC(int v, int & clock, Stack<int> & S)
{//深搜改进
    hca(v) = dTime(v) = ++clock;//最早公共祖先
    status(v) = DISCOVERED;
    S.push(v);
    for ( int u = firstNbr ( v ); -1 < u; u = nextNbr ( v, u ) ){
        switch (status(v))
        {
        case UNDISCOVERED:
            parent(u) = v; type(v,u) = TREE;BCC(u,clock,S);
            //bcc回溯过程 u子树已经完成深搜
            if(hca(u) < dTime(v)){//当前访问节点后向边能连接到的最早祖先hca()
                hca(v) = min(hca(u) , hca(v));//如果v子可以连接到更早的祖先则可以和v的比一比小的为新的hca
            }else{//此时u的hca比v的时刻大等说明u子树是双连通分量
                while ( v != S.pop() ); { //u,v都是关节点
                    S.push ( v );
                }
            }
            break;
        case DISCOVERED:
            type(v,u) = BACKWARD;
            if( u != parent(v)) {//v->u是后向边且u不是v的父亲(如果是父亲删除一个连通分支不会增加)
                hca(v) = min(hca(v) ,dTime(u));//看看u能不能让v的hca更小
            }
            break;
        default:
            type(v,u) = dTime(v) < dTime(u) ? FORWARD : CROSS;
            break;
        }
    }
    status(v) = VISITED;
}
#undef hca




template <typename Tv, typename Te>
template <typename PU> //他自己的优化函数
void Graph::pfs(int s, PU prioUpdater)
{
    reset(); int v = s; 
    do
    {
        if(status(v) == UNDETERMINED){
            PFS(v,prioUpdater);
        }
    } while (s != (v = (++v % _n)));
    
}

template <typename Tv, typename Te>
template <typename PU>
void Graph<Tv, Te>::PFS(int s, PU prioUpdater)
{
        
}

void Graph::prim(int s)
{
}

void Graph::dijkstra(int s)
{
}