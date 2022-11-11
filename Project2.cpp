#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iomanip>
#include <sstream>
using namespace std; 

class AdjacencyList {//The Adjacency List Class
    private: 
        unordered_map<string, unordered_set<string>> adjacency_list; 
        //The data structure for the adjacency list is a unordered_map with the key of vertices and the value is a set of unique edges.
        //The set of unique edges is acceptable since there are no parallel edges while still allowing for directional edges between multiple sets. 
        //Therefore, this datastructure works in the same way as a 2 dimensional array while not requiring the extra space for zero values since each set can have its own size.
        //Unordered_map means that all basic operations take O(1) like an array, but it cannot have an order, which is fine in terms of a graph.
    public: 
        AdjacencyList(vector<pair<string, string>> edges);//The constructor for the adjacency list, using a list of vertex pairs, representing directional edges (from, to)
        map<string, string> CalculatePageRank(int n);//The Page Rank function designed to return a value, which allows for proper testing with catch

};

AdjacencyList::AdjacencyList(vector<pair<string, string>> edges){
    
    for(auto edge: edges){//Iterating over the edges from the parameter
        
        //Setting new names to the variables for readability
        string from, to; 
        from = edge.first; 
        to = edge.second; 

        //Adding the from-to edge under the from vertex, which also adds from to the map if necessary using default constructors
        adjacency_list[from].insert(to);
        //Adding the to vertex, ensuring both vertices (from & to) are in the map
        adjacency_list[to];
    }

}

map<string, string> AdjacencyList::CalculatePageRank(int n){

    //An important note is the end memory for the print out is a map NOT an unordered_map.
    //This means the results that are injected into it are already sorted, reading for printing.
    map<string, double> rank_matrix; 

    for(const auto a: adjacency_list){//Setting initial values to the rank matrix r(0), using the adjacency list keys and size
        string from = a.first;
        rank_matrix[from] = 1.0/(double)adjacency_list.size(); 
    }
    
    for(int p = 1; p < n; p++){//This will repeat the following code for n-1 iterations, since n=0 is the intial value rather than an additional calculation. 
        
        map<string, double> temp;//A temp is needed here because the rank_matrix cannot be modified until all calculations have been completed.

        for(const auto a: adjacency_list){//The double for loop allows for iteration over every value in the adjacency list
            string from = a.first;
            unordered_set<string> outgoing_edges = a.second;
            for(const auto neighbor_vertex: outgoing_edges){
                    //Adding 1 over the size of outgoing edges times the previous rank matrix value.
                    //After all computations are done, this will sum up 1/len(outgoing_edges) * prev_rank for every edge
                    temp[neighbor_vertex] += 1.0/((double)outgoing_edges.size()) * ((double)rank_matrix[from]);
            }
        }
        rank_matrix = temp;//Update the rank_matrix since all calculations are done
    }
    
    map<string, string> rank_matrix_rounded; //Instead of pringting to the console, the values are altered and added to a new map for proper checking
    for(const auto r: rank_matrix){//Simply print out the rank_matrix in order (because its an ordered map built on tree rather than a table) with the proper rounding and precision.
        string from = r.first; 
        double rank = r.second;
        std::stringstream stream;
        stream << fixed << setprecision(2) << rank;
        rank_matrix_rounded[from] = stream.str();
    }

    return rank_matrix_rounded;//Return the resulting rank matrix for proper testing
}

#ifndef UNIT_TESTING//Catch Framework testing purposes with Makefile
int main(){
    ////PROVIDED CODE FROM PROJECT 2 PDF
    int no_of_lines, power_iterations;
    string from, to; 
    cin >> no_of_lines;
    cin >> power_iterations; 
    ////

    //All inputted edges are stored in a vector of type pair (string, string).
    //This allows for easy accessibility after the for loop has been completed. 
    //This is only done because it is assuming that an AdjacencyList object must be created AFTER the inputs have been collected.
    //However, a more optimal solution would involve adding each edge as it is inputted, which would use 1 loop rather than 2.  
    vector<pair<string, string>> edges; 
    
    ////PROVIDED CODE FROM PROJECT 2 PDF
    for(int i = 0; i < no_of_lines; i++){
        cin >> from; 
        cin >> to; 
    ////
        edges.push_back(make_pair(from, to));//Adding the new edge to the vector
    }

    //Initializes a new AdjacencyList object and calls the CalculatePageRank function, which will print out the result. 
    AdjacencyList a_list(edges);
    map<string, string> rank_matrix = a_list.CalculatePageRank(power_iterations);

    for(const auto r: rank_matrix){//Simply print out the rank_matrix in order (because its an ordered map built on tree rather than a table) with the proper rounding and precision.
        string from = r.first; 
        string rank = r.second;
        cout << from << " " << rank << endl;
    }

}
#endif


