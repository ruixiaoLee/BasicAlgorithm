//Ford法 邻接链表
//一个点到其他各个点的最短距离
//允许权值为负，若权值没有负数则比Dijkstra快
//O(|N||V|)顶点数乘边数
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct edge{
  int from,to,cost;
};
// struct edge e;//起始点终点和权值
// int d[1000];//用来储存从起始点到某点的距离
// vector<edge> path;//移动

int main(void){
  int node, side;
  cin>>node>>side;//设置含有的点数和边数
  struct edge e;//起始点终点和权值
  int d[1000];//用来储存从起始点到某点的距离
  vector<edge> path;//移动
  for(int i=0 ; i<side ; i++){
    int a,b;
    cin>> a >> b >> e.cost;
    e.from=a-1;
    e.to=b-1;
    path.push_back(e);
  }
  for(int j=0 ; j<node ; j++){
    d[j]=1000;
  }
  cout<<"input start and end vertices"<<endl;
  int start,end;
  cin>>start>>end;
  d[start-1]=0;
  //fill(d, d+node, 1000);所有点的d初始化全部为1000
  //只有起始点初始化为0
  for(int i=0 ; i<node ; i++){//对所有点
    for(int j=0 ; j<(int)path.size() ;j++){//对所有边
      struct edge k = path[j];  //移动到的点k
      if(d[k.to] > d[k.from]+k.cost){//起始点到下一个点的距离如果>
        d[k.to] = d[k.from]+k.cost;  //起始点到上一个点的距离+到k点的cost
        if(i==node-1) return 0;      //则更新起始点到下一个点的距离
      }
    }
  }
  cout<<"min path:"<<d[end-1]<<endl;
  return 0;
}
