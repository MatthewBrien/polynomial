#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial //polynomials are of the form akX^k + ak-1X^k-1 + ... + a2X^1 + a1
{
private:

  double *constants;
  int degree = -1; //largest degree, and length of polynomial


public:
  Polynomial();
  Polynomial(string);
  Polynomial operator+(const Polynomial&);
  Polynomial operator-(const Polynomial&);
  void operator=(const Polynomial&);
  bool operator>(const Polynomial&);
  bool operator>=(const Polynomial&);
  bool operator<(const Polynomial&);
  bool operator<=(const Polynomial&);
  bool operator==(const Polynomial&);

  ~Polynomial(){
    if(constants){
      delete[] constants;
    }
  }
void build();
void print() const;



};

#endif
