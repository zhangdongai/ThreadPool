#include <chrono>
#include <iostream>
#include <string>

#include "thread_pool.h"

void exec_f_g() {
    std::cout << "exec_f_g is called" << std::endl;
}

void exec_f_p(int param) {
    std::cout << "exec_f_p is caled " << param << std::endl;
}

class T {
public:
    static void exec_f_l(T* t, std::string& s) {
        std::cout << "exec_f_l is called " << t->data_ << std::endl;
    }

    int32_t data_;
};

int32_t main(int32_t argc, char** argv) {
    ThreadPool tp(2);
    tp.push(exec_f_g);
    tp.push(exec_f_p, 2);
    T t;
    t.data_ = 1314;
    std::string s = "exec_f_l";
    tp.push(&T::exec_f_l, &t, s);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return 0;
}