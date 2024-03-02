#include <iostream>
#include <vector>

/*

vector
------
realloc when inscreased - not optimal


*/

struct Vertex
{
    float x, y, z;

 //   Vertex(const Vertex& v) = delete; // copy constructor not allowed  
};



std::ostream& operator<<(std::ostream& s, const Vertex& v)
{
    s << v.x << ", " << v.y << ", " << v.z;
    return s;
}

int main()
{
    std::vector<Vertex> vertices;

    vertices.reserve(3); // allocate more memory sooner to avoid copies


    vertices.emplace_back(Vertex({ 1,2,3 })); // will create the objet in the vector mem to avoid a copy!
    vertices.push_back({ 4,5,6 });

#if 0
    for (int i = 0; i < vertices.size(); i++)
        std::cout << vertices[i] << std::endl;
#else
    for (auto& v : vertices)    // reference to be used to avoid a copy
        std::cout << v << std::endl;
#endif

    std::cin.get();
}