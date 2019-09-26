#include <iostream>

class Szulo{
};

class Gyerek : public Szulo
{
  void kiir(){
    std::cout << "Gyerek";
  }
};

int main(){

  Szulo* sz = new Gyerek();
  sz->kiir();

}
