#ifndef EVENT
#define EVENT

#include <tuple>
using namespace std ; 

class Event {
    /*
        Computation completion event for module Mi is described as - 
            3 tuple (i , i , t)
            where t is the timestamp at which the module Mi completes its execution.
    */

    /*
        Communication completion event between module Mi & Mj (Mi -> Mj) is described as - 
            3 tuple (i , j , t)
            where t is the timestamp at which the communication is completed.

            NOTE :
            if Mi and Mj are on the same processor. Then t is set to TIME, since there will not be any communication delay.
    */


    public:
        int i , j , t ; 


        Event(int i , int j , int t){ 
            this->i = i ; 
            this->j = j ; 
            this->t = t ; 
        }


} ; 

#endif