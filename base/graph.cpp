#include "graph.h"

template <typename Tv, typename Te> //
void Graph<Tv, Te>::BFS ( int v, int& clock ) {
    
}

void Graph::DFS()
{
}

void Graph::BCC()
{
}

void Graph::TSort()
{
}

void Graph::PFS()
{
}
//宽搜森林
void Graph::bfs(int s)
{
    reset();//对整个森林初始化
    int clock = 0;//当前步骤的时刻
    int v = s; //s起始访问节点 v当前访问节点
    do{
        if(status(v) == UNDISCOVERED){//只有当 当前节点v未访问过才会访问该图
            BFS(v , clock); //clock时刻访问v连通图
        }
    } while(s != (v = (++v % n))); //v模n遍历确保所有节点都能判断一遍
}

void Graph::dfs(int s)
{
}

void Graph::bcc(int s)
{
}

// Stack<Tv> *Graph::tSort(int s)
// {
//     return nullptr;
// }

void Graph::prim(int s)
{
}

void Graph::dijkstra(int s)
{
}

template <typename PU>
inline void Graph::pfs(int, PU)
{
}