#include "../include/Event_queue_model.hpp"
#include <iostream>
using namespace std ; 


int Event_queue::compute_exetime(Task_graph& graph , Allocation& alloc){

    // for(auto& it:alloc.allocation){
    //     cout<<it<<' ' ; 
    // }

    // cout<<'\n' ; 
    int TIME = 0 ;

    int num_processors = alloc.get_processors() ; 

    Ready_queue rq(num_processors) ; 

    rq.proc_state.resize(num_processors) ; 



    for(int i = 0 ; i<graph.nodes ; i++){
        if(graph.is_communication_completed(i)){
            rq.ready_queue[alloc.allocation[i]].push(i) ;
        }
    }

    // for(int i = 0 ; i<graph.nodes ; i++){
    //     if(graph.in_degree[i] == 0){
    //         int proc = alloc.allocation[i] ; 
    //         rq.ready_queue[proc].push(i) ; 
    //     }
    // }

    // cout<<rq.ready_queue.size()<<'\n' ; 

    // for(auto& it:rq.ready_queue){
    //     queue<int> qcopy = it ; 
    //     while(!qcopy.empty()){
    //         cout<<qcopy.front()<<' ' ; 
    //         qcopy.pop() ; 
    //     }
    //     cout<<'\n' ; 
    // }

    // cout<<'\n' ; 


    while(!event_queue.empty()){
        // priority_queue<Event , vector<Event> , cmp>  dummy = event_queue ; 

        // while(!dummy.empty()){
        //     auto node = dummy.top() ; 
        //     dummy.pop() ; 
        //     cout<<node.i<<' '<<node.j<<' '<<node.t<<'\n' ; 
        // }

        // cout<<'\n' ; 

        for(auto& it:rq.ready_queue){
            if(!it.empty()){
                int node = it.front() ; 
                it.pop() ; 
                Event new_compt(node , node , TIME) ; 
                event_queue.push(new_compt) ; 
            }
        }

        Event curr = event_queue.top() ; 

        event_queue.pop() ; 

        TIME = curr.t ; 

        int proc = alloc.allocation[curr.i] ; 
        // cout<<proc<<'\n' ; 

        if(!rq.ready_queue[proc].empty()){
            int new_process = rq.ready_queue[proc].front() ; 
            // cout<<new_process<<'\n' ; 
            rq.ready_queue[proc].pop() ; 
            Event new_compt(new_process , new_process , TIME+graph.computation_time[curr.i]) ; 
            event_queue.push(new_compt) ; 
        }

        if(curr.i == curr.j){
            // computation event    
            for(int i = 0 ; i<graph.nodes ; i++){
                if(graph.task_graph[curr.i][i] > 0){
                    
                    int t_commn = 0 ; 
                    graph.visited[curr.i][i] = true ; 
                    
                    // both i , j are on different processor
                    if(proc != alloc.allocation[i]){
                        t_commn += graph.task_graph[curr.i][i] ; 
                    }

                    Event new_commn(curr.i , i , TIME+t_commn) ; 
                    event_queue.push(new_commn) ; 
                    // graph.in_degree[i]-- ; 
                }
            }

            // for(auto& it:rq.ready_queue){
            //     if(!it.empty()){
            //         int node = it.front() ; 
            //         it.pop() ; 
            //         Event new_compt(node , node , TIME+curr.t) ; 
            //         event_queue.push(new_compt) ; 
            //     }
            // }
        }
        else{
            // communication event
            if(graph.in_degree[curr.j] == 0){
                Event new_compt(curr.j , curr.j , TIME) ; 
                rq.ready_queue[alloc.allocation[curr.j]].push(curr.j) ; 
                event_queue.push(new_compt) ; 
            }
        }

        
    }

    // cout<<TIME<<'\n' ; 

    return TIME ; 
}
