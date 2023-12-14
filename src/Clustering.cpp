#include "../include/Clustering.hpp"

using namespace std ; 

void Clustering::partition(int index){
	if (index == nodes) {
		int curr_processor = 0 ; 
		Allocation alloc(nodes) ; 

        for(auto& cluster:clustering){
            for(auto& cluster_element:cluster){
                alloc.allocation[cluster_element] = curr_processor ; 
            }
        	curr_processor++ ; 
        }

        all_clustering.push_back(alloc) ; 
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

