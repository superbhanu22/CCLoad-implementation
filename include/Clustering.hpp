#ifndef CLUSTERING_HPP
#define CLUSTERING_HPP

#include "Allocation.hpp"
#include<vector>


using namespace std ; 

class Clustering{
    private:
        int nodes ; 

    public:
        vector<Allocation> all_clustering ;
        vector<vector<int>> clustering ; 

        /*
            These functions are intended to generate all possible clustering
            for a clustering C of all possible clustering , ith node belong to C[i] processor

            All the clustering are stored in all_clustering array
        */

        void gen_clustering() ; 
        void partition(int idx) ; 


        Clustering(int nodes){
            this->nodes = nodes ; 
        }

} ; 

#endif  