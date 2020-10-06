//
// Xinyang He
// 001059405
// please use 'g++ -std=c++11' to compile

#include <iostream>
#include <map>
#include <fstream>
#include <stdexcept>
#include <limits.h>
#include <stdio.h>

// length of array from txt
#define maxints 10000
// length of map
#define V 48
using namespace std;

// find min distance
int minDistance(int dist[], bool sptSet[]){
    // initialize min value
    int min = INT_MAX, min_index = 0;
    
    for (int v = 0; v < V; v++){
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }
	// v is not included in the shortest path
    return min_index;
}

// print shortest path from source to j
void printPath(int parent[], int j, map<string, int> campus){
    // if j is source
    if (parent[j] == -1)
        return;
    // recursive calls
    printPath(parent, parent[j], campus);
    
    // find key of value j
    string key;
    for(map<string, int>::iterator it = campus.begin(); it != campus.end(); it++) {
        if(it->second == j)
            key = it->first;
    }
    // reversely print key of value j
    cout << " -> " << key;
}

// print the final distance array
void printSolution(int dist[], int n, int parent[], int src, int tar, map<string, int> campus){
    string srcKey, tarKey;
    printf("Vertex\t\t Distance\t Path");
    
    // find key of source and target
    for(map<string, int>::iterator it = campus.begin(); it != campus.end(); it++) {
	if(it->second == src)
            srcKey = it->first;
	if(it->second == tar)
	    tarKey = it->first;
    }
    // print source and target building number and their distance
    cout<<endl<<srcKey<<" -> "<<tarKey<<" \t "<<dist[tar]<<"\t\t "<<srcKey;
    // print the shortest path between them
    printPath(parent, tar, campus);
}

// implementation of Dijkstra algorithm for adjacency matrix of a graph
void dijkstra(int graph[V][V], int src, int tar, map<string, int> campus){
    // dist[i] represents for the shortest distance from source to i
    int dist[V];

    // sptSet[j] is true if j is in the shortest path
    bool sptSet[V];

    // parent of i in shortest path
    int parent[V];
    
    // initialize dist[] and sptSet[]
    for (int i = 0; i < V; i++){
        parent[src] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    
    // distance of source to source is 0
    dist[src] = 0;
    
    // find shortest path
    for (int count = 0; count < V - 1; count++) {
        // choose the nearest node that isn't processed
        int u = minDistance(dist, sptSet);
        
        // set this node as processed
        sptSet[u] = true;
        
        // update distance value of the chosen node
        for (int v = 0; v < V; v++)
            // update distance if it is not in the shortest path, there is an edge,
            // and distance u add weight between u and v is smaller than distance v
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]){
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    
    // print the final distance of source and target
    //cout << "Shortest distance: " << dist[tar] << endl;
    printSolution(dist, V, parent, src, tar, campus);
}

int main() {
    // initialize campus building numbers and their index
    map<string, int> campus;
    campus["20"] = 1;
    campus["21"] = 2;
    campus["23A"] = 3;
    // initialize campus building numbers and their index
    campus["23B"] = 4;
    campus["23C"] = 5;
    campus["23E"] = 6;
    campus["23F"] = 7;
    // initialize campus building numbers and their index
    campus["23G"] = 8;
    campus["23H"] = 9;
    campus["24"] = 10;
    campus["25"] = 11;
    // initialize campus building numbers and their index
    campus["26"] = 12;
    campus["27"] = 13;
    campus["28"] = 14;
    campus["29"] = 15;
    // initialize campus building numbers and their index
    campus["30"] = 16;
    campus["31"] = 17;
    campus["33"] = 18;
    campus["34"] = 19;
    // initialize campus building numbers and their index
    campus["35"] = 20;
    campus["36"] = 21;
    campus["37"] = 22;
    campus["38"] = 23;
    // initialize campus building numbers and their index
    campus["39"] = 24;
    campus["40"] = 25;
    campus["41"] = 26;
    campus["42"] = 27;
    // initialize campus building numbers and their index
    campus["43"] = 28;
    campus["44"] = 29;
    campus["45"] = 30;
    campus["46"] = 31;
    // initialize campus building numbers and their index
    campus["47"] = 32;
    campus["48"] = 33;
    campus["49"] = 34;
    campus["50"] = 35;
    // initialize campus building numbers and their index
    campus["51"] = 36;
    campus["52"] = 37;
    campus["53"] = 38;
    campus["54"] = 39;
    // initialize campus building numbers and their index
    campus["55"] = 40;
    campus["56"] = 41;
    campus["57"] = 42;
    campus["58"] = 43;
    // initialize campus building numbers and their index
    campus["59"] = 44;
    campus["60"] = 45;
    campus["61"] = 46;
    campus["78"] = 47;
    // initialize campus building numbers and their index
    campus["82"] = 0;
    
    // read distance between buildings data file
    ifstream inf;
    int count = 0;
    string list[maxints];
    // open data file
    inf.open("./info.txt");
    if (inf.fail()){
	// in case failure
        cerr << "Error: Could not open input file\n";
        exit(1);
    }

    // set each line to list
    while (! inf.eof()) {
        inf >> list[count++];
    }
    
    //for(int i = 0; i < count; i++)
        //cout << list[i] << endl;
    
    inf.close();

    // initialize adjacency matrix
    int path[V][V];
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j ++)
            path[i][j] = 0;
    
    // intialize two iterator for two nodes have edge between them
    map<string, int>::iterator iter;
    map<string, int>::iterator iter2;
    string dist;
    
    // update adjacency matrix using data file
    for(int i = 0; i < count; i += 3){
        iter = campus.find(list[i]);
        iter2 = campus.find(list[i + 1]);
        dist = list[i + 2];
	// convert string to int format
        int len = atoi(dist.c_str());
        if(iter != campus.end())
            if(iter2 != campus.end()){
		// adjacency matrix for a undirected graph is symmetric matrix
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
    // input source and target
    cout << "Walk from: ";
    cin >> in;
    cout << "To: ";
    cin >> out;
    
    // initialize two iterator for source and target
    map<string, int>::iterator in_index;
    map<string, int>::iterator out_index;
    
    // find index of source and target
    in_index = campus.find(in);
    out_index = campus.find(out);

    // use dijkstra algorithm to find the shortest path
    dijkstra(path, in_index->second, out_index->second, campus);
    
    cout << endl;
    
    return 0;
}
