int func(int x, int y) {
    int z;
    if (__builtin_sadd_overflow(x, y, &z) == 0) {
        return 0;
    } else {
        return 1;
    }
}
