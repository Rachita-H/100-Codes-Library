#include <iostream>

#include <vector>

using namespace std;
/*
    C++ Program
    Boruvka's algorithm for minimum spanning trees
*/
class Edge
{
    public:
    // Edge weight or cost
    int weight;
    int dest;
    int src;
    Edge *next;

    Edge(int weight, int src, int dest)
    {
        this->weight = weight;
        this->dest = dest;
        this->src = src;
        this->next = NULL;
    }
};
class State
{
    public: int parent;
    int rank;
    State(int parent, int rank)
    {
        this->parent = parent;
        this->rank = rank;
    }
};
class Graph
{
    public: int vertices;
    vector < vector < Edge *> > graphEdge;
    Graph(int vertices)
    {
        this->vertices = vertices;

        for (int i = 0; i < this->vertices; ++i)
        {
            this->graphEdge.push_back(vector < Edge *> ());
        }
    }
    void addEdge(int src, int dest, int w)
    {
        if (dest < 0 || dest >= this->vertices ||
             src < 0 || src >= this->vertices)
        {
            return;
        }
        // add node edge
        this->graphEdge.at(src).push_back(new Edge(w, src, dest));
        if (dest == src)
        {
            return;
        }
        this->graphEdge.at(dest).push_back(new Edge(w, dest, src));
    }
    void printGraph()
    {
        cout << "\n Graph Adjacency List ";
        for (int i = 0; i < this->vertices; ++i)
        {
            cout << " \n [" << i << "] :";
            // iterate edges of i node
            for (int j = 0; j < this->graphEdge.at(i).size(); ++j)
            {
                cout << "  " << this->graphEdge.at(i).at(j)->dest;
            }
        }
    }
    int find(State **subsets, int i)
    {
        if (subsets[i]->parent != i)
        {
            subsets[i]->parent = this->find(subsets, subsets[i]->parent);
        }
        return subsets[i]->parent;
    }
    void findUnion(State **subsets, int x, int y)
    {
        int a = this->find(subsets, x);
        int b = this->find(subsets, y);
        if (subsets[a]->rank < subsets[b]->rank)
        {
            subsets[a]->parent = b;
        }
        else if (subsets[a]->rank > subsets[b]->rank)
        {
            subsets[b]->parent = a;
        }
        else
        {
            subsets[b]->parent = a;
            subsets[a]->rank++;
        }
    }
    void boruvkaMST()
    {
        // Contain weight sum in mst path
        int result = 0;
        int selector = this->vertices;
        State **subsets = new State*[this->vertices];
        Edge **cheapest = new Edge*[this->vertices];
        for (int v = 0; v < this->vertices; ++v)
        {
            subsets[v] = new State(v, 0);
        }
        while (selector > 1)
        {
            for (int v = 0; v < this->vertices; ++v)
            {
                cheapest[v] = NULL;
            }
            for (int k = 0; k < this->vertices; k++)
            {
                for (int i = 0; i < this->graphEdge.at(k).size(); ++i)
                {
                    int set1 = this->find(subsets,
                        this->graphEdge.at(k).at(i)->src);
                    int set2 = this->find(subsets,
                        this->graphEdge.at(k).at(i)->dest);
                    if (set1 != set2)
                    {
                        if (cheapest[k] == NULL)
                        {
                            cheapest[k] = this->graphEdge.at(k).at(i);
                        }
                        else if (cheapest[k]->weight >
                            this->graphEdge.at(k).at(i)->weight)
                        {
                            cheapest[k] = this->graphEdge.at(k).at(i);
                        }
                    }
                }
            }
            for (int i = 0; i < this->vertices; i++)
            {
                if (cheapest[i] != NULL)
                {
                    int set1 = this->find(subsets, cheapest[i]->src);
                    int set2 = this->find(subsets, cheapest[i]->dest);
                    if (set1 != set2)
                    {
                        // Reduce a edge
                        selector--;
                        this->findUnion(subsets, set1, set2);
                        // Display the edge connection
                        cout << "\n Include Edge ("
                             << cheapest[i]->src
                             << " - "
                             << cheapest[i]->dest
                             << ") weight "
                             << cheapest[i]->weight;
                        // Add weight
                        result += cheapest[i]->weight;
                    }
                }
            }
        }
        cout << "\n Calculated total weight of MST is "
             << result << endl;
    }
};
int main()
{
    Graph *g = new Graph(10);
    g->addEdge(0, 1, 7);
    g->addEdge(0, 7, 6);
    g->addEdge(0, 8, 4);
    g->addEdge(1, 2, 9);
    g->addEdge(1, 8, 6);
    g->addEdge(2, 3, 8);
    g->addEdge(2, 6, 12);
    g->addEdge(2, 9, 14);
    g->addEdge(3, 4, 16);
    g->addEdge(3, 9, 5);
    g->addEdge(4, 5, 15);
    g->addEdge(5, 6, 8);
    g->addEdge(5, 9, 7);
    g->addEdge(6, 7, 2);
    g->addEdge(6, 8, 10);
    g->addEdge(8, 9, 3);
    // Display graph element
    g->printGraph();
    // Find MST
    g->boruvkaMST();
    return 0;
}
