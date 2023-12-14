#ifndef ALLOCATION_HPP
#define ALLOCATION_HPP

#include <vector>
using namespace std ; 

class Allocation{
    private:
        /*
            Number of modules in the graph
        */
        int nodes ; 

        /*
            vector allocation[i] = j means the ith module is assigned to jth processor
        */ 

       

    public:
        vector<int> allocation ; 

        int get_processors() ;

        Allocation(int nodes){
            this->nodes = nodes ; 
            this->allocation = vector<int>(nodes) ; 
        }

};


#endif // ALLOCATION_HPP
