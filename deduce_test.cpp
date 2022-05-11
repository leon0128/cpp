#include <type_traits>

// pass by value
template<class T>
T passByValue(T t)
{
    return t;
}

// pass by l-reference and pointer
template<class T>
T &passByLReference(T &t)
{
    return t;
}
template<class T>
T *passByPointer(T *t)
{
    return t;
}

int main(int argc, char **argv)
{
    int i = 0;
    const int ci = i;
    int &ri = i;
    const int &cri = i;
    int *pi = nullptr;
    const int *cpi = nullptr;
    const int const *cpci = nullptr;

    // pass by value
    // int(int) (pass by value)
    static_assert(std::is_same_v<int, decltype(passByValue(i))>
        , "int(int) (pass by value)");
    static_assert(std::is_same_v<int, decltype(passByValue(ri))>
        , "int(int) (pass by value)");
    // int(int) (pass by value)
    static_assert(std::is_same_v<int, decltype(passByValue(cri))>
        , "int(int) (pass by value)");

    // pass by lreference and pointer
    // int&(int&) (pass by lreference)
    static_assert(std::is_same_v<int&, decltype(passByLReference(i))>
        , "int&(int&) (pass by lreference)");
    // const int&

    return 0;
}