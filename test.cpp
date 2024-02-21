#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

void testForLoopVector();
void testClassInstance();
int test_heap_use_after_free();

//======================================================================================
int main(){
    testForLoopVector();
    //testClassInstance();
    //return test_heap_use_after_free();
}
//======================================================================================


void testForLoopVector(){
    std::vector<std::pair<std::string, std::string>> arr;
    arr.push_back(std::make_pair("k1", "v1"));
    arr.push_back(std::make_pair("k2", "v2"));

    for (const auto& [k, v] : arr) {
        std::cout << k << " " << v << std::endl;
    }
}

int test_heap_use_after_free(){
  int *array = new int[10];
  delete [] array;
  return array[1];
}

struct TestClass{
    std::map<std::string, std::string> m_mFieldLabels;

    void printMap(){
        for (const auto& [field, label] : m_mFieldLabels){
            std::cout << "  f:" << field << " l:" << label << std::endl;
        }
    }
};

void testClassInstance()
{
    TestClass testClassInstance;

    std::cout << "*1 empty" << std::endl;
    testClassInstance.printMap();
    std::cout << "*2 add field_a and field_b" << std::endl;
    testClassInstance.m_mFieldLabels.emplace("field_a", "value_a");
    testClassInstance.m_mFieldLabels.emplace("field_b", "value_b");
    testClassInstance.printMap();
    std::cout << "*3 change field_a to *MOD" << std::endl;
    testClassInstance.m_mFieldLabels.emplace("field_a", "value_a_MOD");
    testClassInstance.printMap();
    std::cout << "*4 change field_a to MOD but clear first" << std::endl;
    testClassInstance.m_mFieldLabels.clear();
    testClassInstance.m_mFieldLabels.emplace("field_a", "value_a_MOD");
    testClassInstance.printMap();
}
