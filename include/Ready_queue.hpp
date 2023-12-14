#ifndef READY_QUEUE_HPP
#define READY_QUEUE_HPP

#include <vector>
#include <queue>

using namespace std ; 


class Ready_queue {
    public:
        int processors ; 
        vector<queue<int>> ready_queue ; 
        vector<bool> proc_state ; 


        Ready_queue(int processors){
            this->processors = processors ; 
            this->ready_queue = vector<queue<int>>(processors) ; 
            this->proc_state = vector<bool>(processors , true) ; 
        }



} ; 


#endif