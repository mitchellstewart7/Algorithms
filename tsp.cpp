#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

//struct used to define a vertex in a graph
struct vertex
{
    bool in_graph;
    int key;
    int identifier;
    int x;
    int y;
};

//function that finds the index of the closest vertex to graph that has not yet been picked
int find_min(vertex * vertices, int num_vertices)
{
    int min_index;
    int min = 1000000;
    for (int i = 0; i < num_vertices; i++)
    {
        if (vertices[i].in_graph == false && vertices[i].key < min)
        {
            min = vertices[i].key;
            min_index = i;
        }   
    }
    return min_index;
}

//functions that calculates the approximate optimal distance for the travelling salesperson problem
//traversed array parameter tracks which vertices have been picked and in what order
int nearest_neighbor_total_distance(int num_vertices, ifstream & fin, int * traversed)
{
    vertex * vertices = new vertex[num_vertices];
    int total_weight = 0;
    for (int i = 0; i < num_vertices; i++) //for loop to fill vertices array with data from .txt file
    {
        vertex vert;
        vert.in_graph = false;
        vert.key = 100000;
        fin >> vert.identifier;
        fin >> vert.x;
        fin >> vert.y;
        vertices[i] = vert;
    }
    vertices[0].key = 0; //makes sure source vertex is picked first
    int picked; //tracks index of picked vertex
    for (int i = 0; i < num_vertices; i++)
    {
        picked = find_min(vertices, num_vertices);
        vertices[picked].in_graph = true;
        total_weight += vertices[picked].key;
        traversed[i] = vertices[picked].identifier;
        for (int j = 0; j < num_vertices; j++)
        {
            if (vertices[j].in_graph == false)
            {
                //find distance between vertex at index j and picked vertex
                vertices[j].key = round(sqrt(pow(vertices[j].x - vertices[picked].x, 2) + pow(vertices[j].y - vertices[picked].y, 2)));
            }
        }
    }
    //add distance from final vertex to source vertex to complete Hamiltonian path
    total_weight += round(sqrt(pow(vertices[0].x - vertices[picked].x, 2) + pow(vertices[0].y - vertices[picked].y, 2)));
    return total_weight;
}

//creates file I/O and reads/writes values to find distances and write outputs to .tour files
int main(int argc, char * argv[])
{
    ifstream fin;
    ofstream fout;
    string arg1 = argv[1];
    fin.open(arg1);
    fout.open(arg1 + ".tour");
    int num_vertices = 0;
    fin >> num_vertices;
    int * traversed = new int[num_vertices];
    fout << nearest_neighbor_total_distance(num_vertices, fin, traversed) << endl;
    for (int i = 0; i < num_vertices; i++)
    {
        fout << traversed[i] << endl;
    }
}