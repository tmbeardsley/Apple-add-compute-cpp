#include "MetalAdder.hpp"

MetalAdder::MetalAdder(MTL::Device* device) {
    
    mDevice_ = device;
    
    // Load the shader files with a .metal file extension in the project
    MTL::Library* defaultLibrary = mDevice_->newDefaultLibrary();
    if (!defaultLibrary)
    {
        throw std::runtime_error("Failed to find the default library.");
    }
    
    NS::String* functionName = NS::String::string("add_arrays", NS::StringEncoding::UTF8StringEncoding);
    MTL::Function* addFunction = defaultLibrary->newFunction(functionName);
    if (!addFunction)
    {
        throw std::runtime_error("Failed to find the adder function.");
    }
    
    // Create a compute pipeline state object.
    NS::Error* error = nullptr;
    mAddFunctionPSO_ = mDevice_->newComputePipelineState(addFunction, &error);
    if (!mAddFunctionPSO_)
    {
        throw std::runtime_error(std::string("Failed to created pipeline state object, error:\n") + error->localizedDescription()->utf8String());
    }
    
    mCommandQueue_ = mDevice_->newCommandQueue();
    if (!mCommandQueue_)
    {
        throw std::runtime_error("Failed to find the command queue.");
    }
}
