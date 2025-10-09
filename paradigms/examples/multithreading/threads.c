#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
using namespace std;

int main()
{
  mutex m1;
  mutex m2;
  
  thread t1([&m1, &m2] {
    cout << "t1 acquiring m1 " << endl;
    m1.lock();
    usleep(10000);
    cout << "t1 acquiring m2 " << endl;
    m2.lock(); 
  });
  
  thread t2([&m1, &m2] {
    cout << "t2 acquiring m2 " << endl;
    m2.lock();
    usleep(10000);
    cout << "t2 acquiring m1 " << endl;
    m1.lock();
  });
  
  t1.join();
  t2.join();
}
