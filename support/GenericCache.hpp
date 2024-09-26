#pragma once
#include <map>
#include <vector>
using namespace std;
template <typename E, typename S>
class GenericCache
{
private:
    map<S, E> cache;
    GenericCache();
public:
    static GenericCache<E,S>* getInstance();
    void put(S id, E entity);
    E get(S id);
    void remove(S id);
    map<S, E> getAll();
    void setAll(map<S, E> cache);
    vector<E> getValues();
};

template <typename E, typename S>
GenericCache<E,S>::GenericCache() {}

template <typename E, typename S>
GenericCache<E,S>* GenericCache<E,S>::getInstance() {
    static GenericCache<E,S>* instance;
    if(instance==NULL) instance = new GenericCache<E,S>();
    return instance;
}

template <typename E, typename S>
void GenericCache<E,S>::put(S id, E entity) {
    cache[id] = entity;
}

template <typename E, typename S>
E GenericCache<E,S>::get(S id) {
    return cache[id];
}

template <typename E, typename S>
void GenericCache<E,S>::remove(S id) {
    cache.erase(id);
}

template <typename E, typename S>
map<S,E> GenericCache<E,S>::getAll() {
    return cache;
}

template <typename E, typename S>
void GenericCache<E,S>::setAll(map<S, E> cache) {
    this->cache = cache;
}

template <typename E, typename S>
vector<E> GenericCache<E,S>::getValues() {
    vector<E> values;
    for(const auto& pair : cache) {
        values.push_back(pair.second);
    }
    return values;
}

