#include <functional>
#include <iostream>
#include <cmath>

void caller(std::function<int (unsigned)> f, unsigned x) {
    f(x);
}

//template <class Func, class Arg>
//void template_caller(Func func, Arg arg) {
//    func(arg);
//}

template <class Func, class ... Args>
void template_caller(Func func, Args ... args) {
    func(args...);
}

int my_f(unsigned z) {
    std::cerr << "Hell\n" << z << '\n';
    return -1;
}

int main() {
    caller(std::function(my_f), 2);

    template_caller(my_f, 3);

    template_caller(sin, 0.3);
}
