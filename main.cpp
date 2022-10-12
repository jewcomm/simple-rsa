#include <iostream>
#include <list>
#include <cmath>

using namespace std;

list<unsigned long long>::iterator foundBiggerSquare(list<unsigned long long> *vec, list<unsigned long long>::iterator iter);

unsigned long sieveOfErastosthenes(list<unsigned long long> *result, unsigned long long maximum){
    if(!result->empty()) return (unsigned long)-1;

    for(unsigned long long i = 2; i < maximum+1; i++){
        result->push_back(i);
    }

    for(auto base = result->begin(); base != result->end(); base = next(base)){
        for(auto canditate = (*next(base) <= 4? std::next(base): foundBiggerSquare(result, base)); canditate != result->end();){
            if(*canditate % *base == 0)
            {
                canditate = result->erase(canditate);
                if(canditate == std::prev(result->end())) break;
            }else{
                canditate = next(canditate);
            }
        }
    }
    return result->size();
}

list<unsigned long long>::iterator foundBiggerSquare(list<unsigned long long> *vec, list<unsigned long long>::iterator iter){
    unsigned long long square = pow(*iter, 2);
    for(;iter != vec->end(); iter= next(iter)){
        if(*iter >= square) return iter;
    }
    return vec->end();
}

int main() {
    list<unsigned long long> naturShisla;
    unsigned long res = sieveOfErastosthenes(&naturShisla, 100000);
    return 0;
}
