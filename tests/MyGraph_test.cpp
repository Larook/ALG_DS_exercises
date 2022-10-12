//
// Created by karol on 11/10/2022.
//


#include "ostream"
#include <gtest/gtest.h>
#include <MyGraph.h>

using namespace std;

TEST(MyGraph, DisplayGraph) {
    MyGraph<std::string> graph;
    graph.add_vertex("0");
    graph.add_vertex("1");
    graph.add_vertex("2");
    graph.add_vertex("3");
    graph.add_vertex("4");
    graph.add_vertex("5");
    graph.add_vertex("6");
    graph.add_edge("3", "1");
    graph.add_edge("3", "4");
    graph.add_edge("4", "2");
    graph.add_edge("4", "5");
    graph.add_edge("1", "2");
    graph.add_edge("1", "0");
    graph.add_edge("0", "2");
    graph.add_edge("6", "5");

    graph.show_connections();
}



int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}