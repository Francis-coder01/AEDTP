#include "funWithComplexity.h"

//=============================================================================
// Exercise 4: Analyzing a river
//=============================================================================
// TODO
int FunWithComplexity::river(const vector<int> & v, int k, int t) {
    int num1 = 0;
    int num = 0;
    for (int i = 0; i < k; i++){
        if(v[i] > t) num1 ++;
    }
    if ( k/2 <= num1) num++;
    for (int i = k; i <= v.size(); i++){
        if (v[i-k] >= t) num--;
        if (v[i] >= t) num++;
    }
    return num;
}

//=============================================================================
// Exercise 5: Spiral of Numbers
//=============================================================================
// TODO
pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};
    return ans;
}


//=============================================================================
// Exercise 7: Squared notebook
//=============================================================================
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}