#include "funWithCycles.h"

//=============================================================================
// Exercise 1: Palindromes
//=============================================================================
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    unsigned length = s.size();
    // c) at step i, os i-1 caracteres sao iguais ais ultimos i-1 caracteres da string
    // d) length-i
    for (unsigned i = 0; i < length/2; i++)
        if (s[i] != s[length-i-1])
            return false;
    return true;
}


//=============================================================================
// Exercise 2: Palindrome Sentences
//=============================================================================
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    std::string dummy;
    for (char c : s)
        if (isalpha(c))
            dummy += (tolower(c));
    return palindrome(dummy);
}


//=============================================================================
// Exercise 3: Interesting Numbers
//=============================================================================
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    while(true){
        n+=1;
        if(digitSum(n) == sum) return n;

    }
}

// This auxiliary function should return the sum of the digits of n
// TODO
int FunWithCycles::digitSum(int n) {
    int sum_n = 0;
    while(n > 0){
        sum_n += n %10;
        n /= 10;
    }
    return sum_n;
}



//=============================================================================
// Exercise 4: Winter is coming
//=============================================================================
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    if (v.empty()) return 0;
    int maxsequence = 0;
    int currsequence = 0;
    for (unsigned i = 0; i < v.size()-1; i++){
        if (v[i] > v[i+1]) currsequence += 1;
        else {
            if (currsequence > maxsequence) maxsequence = currsequence;
            currsequence = 0;
        }
    }
    if (currsequence > maxsequence) maxsequence = currsequence;
    return maxsequence;
}


//=============================================================================
// Exercise 5: Playing with vectors
//=============================================================================

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    return 0;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    return false;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {

}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    return ans;
}


//=============================================================================
// Exercise 6: Playing with prime numbers
//=============================================================================

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    return false;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    return ans;
}
