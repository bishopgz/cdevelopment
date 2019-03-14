#include <iostream>
#include <fstream>
using namespace std;

int main(){
	const char * filename = "stats.txt";
	ifstream input;
	
	input.open(filename); 
	if (!input.is_open()){
		return 1;
	}
	
	while(input){
		string line;
		getline(input, line, '=');
		
		int pop;
		input >> pop;
		
		cout << line << " -- " << pop << endl;
	}
	
	input.close();
	return 0;
}
