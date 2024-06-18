#pragma once

#include <iostream>
#include <format>
#include <signal.h>

#define RASSERT(expr, reason, ...)                                                                                                                                                 \
    if (!(expr)) {                                                                                                                                                                 \
        std::cout << std::format("\n==========================================================================================\nASSERTION FAILED! \n\n{}\n\nat: line {} in {}",    \
                                 std::format(reason, ##__VA_ARGS__), __LINE__,                                                                                                     \
                                 ([]() constexpr -> std::string { return std::string(__FILE__).substr(std::string(__FILE__).find_last_of('/') + 1); })());                         \
        std::cout << "[Aquamarine] Assertion failed!";                                                                                                                             \
        raise(SIGABRT);                                                                                                                                                            \
    }

#define ASSERT(expr) RASSERT(expr, "?")