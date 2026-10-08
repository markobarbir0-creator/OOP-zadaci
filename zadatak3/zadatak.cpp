#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
template <typename T>
class stack {
private:
	T a;
public:
	stack(T x):a(x){}
	void push(vector <T> v)const {
		v.push_back(a);
	}
	void pop(vector<T> v)const{
		v.pop_back(a);
	}
};

int main() {


}