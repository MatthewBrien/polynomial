#include <iostream>
//#include <regex>
#include "polynomial.h"
#include <String>

Polynomial::Polynomial(){
  degree = -1;
  constants = NULL;
}
void Polynomial::build(){
  //if polynomial is alredy allocated, delete array
  if(degree != -1){
    double *temp = constants;
    delete[] temp;
    constants = NULL;
    degree = -1;
  }

  //get new values
  while(degree < 0){
  cout << "Please enter the degree of the polynomial: " ;
  cin >> degree;
  }
  cout << "degree is  " << degree << endl;

  constants = new double[degree + 1];

  double constant; //input variable
  //fill array with constants
  for(int i = degree; i >= 0; i--){
    cout << "Constant for x ^ " << i << ": ";
    cin >> constant;
    constants[i] = constant;
  }
}//end build()

Polynomial::Polynomial(string input){
  cout << "TODO, parse string" << endl;
}

void Polynomial::print() const{
  int i = degree;
  if(i == -1){
    cout << "Polynomial is empty" << endl;
    return;
  }
  if(i > 0){
    if(i > 1){
      //print lead coefficient
      cout << constants[i] << "X^"<< i << " ";
    }
    for( i = degree -1 ; i >1;i--) //print all from x^degree - 1 : x^2
    {
      if(constants[i] > 0){
          cout << " + ";
      }
      cout << constants[i] << "X^"<< i << " ";
    }
    if(constants[i] > 0 && degree > 1){
        cout << " + ";
    }
    cout << constants[i] << "X" ; // aX
    if(constants[0] > 0){
        cout << " + " ;
    }
    cout << constants[0] << endl;
  }
  else{
    cout << constants[0]<<endl;
  }
}//end print()

//
Polynomial Polynomial::operator+(const Polynomial& p2){
    int i;
  Polynomial sum; //new resut polynomial
  if(this->degree > p2.degree){
    sum.degree = this->degree;
    sum.constants = new double[this->degree+1];
    for( i = this->degree; i >(this->degree = p2.degree); i--){
      sum.constants[i] = this->constants[i];
    }
  }
  else{
    sum.degree = p2.degree;
    sum.constants = new double[this->degree+1];
    for( i = this->degree; i >(this->degree = p2.degree); i--){
      sum.constants[i] = p2.constants[i];
    }
  }
  while(i >=0){
    sum.constants[i] = this->constants[i] + p2.constants[i];
    i--;
  }
  //cout << "Adding polynomials" << endl;
  //sum.print();
  //cout << &sum << endl;
  return sum;
}//operator +

Polynomial Polynomial::operator-(const Polynomial& p2){
cout << "subtracing polynomials"<< endl;
return p2;
}


void Polynomial::operator=(const Polynomial& p2){
    double *temp = this->constants;
    delete[] temp;
    //cout << "Cleared old array" << endl;

    this->degree = p2.degree;
    this->constants = new double[this->degree];
    for(int i = 0; i<= degree; i++){
      this->constants[i] = p2.constants[i];
    }
    //print();
    p2.~Polynomial(); //what if p2 isn't the result of an addition?
}

bool Polynomial::operator>(const Polynomial&){return false;}
bool Polynomial::operator>=(const Polynomial&){return false;}
bool Polynomial::operator<(const Polynomial&){return false;}
bool Polynomial::operator<=(const Polynomial&){return false;}
bool Polynomial::operator==(const Polynomial&){return false;}
