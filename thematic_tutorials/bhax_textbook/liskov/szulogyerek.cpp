#include <iostream>

class Szulo{
public:
  void kiir(){
    std::cout << "Szulo";
  }
};
class Gyerek : public Szulo
{
  void kiir2(){
    std::cout << "Gyerek";
  }
};

int main(){

  Szulo* sz = new Gyerek();
  sz->kiir();

}
