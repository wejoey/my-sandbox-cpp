#include <iostream>

struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes\n";
    s_AllocationMetrics.TotalAllocated += size;
    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
    std::cout << "Freeing " << size << " bytes\n";
    s_AllocationMetrics.TotalFreed += size;
    free(memory);
}

class MyClass
{
public:
    MyClass() { std::cout << "MyClass created" << std::endl; };
    ~MyClass() { std::cout << "MyClass destroyed" << std::endl; };
};

static void PrintMemoryUsage()
{
    std::cout << "Memory usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

int main()
{
    MyClass* ptr1;
    MyClass* ptr2;

    PrintMemoryUsage();

    {
        std::unique_ptr<MyClass> myClassPtr1 = std::make_unique<MyClass>();
        std::shared_ptr<MyClass> myClassPtr2 = std::make_shared<MyClass>();

        ptr1 = myClassPtr1.get();
        ptr2 = myClassPtr2.get();
        PrintMemoryUsage();
    }
    PrintMemoryUsage();
}