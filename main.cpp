#include <iostream>
#include <cmath>
#include "./include/Clustering.hpp"
#include "./include/Task_graph.hpp"
#include "./include/Event_queue_model.hpp"

using namespace std ; 

int main(){

    int n = 7 ; 

    Clustering cluster(7) ; 

    cluster.gen_clustering() ; 

    vector<vector<int>> graph = {
        {0 , 10 , 2 , 0 , 0 , 0 , 0} , 
        {0 , 0 , 0 , 0 , 0 , 0 , 4} , 
        {0 , 0 , 0 , 8 , 6 , 0 , 0} , 
        {0 , 0 , 0 , 0 , 0 , 3 , 0} , 
        {0 , 0 , 0 , 0 , 0 , 3 , 0} , 
        {0 , 0 , 0 , 0 , 0 , 0 , 2} , 
        {0 , 0 , 0 , 0 , 0 , 0 , 0} 
    } ; 
    
    vector<int> node_wt = {2,10,2,4,4,2,2} ; 

    Task_graph g(n , node_wt , graph) ; 

    int time = 1e9 ; 

    Event_queue eq ; 

    Allocation alloc(7) ; 
    for(int i = 0 ; i<7 ; i++){
        if(i < 2) alloc.allocation[i] = 0 ; 
        else alloc.allocation[i] = 1 ; 
    }

    // cout<<cluster.all_clustering.size()<<'\n' ; 

    // for(auto& it:cluster.all_clustering){
    //     time = min(time , eq.compute_exetime(g ,it)) ; 
    // }

    time = eq.compute_exetime(g , alloc) ; 


    cout<<time<<'\n' ; 
    
    return 0 ; 
}