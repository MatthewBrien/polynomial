#include <iostream>
using namespace std;
#include "polynomial.cpp"





int main(){
 Polynomial three;

 Polynomial patty;
 patty.build();
 patty.print();
 cout << "--------------------------------"<<endl;
 Polynomial dude;
 dude.build();
 dude.print();
  cout << "_________________________________________"<<endl;

 cout << "-------------adding-------------------"<<endl;

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
 
 cout << "-------------empty, get degree, get length-------------------"<<endl;

 three.empty(6);
 three.print();
 cout << three.getDegree()<<endl;
 cout << three.getLength()<<endl;
 three.empty(-1);
 three.print();
 cout << three.getDegree()<<endl;
 cout << three.getLength()<<endl;


 cout << "----enter some leading zeroes----------" <<  endl;
 three.build();
 three.clearLeadingZeros();
 three.print();
  return 0;
}
