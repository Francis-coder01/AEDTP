#include "funWithBFS.h"


//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.2: Nodes at distance k (BFS)
//=============================================================================
// TODO
vector<Person> FunWithBFS::nodesAtDistanceBFS(const Graph<Person> *g, const Person &source, int k) {
    vector<Person> res;
    for(auto v : g->getVertexSet()){
        v->setVisited(false);
    }
    Vertex<Person> * v = g->findVertex(source);
    queue<pair<Vertex<Person>*,int>> aux;
    // HINT: Use the flag "visited".
    // HINT: Use the "queue" class to temporarily store the vertices.
    if(v == nullptr) return res;
    aux.emplace(v,0);
    v->setVisited(true);
    while(!aux.empty()){
        auto node = aux.front();
        aux.pop();
        if(node.second == k) res.push_back(node.first->getInfo());
        for(Edge<Person> e : node.first->getAdj()){
            if(!e.getDest()->isVisited()){
                aux.emplace(e.getDest(),node.second+1);
                e.getDest()->setVisited(true);
            }
        }
    }
    return res;
}

//=============================================================================
// Exercise 2.2: Max New Children
//=============================================================================
// TODO
int FunWithBFS::maxNewChildren(const Graph<Person> *g, const Person &source, Person &info) {
    int res = 0;
    for(auto v : g->getVertexSet()){
        v->setVisited(false);
    }
    Vertex<Person> * v = g->findVertex(source);
    queue<Vertex<Person>*> aux;
    // HINT: Use the flag "visited".
    // HINT: Use the "queue" class to temporarily store the vertices.
    if(v == nullptr) return res;
    aux.push(v);
    v->setVisited(true);
    while(!aux.empty()){
        auto node = aux.front();
        aux.pop();
        int count = 0;
        for(Edge<Person> e : node->getAdj()){
            if(!e.getDest()->isVisited()){
                count++;
                aux.emplace(e.getDest());
                e.getDest()->setVisited(true);
            }
        }
        if(count > res){
            res = count;
            info = node->getInfo();
        }
    }
    return res;}
