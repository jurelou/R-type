//
// Created by abachelet on 10/01/18.
//

#include <iostream>

#include "./header/threads/IThreads.hpp"
#include "./header/threads/UnixThreads.hpp"

void *foo(void *x)
{
    std::cout << "foo end" << std::endl;
}

void *bar(void *x)
{
    std::cout << "bar end" << std::endl;
}

int main()
{
    void *data = NULL;
    IThread *foo_test = new UnixThreads(foo, data);
    IThread *bar_test = new UnixThreads(bar, data);

    std::cout << "main, foo and bar now execute concurrently...\n";

    foo_test->join();
    bar_test->join();

    std::cout << "foo and bar completed.\n";

    return 0;
}
