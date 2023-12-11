#include "funWithGraphs.h"

//=============================================================================
// Exercise 2.1: Connected Components
//=============================================================================
// TODO
void dfsVisit(Vertex<int> *v);
int funWithGraphs::connectedComponents(Graph<int> *g) {
    int count = 0;
    for(auto v : g->getVertexSet()){
        for(Edge<int> e : v->getAdj()){
            g->addEdge(e.getDest()->getInfo(),v->getInfo(),e.getWeight());
        }
        v->setVisited(false);
    }
    for(auto v: g->getVertexSet()){
        if(!v->isVisited()){
            count++;
            v->setVisited(true);
            dfsVisit(v);
        }
    }
    return count;
}

void dfsVisit(Vertex<int> *v) {
    v->setVisited(true);
    for (auto & e : v->getAdj()) {
        auto w = e.getDest();
        if (!w->isVisited())
            dfsVisit(w);
    }
}


//=============================================================================
// Exercise 2.2: Giant Component
//=============================================================================
// TODO
int dfsGC(Vertex<int> *v);
int funWithGraphs::giantComponent(Graph<int> *g) {
    int maxs = 0;
    for(auto v : g->getVertexSet()){
        for(Edge<int> e : v->getAdj()){
            g->addEdge(e.getDest()->getInfo(),v->getInfo(),e.getWeight());
        }
        v->setVisited(false);
    }
    for(auto v: g->getVertexSet()){
        if(!v->isVisited()){
            v->setVisited(true);
            maxs = max(maxs,dfsGC(v));
        }
    }
    return maxs;
}

int dfsGC(Vertex<int> *v) {
    int ret = 1;
    v->setVisited(true);
    for (auto & e : v->getAdj()) {
        auto w = e.getDest();
        if (!w->isVisited())
            ret += dfsGC(w);
    }
    return ret;
}


//=============================================================================
// Exercise 2.3: Strongly Connected Components
//=============================================================================
// TODO
void dfs_scc(Graph<int> *g, Vertex<int> *v, stack<int> &s, list<list<int>> &l, int &i);
list<list<int>> funWithGraphs::scc(Graph<int> *g){
    list<list<int>> res;
    int index = 1;
    stack<int> aux;
    for(auto v : g->getVertexSet()){
        v->setNum(0);
        v->setLow(0);
    }
    for(auto v : g->getVertexSet()){
        if(!v->getNum()) dfs_scc(g,v,aux,res,index);
    }
    return res;
}

void dfs_scc(Graph<int> *g, Vertex<int> *v, stack<int> &s, list<list<int>> &l, int &i){
    v->setLow(i);
    v->setNum(i);
    i++;
    s.push(v->getInfo());
    for(Edge<int> e : v->getAdj()){
        if(!e.getDest()->getNum())
            dfs_scc(g,w,s,l,i);
    }
}


//=============================================================================
// Exercise 2.4: Articulation Points
//=============================================================================
// TODO
void dfs_art(Graph<int> *g, Vertex<int> *v, stack<int> &s, unordered_set<int> &res, int &i);
unordered_set<int> funWithGraphs::articulationPoints(Graph<int> *g) {
    unordered_set<int> res;

    return res;
}

void dfs_art(Graph<int> *g, Vertex<int> *v, stack<int> &s, unordered_set<int> &l, int &i){}