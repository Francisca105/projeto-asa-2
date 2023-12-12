#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

enum {
    WHITE,
    GRAY,
    BLACK
};

class Vertice {
    private:
        int d; // tempo de descoberta
        int f; // tempo de fim
        int pred; // antecede
        int color; 
        int id;
        int scc; // 
    public:
        Vertice(int id) {
            this->setD(0);
            this->setF(0);
            this->setPred(0);
            this->setColor(WHITE);
            this->setId(id);
            this->setScc(-1);
        }

        int getD() {return this->d;}
        int getF() {return this->f;}
        int getPred() {return this->pred;}
        int getColor() {return this->color;}
        int getId() {return this->id;}
        int getScc() {return this->scc;}

        void setD(int d) {this->d = d;}
        void setF(int f) {this->f = f;}
        void setPred(int pred) {this->pred = pred;}
        void setColor(int color) {this->color = color;}
        void setId(int id) {this->id = id;}
        void setScc(int scc) {this->scc = scc;}
};

class Grafo {
    private:
        std::vector<Vertice*> *vertices;
        std::list<int> *fwdAdjList;
        std::list<int> *revAdjList;
    
    public:
        Grafo(int V) {
            this->vertices = new std::vector<Vertice*>;
            for (int i=0; i<V; i++) {
                vertices->push_back(new Vertice(i+1));
            }
            this->fwdAdjList = new std::list<int>[V];
            this->revAdjList = new std::list<int>[V];
        }

        std::vector<Vertice*>* getVertices() {return this->vertices;}
        std::list<int>* getFwdAdjList() {return this->fwdAdjList;}
        std::list<int>* getRevAdjList() {return this->revAdjList;}
};

bool compareVertices(Vertice* v, Vertice *u) {
    return (v->getF()) > (u->getF());
}

int DFS_Visit(Grafo *grafo, Vertice *v, int time) {
    v->setColor(GRAY);
    time++;
    v->setD(time);
    std::vector<Vertice*> *vertices = grafo->getVertices();
    std::list<int> *fwdAdjList = grafo->getFwdAdjList();
    int id = v->getId();
    for (auto it = fwdAdjList[id-1].begin(); it != fwdAdjList[id-1].end(); it++) {
        Vertice *u = vertices->at(*it);
        if (u->getColor() == WHITE) {
            u->setPred(id);
            time = DFS_Visit(grafo, u, time);
        }
    }
    v->setColor(BLACK);
    time++;
    v->setF(time);
    return time; 
}

int DFS_Visit2(Grafo *grafo, Vertice *v, int time, int scc, std::vector<int> *sccs) {
    v->setColor(GRAY);
    time++;
    v->setD(time);
    std::vector<Vertice*> *vertices = grafo->getVertices();
    std::list<int> *revAdjList = grafo->getRevAdjList();    

    int id = v->getId();
    for (auto it = revAdjList[id-1].begin(); it != revAdjList[id-1].end(); it++) {
        Vertice *u = vertices->at(*it);
        printf("  Vertice vizinho: %d\n", u->getId());
        if (u->getColor() == WHITE) {
            u->setPred(id);
            u->setScc(scc);
            time = DFS_Visit2(grafo, u, time, scc, sccs);
        }
    }
    v->setColor(BLACK);
    time++;
    v->setF(time);
    return time; 
}

void DFS(Grafo *grafo) {
    std::vector<Vertice*> *vertices = grafo->getVertices();
    int time = 0;
    for (Vertice *v: *vertices) {
        if (v->getColor() == WHITE) {
            time = DFS_Visit(grafo, v, time);
        }
    }
}

void DFS2(Grafo *grafo) {
    std::vector<Vertice*> *vertices = grafo->getVertices();
    std::vector<int> *sccs = new std::vector<int>;
    int time = 0, scc = 0;
    for (Vertice *v: *vertices) {
        printf("Vertice: %d\n", v->getId());
        if (v->getColor() == WHITE) {
            v->setScc(scc);
            sccs->push_back(0);
            time = DFS_Visit2(grafo, v, time, scc, sccs);
        }
    }
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

    // for(int i = 0; i < V; i++){
    //     printf("%d ", i+1);
    //     if (fwdAdjList[i].size() != 0) {
    //         for (auto it = fwdAdjList[i].begin(); it != fwdAdjList[i].end(); it++) {
    //             printf("-> %d", *it + 1);
    //         }
    //         printf("\n");
    //     } else {printf("\n");}

    // }
    
    // printf("\n\n");

    // for(int i = 0; i < V; i++){
    //     printf("%d ", i+1);
    //     if (revAdjList[i].size() != 0) {
    //         for (auto it = revAdjList[i].begin(); it != revAdjList[i].end(); it++) {
    //             printf("-> %d ", *it + 1);
    //         }
    //         printf("\n");
    //     } else printf("\n");
        
    // }

    DFS(grafo);

    // for (int i=0; i<V; i++) {
    //     printf("**Vertice - 1\n");
    //     printf("  Id: %d\n", (*vertices)[i]->getId());
    //     printf("  D: %d\n", (*vertices)[i]->getD());
    //     printf("  F: %d\n", (*vertices)[i]->getF());
    //     printf("  Color: %d\n", (*vertices)[i]->getColor());
    //     printf("  Pred: %d\n", (*vertices)[i]->getPred());
    //     printf("  SCC: %d\n", (*vertices)[i]->getScc());
    // }

    // printf("\n\n");
    // for (int i=0; i<V; i++) {
    //     for (auto it = fwdAdjList[i].begin(); it != fwdAdjList[i].end(); it++) {
    //         printf("%d -> %d\n", i+1, *it + 1);
    //     }
    // }

    // printf("\n\n");
    // for (int i=0; i<V; i++) {
    //     for (auto it = revAdjList[i].begin(); it != revAdjList[i].end(); it++) {
    //         printf("%d -> %d\n", i+1, *it + 1);
    //     }
    // }

    sort(vertices->begin(), vertices->end(), compareVertices);
    
    for (int i=0; i<V; i++) {
        (*vertices)[i]->setColor(WHITE);
    }
    
    DFS2(grafo);

    printf("\n\n");
    for (int i=0; i<V; i++) {
        printf("**Vertice - 2**\n");
        printf("  Id: %d\n", (*vertices)[i]->getId());
        printf("  D: %d\n", (*vertices)[i]->getD());
        printf("  F: %d\n", (*vertices)[i]->getF());
        printf("  Color: %d\n", (*vertices)[i]->getColor());
        printf("  Pred: %d\n", (*vertices)[i]->getPred());
        printf("  SCC: %d\n", (*vertices)[i]->getScc());
    }

    return 0;
}