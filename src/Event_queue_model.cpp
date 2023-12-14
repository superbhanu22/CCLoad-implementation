#include "../include/Event_queue_model.hpp"
using namespace std ; 


int Event_queue::compute_exetime(Task_graph& graph , Allocation& alloc){
    int TIME = 0 ; 

    int processors = alloc.get_processors() ; 

    Ready_queue rq(processors) ; 


    for(int i = 0 ; i<graph.nodes ; i++){
        if(graph.is_communication_completed(i)){
            int proc = alloc.allocation[i] ; 
            rq.ready_queue[proc].push(i) ; 
        }
    }

    for(int i = 0 ; i<processors ; i++){
        if(!rq.ready_queue[i].empty()){
            int node = rq.ready_queue[i].front() ; 
            rq.ready_queue[i].pop() ; 
            if(rq.proc_state[i]){
                Event new_compt(node , node , TIME + graph.computation_time[node]) ; 
                event_queue.push(new_compt) ; 
                rq.proc_state[i] = false;  
            }
        }
    }

    while(!event_queue.empty()){
        Event curr_ev = event_queue.top() ; 
        event_queue.pop() ; 

        TIME = curr_ev.t ; 

        if(curr_ev.i == curr_ev.j){

            for(int i = 0 ; i<graph.nodes ; i++){
                if(graph.task_graph[curr_ev.i][i] > 0){
                    graph.visited[curr_ev.i][i] = true ; 

                    int t_new = TIME ; 

                    if(alloc.allocation[i] != alloc.allocation[curr_ev.i]){
                        t_new += graph.task_graph[curr_ev.i][i] ; 
                    }

                    Event new_comm(curr_ev.i , i , t_new) ; 
                    event_queue.push(new_comm) ; 
                }
            }

            rq.proc_state[alloc.allocation[curr_ev.i]] = true ; 
        }
        else{
            if(graph.is_communication_completed(curr_ev.j)){
                int proc = alloc.allocation[curr_ev.j] ;
                rq.ready_queue[proc].push(curr_ev.j) ; 
            }
        }


        for(int i = 0 ; i<processors ; i++){
            if(!rq.ready_queue[i].empty()){
                if(rq.proc_state[i]){
                    int node = rq.ready_queue[i].front() ; 
                    rq.ready_queue[i].pop() ; 
                    Event new_compt(node , node , TIME + graph.computation_time[node]) ; 
                    event_queue.push(new_compt) ; 
                    rq.proc_state[i] = false;  
                }
            }
        }

    }

    return TIME ; 
}
