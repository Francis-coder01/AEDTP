#include "funWithDFS.h"


//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.1: Nodes at distance k (DFS)
//=============================================================================
// TODO
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res);
vector<Person> FunWithDFS::nodesAtDistanceDFS(const Graph<Person> *g, const Person &source, int k) {
    vector<Person> res;
    for(auto v : g->getVertexSet()){
        v->setVisited(false);
    }
    nodesAtDistanceDFSVisit(g,g->findVertex(source),k,res);
    return res;
}

// TODO
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res) {
    v->setVisited(true);
    if(k== 0){
        res.push_back(v->getInfo());
        return;
    }
    for(Edge<Person> e : v->getAdj()){
        if(!e.getDest()->isVisited())
        nodesAtDistanceDFSVisit(g,e.getDest(),k-1,res);
    }
}


//=============================================================================
// Exercise 2.3: Directed Acyclic Graph
//=============================================================================
// TODO
bool dfsIsDAG(Vertex<int> *v);
bool FunWithDFS::isDAG(Graph<int> g) {
    for(auto& v : g.getVertexSet()){
        v->setVisited(false);
        v->setProcessing(false);
    }
    for(auto& v : g.getVertexSet()){
        if(!v->isVisited())
            if(!dfsIsDAG(v)) return false;
    }
    return true;
}

// TODO
bool dfsIsDAG(Vertex<int> *v) {
    v->setVisited(true);
    v->setProcessing(true);
    for(Edge<int> e : v->getAdj()){
        if(e.getDest()->isProcessing()) return false;
        if(!e.getDest()->isVisited())
            if (!dfsIsDAG(e.getDest())) return false;
    }
    v->setProcessing(false);
    return true;
}
