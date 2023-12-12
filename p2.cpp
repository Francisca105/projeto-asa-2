#include <stdio.h>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

class Vertice {
    private:
        int f;  // tempo de fim
        int id; // id do vertice
        int scc; // componente fortemente ligada
    
    public:
        Vertice(int id) {
            this->setF(0);
            this->setId(id);
            this->setScc(0);
        }

        int getF() {return this->f;}
        int getId() {return this->id;}
        int getScc() {return this->scc;}

        void setF(int f) {this->f = f;}
        void setId(int id) {this->id = id;}
        void setScc(int scc) {this->scc = scc;}
};

class Grafo {
    private:
        std::vector<Vertice*> *vertices;    // vector de vértices
        std::list<int> *fwdAdjList;         // lista de adjacencias
        std::list<int> *revAdjList;         // lista de adjacencias do grafo transposto
    
    public:
        Grafo(int V) {
            this->vertices = new std::vector<Vertice*>(V);
            for (int i=0; i<V; i++) {
                (*vertices)[i] = new Vertice(i);
            }
            this->fwdAdjList = new std::list<int>[V];
            this->revAdjList = new std::list<int>[V];
        }
        
        std::vector<Vertice*> *getVertices() {return this->vertices;}
        std::list<int> *getFwdAdjList() {return this->fwdAdjList;}
        std::list<int> *getRevAdjList() {return this->revAdjList;}
};

bool compareVertices(Vertice *u, Vertice *v) {
    return u->getF() > v->getF();
}

void DFS(Grafo *grafo, int V) {
    std::vector<Vertice*> *vertices = grafo->getVertices();
    std::list<int> *AdjList = grafo->getFwdAdjList();

    std::vector<int> visited(V, 0);
    std::stack<int> dfsStack;
    int time = 1;
    for (Vertice *v : *vertices) {
        int check = 0, id = v->getId();
        if (!visited[id]) {
            dfsStack.push(id);
            visited[id] = 1;
            while (!dfsStack.empty()) {
                int top = dfsStack.top();
                check = 0;
                for (int it : AdjList[top]) {
                    if (!visited[it]) {
                        dfsStack.push(it);
                        visited[it] = 1;
                        check = 1;
                        break;
                    }
                }
                if (!check) {
                    vertices->at(dfsStack.top())->setF(time++);
                    dfsStack.pop();
                }
            }
        }
    }
}

int DFS2(Grafo *grafo, int V, std::vector<int> indexes) {
    std::vector<Vertice*> *vertices = grafo->getVertices();
    std::list<int> *AdjList = grafo->getRevAdjList();
    std::vector<int> visited(V, 0);
    std::stack<int> dfsStack;
    std::vector<int> sccs;
    int time = 1, scc = -1;
    for (Vertice *v : *vertices) {
        int check = 0, id = v->getId();
        if (!visited[id]) {
            sccs.push_back(0);
            scc++;
            dfsStack.push(id);
            visited[id] = 1;
            vertices->at(indexes[id])->setScc(scc);
            while (!dfsStack.empty()) {
                int top = dfsStack.top();
                check = 0;
                for (int it : AdjList[top]) {
                    Vertice *u = vertices->at(indexes[it]);
                    if (!visited[it]) {
                        dfsStack.push(it);
                        visited[it] = 1;
                        u->setScc(scc);
                        check = 1;
                        break;
                    } else {
                        if (scc != u->getScc()) {
                            sccs[scc] = std::max(sccs[scc], sccs[u->getScc()] + 1);
                        }
                    }
                }
                if (!check) {
                    vertices->at(indexes[dfsStack.top()])->setF(time++);
                    dfsStack.pop();
                }
            }
        }
    }
    int max = 0;
    for (long unsigned int i=0; i<sccs.size(); i++) {
        max = std::max(max, sccs[i]);
    }
    return max;
}

int main() {

    int V, E;
    scanf("%d %d", &V, &E);

    Grafo *grafo = new Grafo(V);
    std::vector<Vertice*> *vertices = grafo->getVertices();
    std::list<int> *fwdAdjList = grafo->getFwdAdjList();
    std::list<int> *revAdjList = grafo->getRevAdjList();

    for (int i=0; i<E; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        fwdAdjList[x-1].push_back(y-1);
        revAdjList[y-1].push_back(x-1);
    }


    DFS(grafo, V);

    std::sort(vertices->begin(), vertices->end(), compareVertices);
    std::vector<int> indexes(V);
    for (int i=0; i<V; i++) {
        indexes[vertices->at(i)->getId()] = i;
    }
    
    int max = DFS2(grafo, V, indexes);

    printf("%d\n", max);

    return 0;
}
