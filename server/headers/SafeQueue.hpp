//
// Created by marmus_a on 15/01/18.
//

#ifndef R_TYPE_SAFEQUEUE_HPP
#define R_TYPE_SAFEQUEUE_HPP

#include <mutex>
#include <queue>
#include <vector>

template<typename T>
class SafeQueue {
public:
  SafeQueue() {
    this->queue = new std::queue<T>();
    this->locker.unlock();
  }
  SafeQueue(T elem) {
    this->queue = new std::queue<T>();
    this->queue->push(elem);
    this->locker.unlock();
  }
  SafeQueue(std::vector<T> elems) {
    this->queue = new std::queue<T>();
    for (T it : elems) {
      this->queue->push(it);
    }
    this->locker.unlock();
  }
  ~SafeQueue() {}

  bool            push(T elem) {
    this->locker.lock();
    this->queue->push(elem);
    this->locker.unlock();
    return (true);
  };

  bool            tryPush(T elem) {
    if (this->locker.try_lock()) {
      this->queue->push(elem);
      this->locker.unlock();
      return (true);
    }
    return (false);
  }

  T               pop() {
    this->locker.lock();
    T res;
    if (!this->queue->empty()) {
      res = this->queue->front();
      this->queue->pop();
    } else {
      res = nullptr;
    }
    this->locker.unlock();
    return (res);
  }

  T               tryPop() {
    if (this->locker.try_lock()) {
      T res;
      if (!this->queue->empty()) {
        res = this->queue->front();
        this->queue->pop();
      } else {
        res = nullptr;
      }
      this->locker.unlock();
      return (res);
    }
    return (nullptr);
  }

//  T*              front() {
//    this->locker.lock();
//    T* res = this->queue.front();
//    this->locker.unlock();
//    return (res);
//  }

  bool            empty() {
    this->locker.lock();
    bool res = this->queue->empty();
    this->locker.unlock();
    return (res);
  }

private:
  std::mutex        locker;
  std::queue<T>     *queue;
};


#endif //R_TYPE_SAFEQUEUE_HPP
