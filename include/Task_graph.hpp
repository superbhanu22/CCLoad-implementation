#ifndef TASK_GRAPH
#define TASK_GRAPH

#include <vector> 
using namespace std ; 

class Task_graph{
    public:
        /*
            Number of modules in the graph
        */
        int nodes ; 

        /*
            vector computation_time[i] means the time require to do computation for ith module
        */ 
        vector<int> computation_time ; 
        
        /*
            task graph represented as a adjacency matrix 
            graph[i][j] = 0 means there is no edge between ith module and jth module
            graph[i][j] > 0 means there is a directed edge from ith module to jth module with communication time graph[i][j]
        */

        vector<vector<int>> task_graph ; 
        vector<vector<bool>> visited ; 

        bool is_communication_completed(int curr_node) ; 



        Task_graph(int nodes , vector<int>& computation_time , vector<vector<int>>& task_graph){
            this->nodes = nodes ; 
            this->task_graph = task_graph ; 
            this->computation_time = computation_time ; 
            this->visited = vector<vector<bool>>(nodes , vector<bool>(nodes,false)) ;
        }    
} ; 

#endif