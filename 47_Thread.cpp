#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

template<typename T>
class ThreadQueue {
  private:
    queue<T> q;
    mutex m;
    condition_variable cv;

  public:
    ThreadQueue() {}

    void push(T&& elem) {
      unique_lock<mutex> lck(m);
      q.push(elem);
      cv.notify_one();
    }

    T pop() {
      unique_lock<mutex> lck(m);
      cv.wait(lck, !q.empty());

      T elem;
      if (!q.empty()) {
        elem = std::move(q.front());
        q.pop();
      }

      return elem;
    }
};
