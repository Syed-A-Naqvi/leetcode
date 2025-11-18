#include "../cusutils.hpp"
#include <cstdio>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    std::vector<int> numbers = {1,2,3,4};
    printf("%s\n", vec_to_string(numbers).c_str());
    return 0;
}
