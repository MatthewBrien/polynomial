#include <iostream>
//#include <regex>
#include "polynomial.h"
#include <String>
#include <vector>

void Polynomial::build(){
  //if polynomial is alredy allocated, delete array, allocate anew
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

    for( i = degree-1  ; i >1;i--) //print all from x^degree - 1 : x^2
    {
      if(constants[i] > 0){
          cout << " + ";
      }
      cout << constants[i] << "X^"<< i << " ";
    }
    if(constants[i] >= 0 && degree > 1){
        cout << " + ";
    }
    cout << constants[i] << "X" ; // aX
    if(constants[0] >= 0){
        cout << " + " ;
    }
    cout << constants[0] << endl;
    }
    else{
      cout << constants[1] << "X ";
      if(constants[0] > 0){
        cout << "+ " << constants[0] << endl;
      }
      else if(constants[0] < 0){
        cout << constants[0] << endl;
      }
    }
  }
  else{
    cout << constants[0]<<endl;
  }
}//end print()

//
Polynomial Polynomial::operator+(const Polynomial& p2){

  Polynomial sum; //new resut polynomial
  //assignt to the the polynomial with the larger degree
  if(degree > p2.degree){
    sum = *this;
    for(int i = 0; i<=p2.degree; i++) //itterate over the smaller polynomial
    {
      sum.constants[i] += p2.constants[i];
    }
  }
  else{
    sum = p2;
    for(int i = 0; i<=degree; i++)//itterate over the smaller polynomial
    {
      sum.constants[i] += constants[i];
    }
  }
  return sum;

}//operator +

Polynomial Polynomial::operator-(const Polynomial& p2){
  Polynomial difference; //result Polynomial

  //case one, subtracting a polynomial of a larger degree from a polynomial of a smaller degree
  if(degree < p2.degree){
    difference.degree = p2.degree;
    difference.constants = new double[difference.degree+1];
    for(int i = 0; i<=degree; i++){
      difference.constants[i] = constants[i] - p2.constants[i];
    }
    //for remaining constants, 0 - Ci = -Ci
    for(int i = degree+1; i<=p2.degree;i++){
      difference.constants[i] = p2.constants[i] * -1;
    }
  }
  else
  {
    difference.degree = degree;
    difference.constants = new double[difference.degree+1];
    for(int i = 0; i<=p2.degree; i++){
      difference.constants[i] = constants[i]-p2.constants[i];
    }
    //copy remaining constants to difference
    for(int i = p2.degree+1; i<= degree;i++){
      difference.constants[i] = constants[i];
    }
  }

  return difference;
}//operator -

void Polynomial::operator=(const Polynomial& p2){
    double *temp = this->constants;
    delete[] temp;

    this->degree = p2.degree;
    this->constants = new double[this->degree];
    for(int i = 0; i<= degree; i++){
      this->constants[i] = p2.constants[i];
    }

    p2.~Polynomial();

}

Polynomial Polynomial::operator*(const Polynomial& p2){
  Polynomial product;
  product.degree = this->degree + p2.degree;
  product.constants = new double[degree+1];
  //initialize product's constants to zero
  for(int i = 0; i<=product.degree; i++){
    product.constants[i] = 0;
  }

  //itterate over both factos,
  for(int i = 0; i<=this->degree; i++){
    for(int ii = 0; ii<=p2.degree; ii++){
      product.constants[i+ii] += this->constants[i] * p2.constants[ii];
    }
  }

  return product;
}

Polynomial Polynomial::operator/(const Polynomial& p2){
  divisionHelper(*this, p2);
  return p2;
}//operator /

Polynomial Polynomial::operator%(const Polynomial& p2){
  divisionHelper(*this, p2);
  return p2;
}//operator %

void Polynomial::divisionHelper(const Polynomial& p1, const Polynomial& p2){
  cout << "dividing stuff" << endl;

}
bool Polynomial::operator>(const Polynomial& p2){
  if(this->degree > p2.degree ){
    return true;
  }
  return false;
}//operator >
bool Polynomial::operator>=(const Polynomial& p2){
  if(this->degree >= p2.degree){
    return true;
  }
  return false;
}//operator >=
bool Polynomial::operator<(const Polynomial& p2){
  if(this->degree < p2.degree)
  {
    return true;
  }
  return false;
}//operator <
bool Polynomial::operator<=(const Polynomial& p2){
  if(this->degree <= p2.degree)
  {
    return true;
  }
  return false;
}//operator <=
bool Polynomial::operator==(const Polynomial& p2){return false;
  if(this->degree != p2.degree){
    return false;
  }
  else{
    for(int i = 0; i< this->degree; i++){
      if(this->constants[i] != p2.constants[i]){
        return false;
      }
    }
  }
  return true;
}//operator ==

Polynomial Polynomial::GCD(Polynomial p2) const{
  return p2;
};




/*
vector<Polynomial> Polynomial::primeFactorizaion() {
  vector<Polynomial> factors;
  retun factors;
}
*/
