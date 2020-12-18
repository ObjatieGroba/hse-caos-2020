#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

struct Tree {
    struct Tree *left;
    struct Tree *right;

    unsigned value;
};

struct Tree* search(unsigned to_find, struct Tree** node_) {
    if (!node_) {
        return NULL;
    }
    if (!(*node_)) {
        return NULL;
    }
    struct Tree* node = *node_;
    if (node->value == to_find) {
        return node;
    }
    if (to_find < node->value) {
        return search(to_find, &node->left);
    }
    return search(to_find, &node->right);
}

struct Tree nodes[1000];

void func_print(int x, int y) {
    printf("%d %d\n", x, y);
//    _exit(0);
//    exit(0);
}

int main() {
    struct Tree node1 = {};
    struct Tree node2 = {};
    struct Tree node3 = {};

    node1.value = 1;
    node2.value = 2;
    node3.value = 3;
    node2.left = &node1;
    node2.right = &node3;

    struct Tree *root = &node2;

    search(4, &root);

    char data[4];

    char * buf = data;
    buf[1];  /// Индексация
    *(buf + 1);  /// Same

    *buf = *buf;

    uint64_t a;
    uint32_t b = 0x1f0000, c = 0x2f0000;

    a = (uint64_t)b * c;  // Same as (uint64_t)b * (uint64_t)c

    printf("%x %x %lx\n", b, c, a);


//    unsigned f = 0;
//    func_print(f++, ++f);  // PLEASE DO NOT
//
//    f = 0;
//    func_print(++f, f++);  // PLEASE DO NOT

//    char bigbuf[1000];
//    memcpy(bigbuf, func_print, sizeof(bigbuf));

    char * bigbuf = malloc(1000);
    memcpy(bigbuf, func_print, 1000);

    void * func = bigbuf;

    ((void (*)(int, int))(func))(4, 5);
}


