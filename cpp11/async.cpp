#include <iostream>
#include <future>
#include <chrono>

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took: " << ms << "ms" << std::endl;
    }
};


static void Compute(int input)
{
    Timer timer;

    for (int i = input; i < 400000000; i++)
    {
        if (i % 100000000 == 0)
            std::cout << "input " << input << ": " << i << std::endl;
    }
}

int main()
{
    std::vector<std::future<void>> futures; // requires, otherwise wait a la fin de compute


    auto Timer1Start = std::chrono::high_resolution_clock::now();

    for (int i=0; i<5; i++)
        futures.push_back(std::async(std::launch::async, Compute, i));

    auto Timer1Stop = std::chrono::high_resolution_clock::now();

    //std::chrono::duration<float>
    auto DurationAsync = Timer1Stop - Timer1Start;
    std::cout << "DurationAsync: " << DurationAsync.count() << std::endl;

    auto Timer2Start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 5; i++)
        Compute(i);
    
    auto Timer2Stop = std::chrono::high_resolution_clock::now();
    
    auto DurationSequentiel = Timer2Stop - Timer2Start;
    std::cout << "DurationSequentiel: " << DurationSequentiel.count() << std::endl;

    //======================================

    std::cin.get();
}