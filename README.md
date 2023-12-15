# CCLoad-implementation

This repository features implementation of **CC_load algorithm** which tries to solve the following problem using heuristics in polynomial time . 
> *Given a task graph of modules, the problem of finding an optimal clustering of modules is an NP-Complete problem *

The repository also features the implementation of **optimal algorithm** which tries to compute execution time for all the allocations possible for the given graph. 

----------------
**Requirements** -  C++ 17 , GCC / Clang compiler , Cmake 

------------
**Running the code**  -

In the CCLoad-implementation folder run the following command 

```bash
mkdir build
cd build
cmake ..
make
./exe
```

-------

The algorithm takes a task graph as input and tries to find the *T_OPT* (optimal time) and *T_SUBOPT*  (sub-optimal time) for the given graph . 

-----

**Graph** is described as a adjaceny matrix *G* and a weight array *W*

let the nodes of graph be N 
- W[i] means the computation time for ith node is W[i]
- G[i][j] means the communication time from ith node the jth , if G[i][j] > 0 