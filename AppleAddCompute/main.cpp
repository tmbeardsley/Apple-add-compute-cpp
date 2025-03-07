#include <Metal/Metal.hpp>
#include "MetalAdder.hpp"

#include <iostream>
#include <memory>

int main(int argc, const char * argv[]) {
    MTL::Device* device = MTL::CreateSystemDefaultDevice();
    
    MetalAdder adder(device);
    
    std::cout << "Hello, World!\n";
    
    return 0;
}
