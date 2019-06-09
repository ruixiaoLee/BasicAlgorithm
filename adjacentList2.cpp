#include<vector>
#include<iostream>
#include<list>
using namespace std;//没有储存权值

class Graph{
  private:
    int V;//No. of vertices
    list<int> *adjList;//Pointer to an array containing adjacency lists
  public:
    Graph(int V){
      this -> V = V;
      adjList = new list<int>[V];
    }
    void addEdge(int v, int w){
      adjList[v].push_back(w);
    }
    void BFS(int s);//BreadthFirstSearch
    void DFS(int v);//DepthFirstSearch
    void DFSUtil(int v, bool visited[]);
};

void Graph::BFS(int s){
  bool *visited=new bool[V];//array
  for(int i=0 ; i<V ; i++){
    visited[i]=false;
  }
  //create a queue for BFS
  list<int> que;
  visited[s]=true;
  que.push_back(s);
  //iter will be used to get all adjacent vertices of a vertex
  list<int>::iterator iter;
  while (!que.empty()) {
    //dequeue a vertex from que and print
    int k=que.front();
    cout<<k<<" ";
    que.pop_front();
    //get all adjacent vertices of the dequeued vertex. If a adjacent has not
    //been visited then mark it visited and enqueue it
    for(iter=adjList[k].begin() ; iter!=adjList[k].end() ; ++iter){
      if(!visited[*iter]){
        visited[*iter]=true;
        que.push_back(*iter);
      }
    }
  }
}

void Graph::DFSUtil(int v, bool visited[]){
  //make the current node as visited and print
  visited[v]=true;
  cout<<v<<" ";
  //recur循环 for all the vertices adjacent to this vertex
  list<int>::iterator iter;
  for(iter=adjList[v].begin() ; iter!=adjList[v].end() ; ++iter){
    if(!visited[*iter]) DFSUtil(*iter, visited);
  }
}

void Graph::DFS(int v){
  bool *visited=new bool[V];//array
  for(int i=0 ; i<V ; i++){
    visited[i]=false;
  }
  DFSUtil(v, visited);
}

int main(void){
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
  g.BFS(2);
  g.DFS(2);
  return 0;
}
