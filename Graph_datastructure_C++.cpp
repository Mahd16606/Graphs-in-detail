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
    }};