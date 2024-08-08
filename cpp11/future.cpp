#include <future>
#include <iostream>
#include <vector>

int main()
{
  const auto doPrint = [](char start)
  {
    for (int i = 0; i < 999; ++i)
    {
      std::cout << start;
    }
  };

  static const int NB_OF_THREADS = 2;

  std::vector<std::future<void>> vFuture;
  vFuture.reserve(NB_OF_THREADS);

  char myChar[3] = {'|','_'};

  for (char & i : myChar)
  {
    vFuture.emplace_back(std::async(doPrint, i));
  }

  for (auto& future : vFuture)
  {
    future.get();
  }
}