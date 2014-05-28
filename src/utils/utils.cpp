
#include "utils.h"

int count_elapse_microsecond(const std::function<void ()> & f)
{
    using namespace std::chrono;

    time_point<system_clock> start, end;

    start = system_clock::now();
    f();
    end = system_clock::now();
    return duration_cast<microseconds>(end-start).count();
}
