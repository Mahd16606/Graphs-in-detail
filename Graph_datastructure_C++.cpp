#include<iostream>
#include<queue>
#include<string>
using namespace std;
class graph{
    int **AdjancencyMatrix;
    int vertices;
    string *VertexValues;
    public:
    graph(int value):vertices(value){
        AdjancencyMatrix=new int*[vertices];
        for(int i=0;i<vertices;i++){
            AdjancencyMatrix[i]=new int[vertices];
            for(int j=0;j<vertices;j++){
                AdjancencyMatrix[i][j]=0;
            }
        }
        VertexValues=new string[vertices];
    }
    ~graph(){
        for(int i=0;i<vertices;i++){
            delete[] AdjancencyMatrix[i];
        }
        delete[] AdjancencyMatrix;
        delete[] VertexValues;
    }
    void add_vertexValue(int vertex,string value){
        if(vertex<0||vertex>=vertices){
            cout<<"Invalid vertex entered..."<<endl;
            return;
        }
        VertexValues[vertex]=value;
    }
    void addEdge(int v,int u){
        if(v>=vertices||u>=vertices||v<0||u<0){
            cout<<"Invalid vertices typed..."<<endl;
            return;
        }
        AdjancencyMatrix[v][u]=1;
        AdjancencyMatrix[u][v]=1;
    }
    void display_Graph_2d_Matrix(){
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                cout<<AdjancencyMatrix[i][j]<<" ";  
            }
        cout<<endl;
        }
    }
    void search_edge(int v,int u){
        if(v>=vertices||u>=vertices||v<0||u<0){
            cout<<"Invalid vertices typed..."<<endl;
            return;
        }
        if(AdjancencyMatrix[v][u]==1){
            cout<<"There exists an edge between "<<v<<" and "<<u<<endl;
        }
        else{
            cout<<"There does not exist an edge between "<<v<<" and "<<u<<endl;
        }
    }
    void search_vertex_with_value(string value){
        for(int i=0;i<vertices;i++){
            if(VertexValues[i]==value){
                cout<<"The vertex is found with position... "<<i<<"\n"<<endl;
                return;
            }
    }
    cout<<"Vertex not found..."<<endl;
    return;
    }
    void search_vertex_with_index_value(int vertex){
        if(vertex>=vertices||vertex<0){
            cout<<"Invalid vertex typed..."<<endl;
        return;
        }
        if(VertexValues[vertex]==""){
            cout<<"The vertex is deleted or empty..."<<endl;
            return;
        }
        else{
            cout<<"Vertex found with value..."<<VertexValues[vertex]<<endl;
        }
    }
    void delete_vertex_by_value(string value){
        int vertex_index_value=-1;
           for(int i=0;i<vertices;i++){
                if(VertexValues[i]==value){
                    cout<<"The vertex is found with position... "<<i<<"\nNow deleting.."<<endl;
                    vertex_index_value=i;
                }
           }
           if(vertex_index_value==-1){
            cout<<"No vertex found with value.. "<<value<<endl;
            return;
           }
           for(int j=0;j<vertices;j++){
                AdjancencyMatrix[vertex_index_value][j]=0;//Reseting all the egde connections
                AdjancencyMatrix[j][vertex_index_value]=0;
           }
            VertexValues[vertex_index_value]="";
            cout<<"Vertex deleted"<<endl;
    }
    void delete_vertex_by_index(int index_value){
        if(index_value>=vertices||index_value<0){
            cout<<"Invalid vertex typed..."<<endl;
        return;
        }
        for(int i=0;i<vertices;i++){
            AdjancencyMatrix[index_value][i]=0;
            AdjancencyMatrix[i][index_value]=0;
        }
        VertexValues[index_value]="";
        cout<<"The vertex is deleted."<<endl;    
    }
    void delete_edge(int v,int u){
        if(v>=vertices||u>=vertices||v<0||u<0){
            cout<<"Invalid vertices typed..."<<endl;
            return;
        }
        AdjancencyMatrix[v][u]=0;
        AdjancencyMatrix[u][v]=0;
        cout<<"The edge between the vertices has been deleted..."<<endl;
    }
    void Breadth_first_search(int start){
        if(start<0||start>=vertices){
            cout<<"Invalid start vertex"<<endl;
            return;
        }
        bool*visited=new bool[vertices]();
        queue<int>q;
        cout<<"BFS:"<<endl;
        visited[start]=true;
        q.push(start);
        while(!q.empty()){
            int current=q.front();
            q.pop();
            cout<<VertexValues[current]<<" ";
            for(int i=0;i<vertices;i++){
                if(AdjancencyMatrix[current][i]==1&&!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        cout<<endl;
        delete[] visited;
    }
    void DFS_helper(int v,bool*visited){
        visited[v]=true;
        cout<<VertexValues[v]<<" ";
        for(int i=0;i<vertices;i++){
            if(AdjancencyMatrix[v][i]==1&&!visited[i]){
                DFS_helper(i,visited);
            }
        }
    }
    void DFS(int start){
        if(start<0||start>=vertices){
            cout<<"Invalid start vertex"<<endl;
            return;
        }
        bool*visited=new bool[vertices]();
        cout<<"DFS:"<<endl;
        DFS_helper(start,visited);
        cout<<endl;
        delete[] visited;
    }
};
int main(){
        int vertices = 7; // Example: Graph with 7 vertices
    graph g(vertices);

    // Set values for the vertices
    g.add_vertexValue(0, "A");
    g.add_vertexValue(1, "B");
    g.add_vertexValue(2, "C");
    g.add_vertexValue(3, "D");
    g.add_vertexValue(4, "E");
    g.add_vertexValue(5, "F");
    g.add_vertexValue(6, "G");

    // The most important part.
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 2);

    // Display the adjacency matrix
    g.display_Graph_2d_Matrix();
    cout<<endl;
    g.Breadth_first_search(3); // Start from vertex 3 (D)
    g.DFS(3);   // Start from vertex 3 (D)
    // Search for a vertex and an edge
    g.search_vertex_with_index_value(3); // Search for vertex 3
    g.search_edge(1, 2); // Search for edge (1, 2)

    // Delete an edge and a vertex
    g.delete_edge(1, 2);
    g.delete_vertex_by_index(4);//Deletion by index
    g.delete_vertex_by_value("A");//Deletion by value
    // Display the graph after deletions
    g.display_Graph_2d_Matrix();

    // Perform BFS and DFS
    g.Breadth_first_search(3); // Start from vertex 3 (D)
    g.DFS(3);   // Start from vertex 3 (D)

    return 0;
}