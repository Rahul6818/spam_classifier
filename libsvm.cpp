#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;

int main(){
	ofstream output;
	output.open("libsvm_test.txt");
	
	ifstream att;
	att.open("x_test.txt");
	ifstream y;
	y.open("y_test.txt");
	string line_a,line_y;	
	while ( getline (att,line_a) && getline(y,line_y) ){
		output << line_y<<" "<<line_a<<"\n";
	}
}