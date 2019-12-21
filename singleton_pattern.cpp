#include <thread>

#include <chrono>
#include <iostream>
#include <future>

constexpr auto tenMill= 10000000;

class MySingleton{
public:
  static MySingleton& getInstance(){
    static MySingleton instance; // As compilation is happending through C++11 , it will get initialised when the first time the decleraion is called
    return instance; // returning as reference
  }
  /*
        According to C++11 , the static valiable confirms that , valiable is initiated once .
        It cam be called from multiple thread , so its developer responsibility to ensure that ctor is implemented in thread-safe way .
        i.e. If there is any resource are in teh calsss , then creation of those resource needs to to synchronise accordingly .
  */
private:
  // Making this implicit functions private . It can't be called from out side of class
  MySingleton()= default; // using the default constructor
  ~MySingleton()= default; // using the default dtor
  MySingleton(const MySingleton&)= delete;//deleting copy constructor
  MySingleton(const MySingleton&&)= delete;//deleting move constructor
  MySingleton& operator=(const MySingleton&)= delete;// deleting copy assignment
  MySingleton& operator=(const MySingleton&&)= delete;// deleting move assignment

};

// we are calling this function from different thread
std::chrono::duration<double> getTime(){

  auto begin= std::chrono::system_clock::now();
  for ( size_t i= 0; i <= tenMill; ++i){
      MySingleton::getInstance();
  }
  return std::chrono::system_clock::now() - begin;

};

int main(){
    auto fut1= std::async(std::launch::async,getTime);
    auto fut2= std::async(std::launch::async,getTime);
    auto fut3= std::async(std::launch::async,getTime);
    auto fut4= std::async(std::launch::async,getTime);

    auto total= fut1.get() + fut2.get() + fut3.get() + fut4.get();

    std::cout << total.count() << std::endl;

}
