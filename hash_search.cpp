#include <cstdlib>
#include <iostream>

#define MAX 6
#define HASHMAX 5

int data[MAX] = {1, 10, 15, 5, 8, 7};

typedef struct list {
    int key;
    struct list* next;
} node,
    *link;

node hashtab[HASHMAX];

int h(int key) { return key % HASHMAX; }

void create_list(int key) {
    link p, n;
    int index;
    n = (link)malloc(sizeof(node));
    n->key = key;
    n->next = NULL;
    index = h(key);
    p = hashtab[index].next;
    if (p != NULL) {
        n->next = p;
        hashtab[index].next = n;
    } else {
        hashtab[index].next = n;
    }
}

int hash_search(int key, int* counter) {
    link pointer;
    int index;

    *counter = 0;
    index = h(key);
    pointer = hashtab[index].next;

    std::cout << "data[" << index << "]:";

    while (pointer != NULL) {
        counter[0]++;
        std::cout << "data[" << pointer->key << "]:";
        if (pointer->key == key)
            return 1;
        else
            pointer = pointer->next;
    }

    return 0;
}

int main() {
    link p;
    int key, index, i, counter;
    index = 0;

    while (index < MAX) {
      create_list(data[index]);
        index++;
    }

    for (i = 0; i < HASHMAX; i++) {
        std::cout << "hashtab [" << i << "]\n";

        p = hashtab[i].next;

        while (p != NULL) {
            std::cout << "please int key:";
            if (p->key > 0)
                std::cout << "[" << p->key << "]";
            p = p->next;
        }
        std::cout << std::endl;
    }

    while (key != -1) {
        key = 10;
        if (hash_search(key, &counter))
            std::cout << "search time = " << counter << std::endl;
        else
            std::cout << "no found!\n";
        key = -1;
    }

    return 0;
}
