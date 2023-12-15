#include "../include/CC_load.hpp"
#include<cmath>

using namespace std ; 


void CC_load::get_load(Task_graph& graph){

    for(int i = 0 ; i<graph.nodes ; i++){
        int mx_in = 0 , mx_out = 0 ; 

        for(int j = 0 ; j<graph.nodes ; j++){
            mx_out = max(mx_out , graph.task_graph[i][j]) ; 
            mx_in = max(mx_in , graph.task_graph[j][i]) ; 
        }


        load[i].value = graph.computation_time[i] - mx_in - mx_out ; 
        load[i].index = i ; 
    }
}

int CC_load::cc_load_clustering(Task_graph& graph){
    get_load(graph) ; 

    sort(load.begin() , load.end() , cmp) ; 

    int processor_count = 1 ; 

    Allocation alloc(nodes) , min_allocation(nodes) ; 

    Event_queue eq ; 

    int t_min = eq.compute_exetime(graph , alloc) ; 

    min_allocation.allocation = alloc.allocation ; 

    for(int i = 0 ; i<graph.nodes ; i++){

        processor_count = alloc.get_processors() ; 
        for(int j = 0 ; j<=min(processor_count,graph.nodes-1) ; j++){
            graph.visited = vector<vector<bool>>(graph.nodes , vector<bool>(graph.nodes , false)) ; 
            alloc.allocation[load[i].index] = j ;

            int t_new = eq.compute_exetime(graph , alloc) ; 


            if(t_new < t_min){
                min_allocation.allocation = alloc.allocation ; 
                t_min = t_new ; 
            }
            
            alloc.allocation = min_allocation.allocation ; 
        }

    }

    return t_min ; 
}