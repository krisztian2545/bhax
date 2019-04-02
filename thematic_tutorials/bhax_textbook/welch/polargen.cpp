#include "std_lib_facilities.h" 
class PolarGenerator{
bool nincsTarolt=true;
double tarolt;
 public :
double kovetkezo()
 {
	
	if(nincsTarolt)
	{
	double u1,u2,v1,v2,w;
	u1= ((double) rand() / (double)(RAND_MAX));
	u2= ((double) rand() / (double)(RAND_MAX));
	v1=(2*u1)-1;
	v2=(2*u2)-1;
	
	w=(v1*v1)+(v2*v2);
	 while(w>1)
	 {double r = sqrt((-2*log(w))/w);
	  tarolt=r*v2;
	  nincsTarolt=!nincsTarolt;
	  return r*v1;
	 }
	}
	else
	{
	 nincsTarolt=!nincsTarolt;
	return tarolt;
	}
 };
};
int main()
{
std::srand(std::time(0));
PolarGenerator g;
for(int i=0; i<10; ++i)
	std::cout<<g.kovetkezo()<<std::endl;
return 0;
}