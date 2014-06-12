#ifndef FFSAE_UTILS_H
#define FFSAE_UTILS_H

#include<chrono>
#include <functional>

int count_elapse_microsecond(const std::function<void ()> & f);
int count_elapse_second(const std::function<void ()> & f);

#endif // UTILS_H
