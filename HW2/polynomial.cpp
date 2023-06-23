#include <iostream>
#include <stdio.h>
#include <string>

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

class Polynomial
{

public:
    Polynomial();
    Polynomial(const int , const int [51]);
    Polynomial add( const Polynomial) const; // add function
    Polynomial subtract( const Polynomial ) const; // subtract function
    Polynomial multiplication( const Polynomial ) const; // multiplication function
    void output() const;
private:
    int coefficients[101]; // integer coefficients
    int greatestPower; // integer greatestPower
}; // end class Polynomial

#endif


using namespace std;

Polynomial::Polynomial(){ // constructor to set all coef to 0 and power to -1
    greatestPower = -1;
    for(int i = 0; i< 101; i++){
        coefficients[i] = 0;
    }
}

Polynomial::Polynomial(const int greatestPower, const int coefficients[51]){//set the coef and degree of polynomial
    this->greatestPower = greatestPower;
    for(int i=0; i<=greatestPower; i++){
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial Polynomial::add( const Polynomial B) const{ // add function
    Polynomial temp = Polynomial();
    temp.greatestPower = max(this->greatestPower,B.greatestPower);
    for(int i=0; i<=temp.greatestPower; i++){
        temp.coefficients[i] = this->coefficients[i] + B.coefficients[i];
    }
    return temp;
}

Polynomial Polynomial::subtract( const Polynomial B) const{// subtract function
    Polynomial temp = Polynomial();
    temp.greatestPower = max(this->greatestPower,B.greatestPower);
    for(int i=0; i<=temp.greatestPower; i++){
        temp.coefficients[i] = this->coefficients[i] - B.coefficients[i];
    }
    return temp;
} 
Polynomial Polynomial::multiplication( const Polynomial B) const{ // multiplication function
    Polynomial temp = Polynomial();
    temp.greatestPower = this->greatestPower + B.greatestPower;
    for(int i=0; i<=this->greatestPower; i++){
        for(int j=0; j<=B.greatestPower; j++){
            temp.coefficients[i+j] += this->coefficients[i] * B.coefficients[j];
        }  
    }
    return temp;
}

void Polynomial::output() const{
    for(int i = greatestPower; i>=0; i--){
        (i==0) ? cout << coefficients[i]: cout << coefficients[i] << " ";
    }
}

int main()
{
    int greatestPower1, greatestPower2;
    int coefficient1[51], coefficient2[51];
    Polynomial ans;

    cin>>greatestPower1;
    for(int i = greatestPower1 ; i >= 0; i--)
    {
        cin>>coefficient1[i];
    }
    cin>>greatestPower2;
    for(int i = greatestPower2 ; i >= 0 ; i--)
    {
        cin>>coefficient2[i];
    }
    Polynomial a(greatestPower1, coefficient1), b(greatestPower2, coefficient2) ;

    ans = a.add( b );
    ans.output();
    cout << endl;

    ans = a.subtract( b );
    ans.output();
    cout << endl;

    ans = a.multiplication( b );
    ans.output();
    cout << endl;

} // end main
