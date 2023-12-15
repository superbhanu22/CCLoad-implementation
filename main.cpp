#include <iostream>
#include <cmath>
#include "./include/Clustering.hpp"
#include "./include/Task_graph.hpp"
#include "./include/Event_queue_model.hpp"
#include "./include/CC_load.hpp"

using namespace std ; 

int main(){
    int n = 7 ; 

    Clustering cluster(n) ; 

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
    
    vector<int> node_wt = {2 , 10 , 2 , 4 , 4 , 2 , 2} ; 

    int time = 1e9 ; 

    Event_queue eq ; 

    CC_load cc_load(n) ;

    for(auto& it:cluster.all_clustering){
        Task_graph g(n , node_wt , graph) ; 
        int t_cal = eq.compute_exetime(g ,it) ; 

        time = min(time , t_cal) ; 
    }


    cout<<"T_OPT = "<<time<<'\n' ; 

    Task_graph g(n , node_wt , graph) ; 
    
    cout<<"T_SUBOPT = "<<cc_load.cc_load_clustering(g)<<'\n' ; 
    
    return 0 ; 
}