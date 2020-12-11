#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct List {
    struct List * next;
    int value;
};

//struct MyList {
//    struct List lst;
//    short val;
//};
//struct MyList *m;
//m == &m->lst;

struct List * begin = NULL;

void append(int x) {
    ;
}

void push_front(int x) {
    /// Allocate new object
    struct List * ptr = calloc(1, sizeof(struct List));

    /// Push from
    ptr->next = begin;
    begin = ptr;

    /// Set value
    ptr->value = x;
}

void pop_front(size_t count) {
    if (count != 1) {
        exit(2); // TODO
    }
    if (begin == NULL) {
        return;
    }
    struct List * ptr = begin;
    begin = begin->next;

    free(ptr);
}

int is_empty() {
    return begin == NULL;
}

void clear() {
    while (!is_empty()) {
        pop_front(1);
    }
}

int main(int argc, const char ** argv) {
//    printf("%lu\n", sizeof(void));
//    void * p; ++p; /// BAN

//    TYPE * ptr;
//    ++ptr; ptr = ((char *)ptr)) + sizeof(type);

    struct List * ptr = calloc(1, sizeof(struct List));
    ptr->value == 0; ptr->next == 0;  /// Because calloc
    free(ptr);



}
