#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

std::vector<std::string> createAndInsert();
int main()
{
    std::vector<std::string> vecString;
    vecString = createAndInsert();
    for (const auto &s : vecString)
    {
        std::cout << s << '\n';
    }
    return EXIT_SUCCESS;
}

std::vector<std::string> createAndInsert()
{
    std::vector<std::string> vec;
    vec.reserve(3);
    std::cout << "Enter a string: "<<std::endl;
    std::string str("Harshad");
    vec.push_back(str);
    vec.push_back(str + str);
    vec.push_back(std::move(str));
    return vec;
}
