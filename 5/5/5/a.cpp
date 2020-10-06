//
//  Xinyang He
//
//



#include <iostream>
#include <map>
#include <fstream>
#include <stdexcept>
#include <limits.h>
#include <stdio.h>

#define maxints 1000
#define V 48

using namespace std;

int minDistance(int dist[], bool sptSet[]){
    // Initialize min value
    int min = INT_MAX, min_index = 0;
    
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    
    return min_index;
}

// Function to print shortest
// path from source to j
// using parent array

void printPath(int parent[], int j){
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;
    
    printPath(parent, parent[j]);
    
    cout << " " << j;
}

// A utility function to print
// the constructed distance
// array
void printSolution(int dist[], int n, int parent[]){
    int src = 0;
    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < V; i++){
        printf("\n%d -> %d \t\t %d\t\t%d ",
               src, i, dist[i], src);
        printPath(parent, i);
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src){
    // The output array. dist[i]
    // will hold the shortest
    // distance from src to i
    int dist[V];
    
    // sptSet[i] will true if vertex
    // i is included / in shortest
    // path tree or shortest distance
    // from src to i is finalized
    bool sptSet[V];
    
    // Parent array to store
    // shortest path tree
    int parent[V];
    
    // Initialize all distances as
    // INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++){
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    
    // Distance of source vertex
    // from itself is always 0
    dist[src] = 0;
    
    // Find shortest path
    // for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance
        // vertex from the set of
        // vertices not yet processed.
        // u is always equal to src
        // in first iteration.
        int u = minDistance(dist, sptSet);
        
        // Mark the picked vertex
        // as processed
        sptSet[u] = true;
        
        // Update dist value of the
        // adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)
            
            // Update dist[v] only if is
            // not in sptSet, there is
            // an edge from u to v, and
            // total weight of path from
            // src to v through u is smaller
            // than current value of
            // dist[v]
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    
    
    // print the constructed distance array
    //cout << "Shortest distance: " << dist[tar] << endl;
    printSolution(dist, V, parent);
    //printPath(parent, tar);
}

int main() {
    
    map<string, int> campus;
    campus["20"] = 1;
    campus["21"] = 2;
    campus["23A"] = 3;
    campus["23B"] = 4;
    campus["23C"] = 5;
    campus["23E"] = 6;
    campus["23F"] = 7;
    campus["23G"] = 8;
    campus["23H"] = 9;
    campus["24"] = 10;
    campus["25"] = 11;
    campus["26"] = 12;
    campus["27"] = 13;
    campus["28"] = 14;
    campus["29"] = 15;
    campus["30"] = 16;
    campus["31"] = 17;
    campus["33"] = 18;
    campus["34"] = 19;
    campus["35"] = 20;
    campus["36"] = 21;
    campus["37"] = 22;
    campus["38"] = 23;
    campus["39"] = 24;
    campus["40"] = 25;
    campus["41"] = 26;
    campus["42"] = 27;
    campus["43"] = 28;
    campus["44"] = 29;
    campus["45"] = 30;
    campus["46"] = 31;
    campus["47"] = 32;
    campus["48"] = 33;
    campus["49"] = 34;
    campus["50"] = 35;
    campus["51"] = 36;
    campus["52"] = 37;
    campus["53"] = 38;
    campus["54"] = 39;
    campus["55"] = 40;
    campus["56"] = 41;
    campus["57"] = 42;
    campus["58"] = 43;
    campus["59"] = 44;
    campus["60"] = 45;
    campus["61"] = 46;
    campus["78"] = 47;
    campus["82"] = 0;
    
    ifstream inf;
    int count = 0;
    string list[maxints];
    inf.open("/Users/hexinyang/Desktop/NEU/7205FCE/Assignment/5/info.txt");
    if (inf.fail()){
        cerr << "Error: Could not open input file\n";
        exit(1);
    }
    
    while (! inf.eof()) {
        inf >> list[count++];
    }
    
    //for(int i = 0; i < count; i++)
        //cout << list[i] << endl;
    
    inf.close();
    
    int path[V][V];
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j ++)
            path[i][j] = 0;
    }
    
    map<string, int>::iterator iter;
    map<string, int>::iterator iter2;
    string distance;
    
    for(int i = 0; i < count; i+=3){
        iter = campus.find(list[i]);
        iter2 = campus.find(list[i + 1]);
        distance = list[i + 2];
        int len = atoi(distance.c_str());
        if(iter != campus.end())
            if(iter2 != campus.end()){
                path[iter->second][iter2->second] = len;
                path[iter2->second][iter->second] = len;
                //cout << a << " ";
               // cout<<"Find, the value is"<<iter->second<<endl;
            }
            //else
               // cout<<"Do not Find"<<endl;
    }
    /*
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j ++)
            cout << path[i][j] << " ";
        cout << endl;
    }
    */
    
    string in, out;
    cout << "Walk from: ";
    cin >> in;
    cout << "To: ";
    cin >> out;
    
    map<string, int>::iterator in_index;
    map<string, int>::iterator out_index;
    
    in_index = campus.find(in);
    out_index = campus.find(out);
    
    dijkstra(path, in_index->second);
    //dijkstra(path, in_index->second, out_index->second);
    
    return 0;
}
