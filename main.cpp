#include <iostream>
#include <list>
#include <vector>

using namespace std;

unsigned long sieveOfErastosthenes(vector<unsigned long long> *result, unsigned long long maximum){
    if(!result->empty()) return (unsigned long)-1;

    for(unsigned long long i = 2; i < maximum+1; i++){
        result->push_back(i);
    }

    for(auto base = result->begin(); base != result->end(); base++){
        for(auto canditate = base+1; canditate != result->end(); canditate++){
            if(*canditate % *base == 0)
            {
                if(result->erase(canditate) == result->end()) break;
            }
        }
    }

    return result->size();
}

int main() {
    vector<unsigned long long> naturShisla;
    unsigned long res = sieveOfErastosthenes(&naturShisla, 30);
    return 0;
}
