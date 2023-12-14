#ifndef EVENT_QUEUE_MODEL
#define EVENT_QUEUE_MODEL

#include "Allocation.hpp"
#include "Clustering.hpp"
#include "Event.hpp"
#include "Ready_queue.hpp"
#include "Task_graph.hpp"

#include <queue>
#include <vector>

class Event_queue {
    /*
        Let V be the number of vertices, and E be the number of edges in the task graph. 
        Then, there will be a total of (E + V) events out of which - 
        V events will be computation completion events corresponding to each module.
        E events will be communication completion events corresponding to each edge.
     */
    public:    

        /*
            Comparator for the priority queue 
        */

        struct cmp{
            bool operator()(Event& event1 , Event& event2){
                return event1.t > event2.t ; 
            }
        } ; 

        
        priority_queue<Event , vector<Event> , cmp> event_queue ; 

        int compute_exetime(Task_graph& graph , Allocation& alloc) ;     
} ; 

#endif