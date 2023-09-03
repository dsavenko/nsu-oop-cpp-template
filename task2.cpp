
#include "task2.h"
#include <iostream>

// TODO: переименовать пространство имен
namespace task {

std::string say_hello(std::string_view name) {
    return "Hello, " + std::string(name) + "!";
}

}
