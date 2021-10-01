template <class K, class V>
class Node {
    int hash;
    K *key;
    V *value;
    Node *next;
};

template <class K, class V>
class DuoHashTable {
protected:
    int nbuckets;
    Node<K,V> **buckets;

public:
    DuoHashTable(int nbuckets) {
        this->nbuckets = nbuckets;
        this->buckets = new Node<K,V>*[nbuckets];
    }
};
