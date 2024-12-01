#include<iostream>

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
};