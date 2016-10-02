#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial //polynomials are of the form akX^k + ak-1X^k-1 + ... + a2X^1 + a1
{
private:

  double *constants;
  int degree; //largest degree, and length of polynomial
  void divisionHelper(const Polynomial&, const Polynomial&); //return array, containing quotient and remainder

public:
  Polynomial(){degree = -1; constants=NULL;}
    Polynomial(string); //TODO, implement this
  Polynomial operator+(const Polynomial&); //
  Polynomial operator-(const Polynomial&);
  Polynomial operator*(const Polynomial&);
  Polynomial operator/(const Polynomial&); //return division with remainder truncated
  Polynomial operator%(const Polynomial&); //return remainder of division
  void operator=(const Polynomial&); //assign polynomial term by term
  bool operator>(const Polynomial&); //degree of P1 > degree of P2
  bool operator>=(const Polynomial&); //degree of P1 >= degree of P2
  bool operator<(const Polynomial&); //degree of P1 <  degree of P2
  bool operator<=(const Polynomial&); //degree of P1 <= degree of p2
  bool operator==(const Polynomial&); //are P1 and P2 equal term by term

  ~Polynomial(){
    if(constants){
      delete[] constants;
    }
  }

void build(); //allocated a new Polynomial, term by term, through user input
void print() const; //display a formated version of he polynomial
Polynomial GCD(Polynomial)const;
//vector<Polynomial> primeFactorizaion() const;


};

#endif
