#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <cctype>
using namespace std;
void funkcija3(vector<string>& v) {
	ofstream out("bla1.txt");
	if (!out) {
		cout<<"nije se otvoria" << endl;
		return;
	}
	string rijec;
	for (const auto& rijec : v) {
		out << rijec <<" ";  
	}

	out.close();
	cout << "upisano";
}
void funkcija2(vector<string>& v) {
	transform(v.begin(), v.end(), v.begin(), [](string x) {
		for (char& c : x) {
			c = tolower(c);
		}
		return x;
		});
}
void funkcija1(vector<string>& v) {
	auto it = remove_if(v.begin(), v.end(), [](string x) {return x.size() < 3; });
	v.erase(it, v.end());
}
void funkcija(vector<string> &v) {
	ifstream in("bla.txt");
	if (!in) {
		cout << "nema filea";
		return;
	}
	copy(istream_iterator<string>(in), istream_iterator<string>(), back_inserter(v));
}
int main() {
	vector<string> v;
	funkcija(v);
	funkcija1(v);
	funkcija2(v);
	funkcija3(v);


	
	return 0;
}