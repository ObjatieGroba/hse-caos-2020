#include <thread>
#include <mutex>
#include <iostream>
#include <string>
#include <future>

std::mutex mx;


std::mutex mx1;
std::mutex mx2;
std::mutex mx3;

//void func(int num, std::string s) {
//    std::cout << "Hello\n";
//    for (int i = 0; i != 100; ++i) {
//        // .lock() в конструкторе
//        // .unlock() в деструкторе
//        std::lock_guard<std::mutex> lg(mx);
//
////        std::unique_lock<std::mutex> ul(mx);
////        ul.unlock();
//
//        std::lock(mx1, mx2, mx3);
//
//        std::cout << num << ' ' << s << std::endl;
//
//        mx1.unlock();
//        mx2.unlock();
//        mx3.unlock();
//    }
//}

void func(int num, std::promise<int> &prm) {
//    try {
//        throw std::runtime_error("Error");
//    } catch (std::exception &e) {
//        prm.set_exception(e);
//    }
    prm.set_value(num + 1);
//    prm.set_exception({});
}

int just_func(int x) {
//    throw std::runtime_error("Bad");
    return x * x;
}

int main() {
//    int x = 3;
//    std::thread t1(func, x, "abcd");
//    x = 4;
//    std::thread t2(func, x, "abcd");

//    t1.join();
//    t2.join();

    std::promise<int> prm;
    std::thread t1(func, 4, std::ref(prm));

//    std::cout << prm.get_future().valid() << std::endl;
    auto future_ = prm.get_future();
    std::cout << future_.get() << std::endl;

    t1.join();


    auto future = std::async(just_func, -23);
    std::cout << future.get() << std::endl;

//    std::tuple<int, std::string, uint32_t> t;
//    std::pair<int, int> p;
//    struct My {
//        int x;
//        int y;
//    } my_value{};
}
