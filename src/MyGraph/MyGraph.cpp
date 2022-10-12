//
// Created by karol on 12/10/2022.
//

#include <iostream>
#include "include/MyGraph.h"


template<typename T>
MyGraph<T>::MyGraph() {
    number_nodes = 0;
}

template<typename T>
void MyGraph<T>::add_vertex(std::string node_id) {
    Node<std::string> node(node_id);
    std::vector<Node<std::string>> nodes;
    nodes.push_back(node);

    adjacent_list.insert(make_pair(node_id, nodes));
    number_nodes++;

    //    std::pair<std::string, std::vector<Node<std::string>>> id_nodes_pair;
    //    id_nodes_pair.first = node_id;
    //    id_nodes_pair.second = nodes;
}

template<typename T>
void MyGraph<T>::add_edge(std::string node1_id, std::string node2_id) {
    /*
     * node1, node2 = get the nodes given the ids from the adjacent_list
     * create edge between the nodes -->
     *      to adj_list.node1 add node2
     *      to adj_list.node2 add node1
     */
    Node<std::string> node1;
    Node<std::string> node2;
    // get node1 and node2
    for (auto it = adjacent_list.begin(); it != adjacent_list.end(); ++it) {
        if (it->first == node1_id) { node1 = it->second[0]; }
        if (it->first == node2_id) { node2 = it->second[0]; }
    }

    // create edge between the nodes
    adjacent_list[node1_id].push_back(node2);
    adjacent_list[node2_id].push_back(node1);
}

template<typename T>
void MyGraph<T>::show_connections() {
    std::cout << "Presenting the graph" << std::endl;
    for (auto it = adjacent_list.begin(); it != adjacent_list.end(); ++it) {
        std::cout << "id = " << it->first << "; values of nodes = [";
        for (int i = 0; i < it->second.size(); i++) {
            std::cout << it->second[i].value << " ";
        }
        std::cout << "]" << std::endl;
    }
}


// ensures that compiler will generate code for those types
template
class Node<int>;

template
class Node<float>;

template
class Node<std::string>;

template
class MyGraph<int>;

template
class MyGraph<float>;

template
class MyGraph<std::string>;



