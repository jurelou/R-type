//
// Created by abachelet on 10/01/18.
//

#include <iostream>

#include "./header/threads/IThreads.hpp"
#include "./header/threads/UnixThreads.hpp"
#include "./header/mutex/IMutex.hpp"
#include "./header/mutex/UnixMutex.hpp"

IMutex *mut = new UnixMutex();

void *print_block (void *c) {
  char	*d;
  d = static_cast<char *>(c);
  mut->lock();
  for (int i=0; i<50; ++i) { std::cout << d[0]; }
  std::cout << '\n';
  mut->unlock();
}

int main ()
{
  char	first = '*';
  char	second = '$';
  
  IThread *foo_test = new UnixThreads(print_block, &first);
  IThread *bar_test = new UnixThreads(print_block, &second);

  foo_test->join();
  bar_test->join();
  return 0;
}
