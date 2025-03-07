#pragma once

#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

#include <string>

class MetalAdder {
    
public:
    
    MetalAdder(MTL::Device* device);
    void prepareData();
    void sendComputeCommand();
    
private:
    void encodeAddCommand(MTL::ComputeCommandEncoder* computeEncoder);
    void generateRandomFloatData(MTL::Buffer* buffer);
    void verifyResults();
    
    MTL::Device* mDevice_;
    
    // The compute pipeline generated from the compute kernel in the .metal shader file.
    MTL::ComputePipelineState* mAddFunctionPSO_;
    
    // The command queue used to pass commands to the device.
    MTL::CommandQueue* mCommandQueue_;
    
    // Buffers to hold data.
    MTL::Buffer* mBufferA_;
    MTL::Buffer* mBufferB_;
    MTL::Buffer* mBufferResult_;
};

