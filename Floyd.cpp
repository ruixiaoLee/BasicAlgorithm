//Floyd法 邻接矩阵
//用来计算【所有点对】的最短距离
//O（n^3）
#include<iostream>
using namespace std;

int main(void){
  int node, edge;
  cin>>node>>edge;//设置含有的点数和边数
  //int Distance[100][100];
  int Distance[node][node];
  int Path[node][node];
  int a,b,c;//起始点终点和权值
  for(int i=0 ; i<node ; i++){
    for(int j=0 ; j<node ; j++){
      if(i==j) Distance[i][j]=0;
      else Distance[i][j]=1000;
      Path[i][j]=j;
    }
  }
  for(int i=0 ; i<edge ; i++){
    cin>>a>>b>>c;
    Distance[a-1][b-1]=c;
    Distance[b-1][a-1]=c;//undirected graph
  }
//对于所有点， 全搜矩阵
  for(int k=0 ; k<node ; k++){
    for(int x=0 ; x<node ; x++){
      for(int y=0 ; y<node ; y++){
        if(Distance[x][k]+Distance[k][y]<Distance[x][y]){//如果点x->k的距离+点k->y的距离大于点x到y的距离，则更新点x->y的距离
          Distance[x][y]=Distance[x][k]+Distance[k][y];  //并将点x->y的path更新为点x->k的path
          Path[x][y]=Path[x][k];
        }
      }
    }
  }

  return 0;
}
