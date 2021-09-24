#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h>

using namespace std;

struct vertex
{
    bool in_mst;
    int key;
    int x;
    int y;
};

int find_min(vertex * vertices, int num_vertices)
{
    int min_index;
    int min = 1000000;
    for (int i = 0; i < num_vertices; i++)
    {
        if (vertices[i].in_mst == false && vertices[i].key < min)
        {
            min = vertices[i].key;
            min_index = i;
        }   
    }
    return min_index;
}

int calc_mst_weight(int num_vertices, ifstream & fin)
{
    vertex * vertices = new vertex[num_vertices];
    int total_weight = 0;
    for (int i = 0; i < num_vertices; i++)
    {
        vertex vert;
        vert.in_mst = false;
        vert.key = 100000;
        fin >> vert.x;
        fin >> vert.y;
        vertices[i] = vert;
    }
    vertices[0].key = 0;
    for (int i = 0; i < num_vertices; i++)
    {
        int picked = find_min(vertices, num_vertices);
        vertices[picked].in_mst = true;
        total_weight += vertices[picked].key;
        for (int j = 0; j < num_vertices; j++)
        {
            if (vertices[j].in_mst == false)
            {
                vertices[j].key = round(sqrt(pow(vertices[j].x - vertices[picked].x, 2) + pow(vertices[j].y - vertices[picked].y, 2)));
            }
        }
    }
    return total_weight;
}

int main()
{
    ifstream fin;
    fin.open("graph.txt");
    int num_cases = 0;
    fin >> num_cases;
    for (int i = 0; i < num_cases; i++)
    {
        int num_vertices = 0;
        fin >> num_vertices;
        cout << "Test case " << i + 1 << ": MST weight " << calc_mst_weight(num_vertices, fin) << endl;
        cout << endl;
    }
}