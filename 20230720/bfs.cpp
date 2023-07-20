// Description: BFS algorithm
/*
Algorithm: Breadth First Search

0. BFS(Source)
    level[]= infinity
    Declare a queue
    Equeque (source)
    level[source]=0
    while queue is not empty
        u= front(queue)
        dequeque(u)
        For all adjacent edges of u
            v= adjacent edge of u
            if level[v]==infinity
                Enqueque(v)
                level[v]= level[u]+1
            end if
        end for
    end while
end BFS
*/

/*
Input:
10 13
1 2
1 3
1 4
2 6
6 10
4 7
3 7
3 8
9 10
9 7
8 7
8 5
10 5

Adjacency List:
1: 2 3 4
2: 1 6
3: 1 7 8
4: 1 7
5: 8 10
6: 2 10
7: 4 3 9 8
8: 3 7 5
9: 10 7
10: 6 9 5
*/

// //Code for BFS
// int level[11];
// void BFS(int vector source){
//     level[] = INTMAX;
// }
// int main(){

//     int node, edge;
//     cout << "Enter the number of node and edge: ";
//     cin >> node >> edge;
//     vector <int> adj[node+1];
//     for(int i=0; i<edge; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u); //For undirected graph
//     }
//     BFS(1);
//graph: 1 2 3 4 5 6 7 8 9 10
//level: 0 1 1 1 2 2 2 2 3 3
// }
/*
node: 10
edge: 13
10 13
1 2
1 3
1 4
2 6
6 10
4 7
3 7
3 8
9 10
9 7
8 7
8 5
10 5

*/

 /*   
    // path from source to destination
    int destination;
    cout << "Enter the destination: ";
    cin >> destination;
    vector<int> path;
    path.push_back(destination);
    int parent = destination;
    while (parent != 10)
    {
        for (int i = 0; i < Node_vec[parent].size(); i++)
        {
            int v = Node_vec[parent][i];
            if (level[v] == level[parent] - 1)
            {
                path.push_back(v);
                parent = v;
                break;
            }
        }
    }
    cout << "Path from source to destination: ";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << endl;
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> Node_vec[11];
int level[11];
int parent[11];
void BFS(int source)
{
    for (int i = 0; i < 11; i++)
    {
        level[i] = INT_MAX;
    }
    queue<int> Q;
    Q.push(source);
    level[source] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int j = 0; j < Node_vec[u].size(); j++)
        {
            int v = Node_vec[u][j];
            if (level[v] == INT_MAX)
            {
                Q.push(v);
                level[v] = level[u] + 1;
                parent[v] = u;
            }
        }
    }
}

void path(int dest)
{
    cout<<"Destination: "<<endl;
    if(parent[dest] != dest)
    {
        path(parent[dest]);
    }
    cout<<dest<<" "<<endl;



}

int main()
{
    int node, edge;
    cout << "Enter the number of node and edge: ";
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        Node_vec[u].push_back(v);
        Node_vec[v].push_back(u);
    }
    BFS(10);
    for (int i = 1; i <= node; i++)
    {
        cout << "Level of " << i << " is: " << level[i] << endl;

    }
    
    path(1);



   

    return 0;
}

/*
    Indegree and Outdegree:
    Indegree: Number of edges coming to a node
    Outdegree: Number of edges going out from a node
    In a directed graph, Indegree and Outdegree are not equal
    In an undirected graph, Indegree and Outdegree are equal
    In a directed graph, Indegree + Outdegree = Total number of edges
    In an undirected graph, 2 * Total number of edges = Indegree + Outdegree : There is no direction in undirected graph, So no indegree and outdegree only degree.
    
    Handshaking Lemma:
    In a graph, the sum of all degrees is equal to twice the number of edges in the graph.
    In a directed graph, the sum of all indegree and outdegree is equal to the number of edges in the graph.
    In an undirected graph, the sum of all degrees is equal to twice the number of edges in the graph.
    In a directed graph, the sum of all indegree and outdegree is equal to the number of edges in the graph.
    In an undirected graph, the sum of all degrees is equal to twice the number of edges in the graph.
    In a directed graph, the sum of all indegree and outdegree is equal to the number of edges in the graph.
    In an undirected graph, the sum of all degrees is equal to twice the number of edges in the graph.
    In a directed graph, the sum of all indegree and outdegree is equal to the number of edges in the graph.
    In an undirected graph, the sum of all degrees is equal to twice the number of edges in the graph.
    In a directed graph, the sum of all indegree and outdegree is equal to the number of edges in the graph.
    In an undirected graph, the sum of all degrees is equal to twice the number of edges in the graph.
    In a directed graph, the sum of all indegree and outdegree is equal to the number of edges in the graph.
    In an undirected graph, the sum of all degrees is equal to twice the number of edges in the graph.
    
*/