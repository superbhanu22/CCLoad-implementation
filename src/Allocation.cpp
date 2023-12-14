#include "../include/Allocation.hpp"

#include <set>

using namespace std ; 

int Allocation::get_processors(){

    set<int> processors = set(allocation.begin() , allocation.end()) ; 

    return processors.size() ;
}
