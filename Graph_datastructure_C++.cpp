#include<iostream>
#include<queue>//For storing record of visited vertices
using namespace std;

class graph{
    int vertices;
    int **AdjacencyMatrix;
    public:
    graph(int vertice):vertices(vertice){
        AdjacencyMatrix=new int*[vertices];
        for(int i=0;i<vertices;i++){
            AdjacencyMatrix[i]=new int[vertices];
            for(int j;j<vertices;j++){
                AdjacencyMatrix[i][j]=0;
            }
        }
    }
    ~graph(){
        for(int i=0;i<vertices;i++){
            delete []AdjacencyMatrix[i];
        }
        delete []AdjacencyMatrix;
    }
    void addEgde(int v,int u){
            if(v>=vertices||u>=vertices||v<0||u<0){
                cout<<"Invalid edge.."<<endl;
            }
            else{
                AdjacencyMatrix[v][u]=1;
                AdjacencyMatrix[u][v]=1;//For undirected graphs...
            }
        }
    void display_graph(){
            for(int i=0;i<vertices;i++){
                for(int j=0;j<vertices;j++){
                cout<<AdjacencyMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void Breadth_first_search(int start){
        bool *visited=new bool[vertices]();
        queue<int>q;
        cout<<"Breadth first search..."<<endl;
        visited[start]=true;
        q.push(start);
        while(!q.empty()){
            int current=q.front();
            q.pop();
            cout<<current<<" ";
            for(int i=0;i<vertices;i++){
                if(AdjacencyMatrix[current][i]==1&&!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        cout<<endl;
        delete []visited;
    }
    void DFS_Helper(int v,bool *visited){
        visited[v]=true;
        cout<<v<<" ";
        for(int i=0;i<vertices;i++){
            if(AdjacencyMatrix[v][i]==1&&!visited[i]){
                DFS_Helper(i,visited);
            }
        }
    }
    void DFS(int start){
        bool *visited=new bool[vertices]();
        cout<<"DFS:"<<endl;
        DFS_Helper(start,visited);
        cout<<endl;
        delete []visited;
    }    
};