#include "graph.h"

using namespace std;


ADTGraph::ADTGraph(int numOfVertices){
    size = numOfVertices;
    for(int i = 0; i < numOfVertices; i++){
        vertices[i] = -1;
        for(int j = 0; j < numOfVertices; j++){
            edges[i][j] = -1;
        }
    }
}


ADTGraph::~ADTGraph(){
}


void ADTGraph::addVertex(int vertex){
    vertices[vertex] = 0;
    size++;
}


void ADTGraph::addEdge(int v1, int v2){
    if(vertices[v1] == -1 || vertices[v2] == -1){
        return;
    }
    edges[v1][v2] = 0;
}


void ADTGraph::removeVertex(int vertex){
    if(vertices[vertex] == -1){
        return;
    }
    vertices[vertex] = -1;
    for(int i = 0; i < MAX_SIZE; i++){
        edges[vertex][i] = -1;
        edges[i][vertex] = -1;
    }
    size--;
}


void ADTGraph::removeEdge(int v1, int v2){
    if(vertices[v1] == -1 || vertices[v2] == -1){
        return;
    }
    edges[v1][v2] = -1;
}


bool ADTGraph::connected(int v1, int v2){
    if(vertices[v1] == -1 || vertices[v2] == -1){
        return false;
    }
    return (edges[v1][v2] > -1) ? true : false;
}


int* ADTGraph::neighbors(int vertex){
    
    if(vertices[vertex] == -1){
        return NULL;
    }
    int count = 0;
    for (int i = 0; i < MAX_SIZE; i++){
        if(edges[vertex][i] != -1){
            count++;
        }
    }

    int* neighbors = new int[count];

    for(int i = 0, count = 0; i < MAX_SIZE; i++){
        if(edges[vertex][i] != -1){
            neighbors[count] = i;
            count++;
        }
    }
    return neighbors;
}


void ADTGraph::setVertexValue(int vertex, int value){
    if(vertices[vertex] == -1){
        return;
    }
    vertices[vertex] = value;
}


int ADTGraph::getVertexValue(int vertex){
    if(vertices[vertex] == -1){
        return -1;
    }
    return vertices[vertex];
}


void ADTGraph::setEdgeValue(int v1, int v2, int value){
    if(vertices[v1] == -1 || vertices[v2] == -1){
        return;
    }
    edges[v1][v2] = value;
}


int ADTGraph::getEdgeValue(int v1, int v2){
    if(vertices[v1] == -1 || vertices[v2] == -1){
        return -1;
    }
    return edges[v1][v2];
}


int ADTGraph::sizeOfGraph(){
    return size;
}


void ADTGraph::printGraph(int size){
    for(int i = 0; i < size; i++){
        if(vertices[i] > -1){
            cout << "Vertex " << i << ": ";
            for(int j = 0; j < size; j++){
                if(edges[i][j] > -1){
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
}