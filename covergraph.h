//
// Created by Tafseer Ahmed on 2/5/2018.
//
class CoverGraph {
private:
    unsigned int N; // Nodes in Graph taken as an input through user at the time of execution of program.
    std::vector<std::pair<unsigned int, std::string>> P; // P is the set of nodes in the PoSet's cover graph
    std::vector<std::vector<int>> E,M; // E is the adjacency list showing edges in the cover graph. M is incidence matrix
    std::vector<int> V;// V is incidence edge vector
public:
    /*
     Initializes the data structure M (the incidence matrix)
     by first resizing the 2D vector to size of Cover Graph (N)
     and then iterates N times to create a 2D Vector Matrix
     where all values are initialized to 0. Afterwards, it creates
     and incidence edge vector V of size N, whose ith index denotes
     number of incident edges at the ith node of the cover graph.
     **NOTE**
     It is important to run the INIT() function before being able
     to access DelMin() or ListMin() functions, as they use the
     constructed data structure.
     */
    void INIT();
    /*
     DelMin() function takes an input inside the function which
     is more convenient and first prints the list of available
     nodes and simultaneously shows which are deleted nodes
     or minimal nodes, it deletes the node by traversing the
     Adjacency list corresponding to the node, setting the
     values to 0 in the incidence matrix and simultaneously
     reducing the incidence edge value in the vector V by 1.
     If a non-minimal element has been selected by mistake
     it reports the error.
     */
    void DelMin();
    /*
    ListMin prints the list of minimal elements by iterating
     all the nodes in the incidence edge vector and printing
     only if the value is 0.
     */
    void ListMin();
    /* Cover Graph constructor*/
    CoverGraph(unsigned int);
};


