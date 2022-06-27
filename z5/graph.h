#ifndef GRAPH_H
#define GRAPH_H
#pragma once
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>  
#include <ctime>  
#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000

//ADT graph implementation using adjacency matrix

class ADTGraph{
    public:
        int vertices[MAX_SIZE];
        int edges[MAX_SIZE][MAX_SIZE];
        int size;
        ADTGraph(int numOfVertices);
        ~ADTGraph();
        void addVertex(int vertex);
        void addEdge(int v1, int v2);
        void removeVertex(int vertex);
        void removeEdge(int v1, int v2);
        bool connected(int v1, int v2);

        //return the nieghborhood of a vertex
        int* neighbors(int vertex);

        void setVertexValue(int vertex, int value);
        int getVertexValue(int vertex);
        void setEdgeValue(int v1, int v2, int value);
        int getEdgeValue(int v1, int v2);

        int sizeOfGraph();

        void printGraph(int size);

        void dotFile(string filename);
};

#endif