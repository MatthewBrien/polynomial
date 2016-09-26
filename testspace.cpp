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
 cout << "--------------------------------"<<endl;
 Polynomial three;

 three.print();
 cout << "--------------------------------"<<endl;
 three = patty + dude;

 three.print();
 cout << "--------------------------------"<<endl;

 three = dude;
 dude.print();
 



  return 0;
}
