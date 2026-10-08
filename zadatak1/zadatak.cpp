#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class complex {
private:
	double realni;
	double imaginarni;
public:
	complex(const double &a,const double& b):realni(a),imaginarni(b){}
	complex operator+(const complex& z)const{
		return complex(realni + z.realni, imaginarni + z.imaginarni);
	}
	complex operator-(const complex& z)const {
		return complex(realni - z.realni, imaginarni - z.imaginarni);
	}
	complex operator*(const complex& z)const {
		return complex(realni*z.realni-imaginarni*z.imaginarni,realni*z.imaginarni+imaginarni*z.realni);
	}
	double modul() {
		return sqrt(realni * realni + imaginarni * imaginarni);
	}
	friend ostream& operator<<(ostream& os, complex& x);
};
ostream& operator<<(ostream& os, complex& x) {
	os << x.realni << "," << x.imaginarni<<"i";
	return os;
}
int main() {
	complex x1(3, 4);
	complex x2(2, 4);
	complex x3 = x1 + x2;
	complex x4 = x1 - x2;
	complex x5 = x1 * x2;
	cout << x3 << endl;
	cout << x4 << endl;
	cout << x5 << endl;

	return 0;
}