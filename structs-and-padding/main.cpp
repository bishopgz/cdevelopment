#include <iostream>
using namespace std;

/*
	Using structures to generate files
	with the use of padding and 
	pre-processor directive #pragma 
	pack within a single byte boudary
	
*/

#pragma pack(push, 1)
struct Generic {
	const char * property;
	int counterProperty;
	double compProperty;
};
#pragma pack(pop)

int main(){
	
	/*
		Try to run the program without 
		#pragma pack(pop) to see what 
		happens to the general size 
		of the struct and with it. 
	*/
	
	cout << sizeof(Generic);
	return 0;
}
