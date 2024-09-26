#pragma once
#include <vector>
#include "GenericCache.hpp"
using namespace std;

template <typename S>
struct Entity {
    S id;
    S getId() {return id;}
    void setId(S id) {this->id = id;}
};

template <typename E, typename S>
class Repository {
public:
    static long insert(E* entity);
    static void update(E* entity);
    static void remove(E* entity);
    static void remove(S id);
    static E* load(S id);
    static vector<E*> loadAll(E* entity);
    static vector<E*> load(const vector<S>& ids);
    static S nextId();
};

template <typename E, typename S>
typename enable_if<is_base_of<Entity<S>, E>::value, Repository<E, S>>::type
createEntity() {
    return Repository<E, S>();
}

template <typename E, typename S>
long Repository<E, S>::insert(E* entity) {
    GenericCache<E*, S>* cache = GenericCache<E*, S>::getInstance();
    cache->put(entity->getId(), entity);
    return entity->getId();
}

template <typename E, typename S>
void Repository<E, S>::update(E* entity) {
    GenericCache<E*, S>* cache = GenericCache<E*, S>::getInstance();
    cache->put(entity->getId(), entity);
}

template <typename E, typename S>
void Repository<E, S>::remove(E* entity) {
    GenericCache<E*, S>* cache = GenericCache<E*, S>::getInstance();
    vector<E*> entities = loadAll(entity);
    for (E* e : entities) {
        cache->remove(e->getId());
    }
}

template <typename E, typename S>
void Repository<E, S>::remove(S id) {
    GenericCache<E*, S>* cache = GenericCache<E*, S>::getInstance();
    cache->remove(id);
}

template <typename E, typename S>
E* Repository<E, S>::load(S id) {
    GenericCache<E*, S>* cache = GenericCache<E*, S>::getInstance();
    return cache->get(id);
}

template <typename E, typename S>
vector<E*> Repository<E, S>::loadAll(E* entity) {
    GenericCache<E*, S>* cache = GenericCache<E*, S>::getInstance();
    if(entity == NULL) {return cache->getValues();}
    vector<E*> entities;
    for (const auto value : cache->getValues()) {
        if (entity == value) 
            entities.push_back(value);
    }
    return entities;
}

template <typename E, typename S>
vector<E*> Repository<E, S>::load(const vector<S>& ids) {
    GenericCache<E*, S>* cache = GenericCache<E*, S>::getInstance();
    vector<E*> entities;
    for (S id : ids) {
        entities.push_back(cache->get(id));
    }
    return entities;
}

template <typename E, typename S>
S Repository<E, S>::nextId() {
    GenericCache<E, S>* cache = GenericCache<E, S>::getInstance();
    map<S, E> entities = cache->getAll();
    S maxId = 0;
    for( auto it = entities.rbegin(); it != entities.rend(); ++it ) {
        if (it->first > maxId) {
            maxId = it->first;
        }
    }
    return maxId + 1;
}

