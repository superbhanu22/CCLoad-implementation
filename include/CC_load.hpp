#ifndef CC_LOAD_HPP
#define CC_LOAD_HPP

#include "./Task_graph.hpp"
#include "./Allocation.hpp"
#include "./Event_queue_model.hpp"

#include <vector>

using namespace std ; 

class CC_load{
    public:
        int nodes ; 

        struct Load_module{
            int value , index ; 
        } ; 

        static bool cmp(Load_module& load1 , Load_module& load2){
            return load1.value > load2.value ; 
        }

        vector<Load_module> load ; 

        void get_load(Task_graph& graph) ; 
        int cc_load_clustering(Task_graph& graph) ; 

        CC_load(int nodes){
            this->nodes = nodes ; 
            this->load = vector<Load_module>(nodes) ; 
        }

} ; 

#endif


