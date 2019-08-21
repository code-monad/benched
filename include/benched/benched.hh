#ifndef __PARA_BENCH_BASE_HH__
#define __PARA_BENCH_BASE_HH__

#include <chrono>
#include <utility>

namespace bench {
  template <typename _Tick_T = std::chrono::milliseconds, typename _Func_T, typename ...Args>
  const std::pair<_Tick_T, typename std::result_of<_Func_T(Args...)>::type> bench_base(_Func_T func, Args... args){
    auto start = std::chrono::high_resolution_clock::now();
    auto result = func(args...);
    auto end = std::chrono::high_resolution_clock::now();
    return std::make_pair(std::chrono::duration_cast<_Tick_T>(end-start), result);
  }
}


#endif
