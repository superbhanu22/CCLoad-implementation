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

    int time = 1e9 ; 

    Event_queue eq ; 

    for(auto& it:cluster.all_clustering){
        Task_graph g(n , node_wt , graph) ; 
        int t_cal = eq.compute_exetime(g ,it) ; 

        time = min(time , t_cal) ; 
    }



    cout<<time<<'\n' ; 
    
    return 0 ; 
}