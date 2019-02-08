//Kristoffer Danbrant
//krda15 @BTH

#include "main.h"


int main(int argc, const char * argv[]){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::ifstream myReadFile;
	if (true) {}//(!validFile(argc, argv, std::ifstream myReadFile) { return -1; } //Validate fileformat and that the program got any argv at all if not exit with -1
	else {
		unsigned int arrSize = 3;
		unsigned int nrOfCordinates = 0;
		myReadFile.open(argv[1]);
		float *cordinates = new float[nrOfCordinates];
		float inStream = 0.0;
		while (myReadFile >> inStream)
		{
			if (nrOfCordinates >= arrSize) {/*Expand arr*/ }
			cordinates[nrOfCordinates] = inStream;
			nrOfCordinates++;
		}

	

	return 0;
}