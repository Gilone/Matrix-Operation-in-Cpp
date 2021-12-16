#include <iomanip>
#include <iostream>
#include "MatrixLib.h"

using namespace std;

int main(){

	Matrix<double> a={
		{ 1.0,    1.0,    1.0  },
		{ 1.0,     1.0,    1.0  }
	};

	Matrix<double> b={
		{ 2.0,  2.0 },
		{ 2.0,  2.0 },
		{ 2.0,  2.0 }
	};

	cout<<"matrix a:\n"<<a<<endl;
	cout<<"matrix b:\n"<<b<<endl;

	cout<<"a*3=\n"<<a*3.0<<endl;
	cout<<"a*b=:\n"<<a*b<<endl;
	cout<<"The inverse of a is:\n"<<a.invert()<<endl;

	return 0;
}