#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class graph{
    int vertices;
    int **AdjacenycMatrix;
    string *vertice_Value;//Added pointer array for string data value storage in vertices
    public:
    graph(int vertice):vertices(vertice){
        AdjacenycMatrix=new int *[vertices];
        for(int i=0;i<vertices;i++){
            AdjacenycMatrix[i]=new int[vertices];
        for(int j=0;j<vertices;j++){
            AdjacenycMatrix[i][j]=0;
        }}
        vertice_Value=new string[vertices];
    }
    ~graph(){
        for(int i=0;i<vertices;i++){
            delete []AdjacenycMatrix;
        }
        delete []AdjacenycMatrix;
        delete []vertice_Value;
    }
    void Add_vertice_value(int v,string data){
        if(v>=vertices||v<0){
            cout<<"Invalid vertice entry..."<<endl;
            return;
        }
        vertice_Value[v]=data;
    }
    void addEdge(int v,int u){
        if(v>=vertices||u>=vertices||u<0||v<0){
            cout<<"Invalid edge"<<endl;
            return;
        }
        AdjacenycMatrix[v][u]=1;
        AdjacenycMatrix[u][v]=1;;//For undirected graph
    }
    void display_graph(){
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                cout<<AdjacenycMatrix[i][j]<<" ";
            }
            cout<<endl;
    }}
    void Breadth_first_search(int start){
        if(start>=vertices||start<0){
            cout<<"Invalid vertice start....."<<endl;
            return;
        }
        bool *visited=new bool[vertices]();
        queue<int>q;
        cout<<"Breadth first search"<<endl;
        visited[start]=true;
        q.push(start);
        while(!q.empty()){
            int current=q.front();
            q.pop();
            cout<<vertice_Value[current]<<" ";
            for(int i=0;i<vertices;i++){
                if(AdjacenycMatrix[current][i]==1&&!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        cout<<endl;
        delete []visited;
    }
    void Depth_first_search_helper(int v,bool visited[]){
        visited[v]=true;
        cout<<vertice_Value[v]<<" ";
        for(int i=0;i<vertices;i++){
            if(AdjacenycMatrix[v][i]==1&&!visited[i]){
                Depth_first_search_helper(i,visited);
            }
        }
    }
    void depth_first_search(int start){
        if(start>=vertices||start<0){
            cout<<"Invalid vertice start....."<<endl;
            return;
        }
        bool*visited=new bool[vertices]();
        cout<<"Depth first search..."<<endl;
        Depth_first_search_helper(start,visited);
        cout<<endl;
        delete []visited;
    }
    void delete_Edge(int v,int u){
        if(v>=vertices||u>=vertices||v<0||u<0){
            cout<<"Invalid edge....."<<endl;
            return;
        }
        AdjacenycMatrix[v][u]=0;
        AdjacenycMatrix[u][v]=0;
    }
    void delete_Vertice(int v){
        if(v>=vertices||v<0){
            cout<<"Invalid vertice....."<<endl;
            return;
        }
        for(int i=0;i<vertices;i++){
            AdjacenycMatrix[v][i]=0;
            AdjacenycMatrix[i][v]=0;
        }
        vertice_Value[v]="";
        cout<<"Vertex "<<v<<" does not exist..."<<endl;
    }
};
int main() {
    int vertices = 7; // Example: Graph with 5 vertices
    graph g(vertices);

    // Adding edges
    g.addEdge(1, 2);
    g.addEdge(4, 6);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(0,2);
    //Adding string values to vertices over here.
    g.Add_vertice_value(0,"A");
    g.Add_vertice_value(1,"B");
    g.Add_vertice_value(2,"C");
    g.Add_vertice_value(3,"D");
    g.Add_vertice_value(4,"E");
    g.Add_vertice_value(5,"F");
    g.Add_vertice_value(6,"G");
    // Display the adjacency matrixss
    g.display_graph();
    g.Breadth_first_search(3);//Start from node/vertice 0
    g.depth_first_search(3);//start from node/vertice 0
    return 0;
}
