#include "../include/Clustering.hpp"
#include <iostream>

using namespace std ; 


void Clustering::partition(int index){
	if (index == nodes) {
		int curr_processor = 0 ; 
		Allocation alloc(nodes) ; 

        for(auto& cluster:clustering){
			// cout<<'['<<' ' ; 
            for(auto& cluster_element:cluster){
				// cout<<cluster_element<<' ' ; 
                alloc.allocation[cluster_element] = curr_processor ; 
            }
			// cout<<']'<<' ' ; 
        	curr_processor++ ; 
        }

        all_clustering.push_back(alloc) ; 
		// cout<<'\n' ; 
		return;
	}

	for (int i = 0; i < clustering.size(); i++) {
		clustering[i].push_back(index);
		partition(index + 1);
		clustering[i].pop_back();
	}

	clustering.push_back({ index });
	partition(index + 1);
	clustering.pop_back();
}

void Clustering::gen_clustering(){
    partition(0) ; 
}

