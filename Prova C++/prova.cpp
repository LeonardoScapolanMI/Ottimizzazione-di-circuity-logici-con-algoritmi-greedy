#include <iostream>
#include <fstream>
#include <string>
#include "../Funzioni.hpp"

using namespace std;

int main()
{
	vector<vector<double>> m(3,vector<double> (3,0.0));
	
	cout << DeterminanteTrePerTre(m) << endl;
	
	m[0][0] = 3;
	m[0][1] = 10;
	m[0][2] = 2;
	m[1][0] = 1;
	m[1][1] = 2;
	m[1][2] = 1;
	m[2][0] = 0;
	m[2][1] = 4;
	m[2][2] = 2;
	
	cout << DeterminanteTrePerTre(m) << endl;
}