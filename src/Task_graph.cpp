#include "../include/Task_graph.hpp"


bool Task_graph::is_communication_completed(int curr_node){
    for(int i = 0 ; i<nodes ; i++){
        if(task_graph[i][curr_node] > 0 && !visited[nodes][curr_node]){
            return false ; 
        }
    }

    return true ; 
}