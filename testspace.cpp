#include <iostream>
using namespace std;
#include "polynomial.cpp"





int main(){

 Polynomial patty;
 patty.build();
 patty.print();
 cout << "--------------------------------"<<endl;
 Polynomial dude;
 dude.build();
 dude.print();
  cout << "_________________________________________"<<endl;

 cout << "-------------adding-------------------"<<endl;
 Polynomial three;
 patty.print();
 dude.print();
 cout << "_________________________________________"<<endl;
 three = patty + dude;
 three.print();


 cout << "-------------subtracting-------------------"<<endl;
 patty.print();
 dude.print();
 cout << "_________________________________________"<<endl;
 three = patty - dude;
 three.print();



 cout << "-------------multiplying-------------------"<<endl;
 patty.print();
 dude.print();
 cout << "_________________________________________"<<endl;
 three = patty * dude;
 three.print();


 cout << "-------------Modulus-------------------"<<endl;
 patty.print();
 dude.print();
 cout << "_________________________________________"<<endl;
 three = patty % dude;
 three.print();
  return 0;
}
