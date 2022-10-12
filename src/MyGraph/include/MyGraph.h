//
// Created by karol on 12/10/2022.
//

#ifndef ALGORITHMS_DATASTRUCTURES_MYGRAPH_H
#define ALGORITHMS_DATASTRUCTURES_MYGRAPH_H

#include <vector>
#include <map>


template<typename T>
struct Node {
    T value;
    std::vector<Node<T> *> nodes_connected;

    Node() {}

    Node(T val) {
        value = val;
    }
};


template<typename T>
class MyGraph {
    int number_nodes = 0;
    std::map<std::string, std::vector<Node<std::string>>> adjacent_list;

public:
    MyGraph();

    void add_vertex(std::string node_id);

    void add_edge(std::string node1_id, std::string node2_id);

    void show_connections();
};


#endif //ALGORITHMS_DATASTRUCTURES_MYGRAPH_H
