#include <vector>
#include <iostream>
using namespace std;

struct A {
  int* ptr;

  A(){
    ptr = new int;
    cout << "Constructor..." << endl;
  }

  A(const A& a1){
    cout << "Copy const..." << endl;
    this->ptr = new int;
    *this->ptr = *a1.ptr;
  }

  A(A&& a1){
    cout << "Move contr..." << endl;
    this->ptr = a1.ptr;
    a1.ptr = nullptr;
  }

  ~A(){
    cout << "Destructor..." << endl;
    delete ptr;
  }

};

int main(){

  A old_house = A();
  A new_house = move(old_house);

  return 0;
}
