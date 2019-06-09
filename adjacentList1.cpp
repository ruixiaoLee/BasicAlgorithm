#include<vector>
#include<iostream>
#include<queue>
using namespace std;//没有储存权值
vector<int> graph[100];//开了100个元素的数组，每一个包含一个vector向量
int node, edge;
//广度优先探索
//先初始化所有点没有被访问
//从起始点开始，新建一个队列queue先进先出FIFO
//推入起始点，将起始点更新为被访问
//当queue不为空时
//queue队列头赋值给k，并推出第一个元素
//指针从k顶点的链表头扫到尾，如果没有被访问则访问这个点并将这个点推入队列
void BreadthFirstSearch(int s){
  bool visited[node];
  for(int i=0 ; i<node ; i++)
    visited[i]=false;
  queue<int> que;
  vector<int>::iterator iter;
  que.push(s);
  visited[s]=true;
  while (!que.empty()){
    int k=que.front();
    cout<<k<<" ";
    que.pop();
    for(iter=graph[k].begin() ; iter!=graph[k].end() ; ++iter){
      if(!visited[*iter]){
        visited[*iter]=true;
        que.push(*iter);
      }
    }
  }
}
//深度优先探索//较简单
//DFS一个起始点，先初始化所有点均未被访问
//从起始点开始访问进入DFSUtil函数
//拉出起始点的 adjacentList 指针从头扫到尾
//当遇到的点没有被访问过则再次调用DFSUtil函数访问这个点
void DFSUtil(int s, bool visited[]){
  visited[s]=true;
  cout<<s<<" ";
  vector<int>::iterator iter;
  for(iter=graph[s].begin() ; iter!=graph[s].end() ; ++iter)
    if(!visited[*iter])
      DFSUtil(*iter, visited);
}

void DepthFirstSearch(int s){
  bool visited[node];
  for(int i=0 ; i<node ; i++)
    visited[i]=false;
  DFSUtil(s, visited);
}

int main(void){
    cin>>node>>edge;//设置含有的点数和边数
    int a,b;//起始点终点和权值
    for(int i=0 ; i<edge ; i++){
      cin>>a>>b;
      graph[a-1].push_back(b-1);
      graph[b-1].push_back(a-1);//undirected graph
    }
    //DepthFirstSearch(1);
    BreadthFirstSearch(1);
    return 0;
}
