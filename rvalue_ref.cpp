#include <iostream>
using namespace std;
 
class Foo {
    int* data;
public:
    Foo() : data(new int[1000]) {};
 
    Foo& operator= (Foo&){
        cout << "Foo&" << endl;
        return *this;
    }
 
    Foo& operator= (Foo&& foo){
        if (this == &foo) cout << "bad parameter";
        cout << "Foo&&" << endl;
        data = foo.data;
        foo.data = 0;
        return *this;
    }
 
    ~Foo(){
        delete[] data;
    }
};
 
int main(){
    Foo foo1, foo2;
    foo1 = Foo();
 
    Foo* ptr = &foo2;
 
    foo2 = foo2;
 
    foo2 = *(ptr+0);
 
    return 0;
}
