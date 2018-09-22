#include <iostream>
#include <cmath>
using namespace std;

class Polynomial
{
public:
	Polynomial(); // default constructor
	Polynomial(const Polynomial& object); // copy constructor
	const Polynomial& operator=(const Polynomial & rhs); // operator=
	~Polynomial(); // destructor
	Polynomial(double coefficient[], int size); // parameterized constructor
	friend Polynomial operator+(const Polynomial& lsh, const Polynomial& rhs); // operator+
	friend Polynomial operator-(const Polynomial& lsh, const Polynomial& rhs); // operator-
	friend Polynomial operator*(const Polynomial& lsh, const Polynomial& rhs); // operator*
	const double& operator[](int degree)const; // assign and inspect function
	friend double evaluate(const Polynomial& ploy, double x); //evaluate 
	int getSize() const; // returns size
	double max(double lhs, double rhs); // find max
private:
		double *coef;
		int size;
};

int main()
{
   double quad[] = {3, 2, 1}; 
   double cubic[] = {1, 2, 0, 3};
   Polynomial q(quad, 3); // 3 + 2*x + x*x
   Polynomial c(cubic, 4); // 1 + 2*x + 0*x*x + 3*x*x*x
   Polynomial p(q); // test copy constructor
   Polynomial r;
   r = c;          //test operator=   

   cout << "Polynomial q " << endl;
   for(int i = 0; i < q.getSize(); i++)
		cout << "term with degree " << i << " has coefficient " << q[i] << endl;
   
   cout << "Polynomial c " << endl;
   for(int i = 0; i < c.getSize(); i++)
		cout << "term with degree " << i << " has coefficient " << c[i] << endl;
   
   cout << "value of q(2) is " << evaluate(q, 2) << endl; // x = 2
   cout << "value of p(2) is " << evaluate(p, 2) << endl;
   cout << "value of r(2) is " << evaluate(r, 2) << endl;
   cout << "value of c(2) is " << evaluate(c, 2) << endl;

   r = q + c;
   cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;

   r = q - c;
   cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;

   r = q * c;
   cout << "size of q*c is " << r.getSize() << endl;
   cout << "Polynomial r (= q*c) " << endl;

   for(int i = 0; i < r.getSize(); i++)
     cout << "term with degree " << i << " has coefficient " << r[i] << endl;

   cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
   return 0;
}

// creates an empty polynomial
Polynomial::Polynomial():coef(0), size(0)
{// deliberately empty
}

Polynomial::Polynomial(const Polynomial& object) : size(object.size)
{
	coef = new double[size];
	for(int i = 0; i < size; i++)
		coef[i] = object.coef[i];
}

const Polynomial& Polynomial::operator=(const Polynomial & rhs) // rhs:right-hand-side
{
	if(rhs.coef == coef)
		return rhs;
	else
	{
		delete [] coef;
		size = rhs.size;
		coef = new double[size];
		for(int i = 0; i < size; i++)
    		coef[i] = rhs.coef[i];
	}
	return *this;
}

Polynomial::~Polynomial()
{
	delete [] coef;
}

Polynomial::Polynomial(double coefficient[], int newSize) : size(newSize)
{
	coef = new double[size];
	for(int i = 0; i < size; i++)
		coef[i] = coefficient[i]; 
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) // lhs:left-hand-side
{
	const int sumSize = max(lhs.size, rhs.size);
	double* sumCoef = new double[sumSize];
	
	for(int i = 0; i < sumSize; i++)
		sumCoef[i] = 0;
	
	for(int i = 0; i < sumSize; i++)
	{
		if(i < lhs.size)
			sumCoef[i] += lhs.coef[i];
		if(i < rhs.size)
			sumCoef[i] += rhs.coef[i];
	}

	return Polynomial(sumCoef, sumSize);
}

Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs)
{
	const int sumSize = max(lhs.size, rhs.size);
	double* sumCoef = new double[sumSize];
	
	for(int i = 0; i < sumSize; i++)
		sumCoef[i] = 0;
	
	for(int i = 0; i < sumSize; i++)
	{
		if(i < lhs.size)
			sumCoef[i] += lhs.coef[i];
		if(i < rhs.size)
			sumCoef[i] -= rhs.coef[i];
	}

	return Polynomial(sumCoef, sumSize);
}

Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs)
{
	const int prodSize = lhs.size + rhs.size - 1;
	double* prodCoef = new double[prodSize];

	for(int i = 0; i < prodSize; i++)
		prodCoef[i] = 0;
 
	for(int i = 0; i < lhs.size; i++)
	{
		for(int j = 0; j < rhs.size; j++)
    		prodCoef[i + j] += lhs[i] * rhs[j];
	}

	return Polynomial(prodCoef, prodSize);
}

const double& Polynomial::operator[](int degree) const
{
	return coef[degree];
}

double evaluate(const Polynomial& poly, double x)
{
	double value = 0;

	for(int i = 0; i < poly.getSize(); i++)
		value += poly[i]*pow(x, i);

	return value;
}

int Polynomial::getSize() const
{
	return size;
}

double max(double lhs, double rhs)
{
	return (lhs > rhs) ? lhs : rhs;
}
