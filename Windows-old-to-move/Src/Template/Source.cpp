#include <iostream>

#include <array>

template<typename T, size_t S>
class MyArray
{
public:
    constexpr int Size() const { return S; }

    T& operator[](int index) { return mData[index]; }
    const T& operator[](int index) const { return mData[index]; }

    T* Data() { return mData; }
private:
    T mData[S];
};

int main()
{
    MyArray<int, 5> data;
}