#include <iostream>
#include <list>
#include <cmath>

using namespace std;

list<uint64_t>::iterator foundBiggerSquare(list<uint64_t> *vec, list<uint64_t>::iterator iter);

uint64_t findInBound(list<uint64_t>*source, uint64_t min, uint64_t max){
    if(source->empty() || (*prev(source->end()) < min)) return (uint64_t)-1;

    auto mMin = source->begin();
    auto mMax = source->end();
}

uint32_t sieveOfErastosthenes(list<uint64_t> *result, uint64_t maximum){
    if(!result->empty()) return (uint32_t)-1;

    for(uint64_t i = 2; i < maximum+1; i++){
        result->push_back(i);
    }

    for(auto base = result->begin(); base != result->end(); base = next(base)){
        for(auto canditate = (*next(base) <= 4? next(base): foundBiggerSquare(result, base));
                canditate != result->end();
                canditate = (*canditate % *base == 0) ? result->erase(canditate) : next(canditate));
    }
    return result->size();
}

list<uint64_t>::iterator foundBiggerSquare(list<uint64_t> *vec, list<uint64_t>::iterator iter){
    uint64_t square = pow(*iter, 2);
    for(;iter != vec->end(); iter= next(iter)){
        if(*iter >= square) return iter;
    }
    return vec->end();
}

uint64_t Euler (uint64_t n) {
    uint64_t result = n;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    list<uint64_t> naturShisla;
    unsigned long res = sieveOfErastosthenes(&naturShisla, 100000);

    uint64_t p = 6199;
    uint64_t q = 6737;
    uint64_t n = p * q;
    uint64_t On = (p-1)*(q-1);
    uint64_t resEuler = Euler(On);

    return 0;
}
