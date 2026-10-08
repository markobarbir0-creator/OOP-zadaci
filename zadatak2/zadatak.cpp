#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class bankacc {
public:
	virtual void depozit(double a) = 0;
	virtual void witdraw(double a) = 0;
};
class saving :public bankacc {
private:
	double stanje;
	double kamata;
public:
	saving(double s,double k):stanje(s),kamata(k){}
	void depozit(double a)override{
		stanje += a;
	}
	double getstanje() {
		return stanje;
	}
	void witdraw(double a)override {
		double temp = stanje;
		stanje -= a;
		if (stanje <0) {
			stanje = temp;

		}
	}
};
class check :public bankacc {
private:
	double stanje;
	double dozvoljeno;
public:
	check(double s, double b):stanje(s),dozvoljeno(b){}
	void witdraw(double a)override {
		double temp = stanje;
		stanje -= a;
		if (stanje < dozvoljeno) {
			stanje = temp;
			cout << "nije uspjelo";
		}
	}
	void depozit(double a)override {
		stanje += a;
	}
	double getstanje() {
		return stanje;
	}
};
int main() {
	saving s(1000, 1.5);
	check c(100, -100);
	s.depozit(200);
	cout << s.getstanje() << endl;
	c.witdraw(300);
	cout << c.getstanje() << endl;
	

	return 0;
}