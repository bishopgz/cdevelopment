#include <iostream>
#include <fstream>
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
	/* cout << sizeof(Generic); */
	const char * fileName = "test.bin";
	Generic object = {"generic", 23000, 198.345};
	
	/* Write file */
	ofstream outFile;
	outFile.open(fileName, ios::binary);
	
	if (outFile.is_open()){
		/* Write the struct to the file */
		// outFile.write((char *)&object, sizeof(Generic)); // old way
		outFile.write(reinterpret_cast<char *>(&object), sizeof(Generic));
		outFile.close();
		cout << "Created file {" << fileName << "} successfully." << endl;
	} else {
		cout << "Couldn't create file {" << fileName << "}" << endl;
	}
	
	/* Read file */
	ifstream inFile;
	inFile.open(fileName, ios::binary);
	Generic viewObj = {};
	
	if (inFile.is_open()){
		/* Read the struct from the file */
		// outFile.read((char *)&object, sizeof(Generic)); // old way
		inFile.read(reinterpret_cast<char *>(&viewObj), sizeof(Generic));
		inFile.close();
		cout << fileName << " opened successfully. Bellow are all the properties." << endl;
		cout << viewObj.property << endl;
		cout << viewObj.counterProperty << endl;
		cout << viewObj.compProperty << endl;
	} else {
		cout << "Couldn't create file {" << fileName << "}" << endl;
	}
	
	
	return 0;
}
















