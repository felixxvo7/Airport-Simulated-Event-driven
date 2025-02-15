#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout<<"USAGE: FileReadingExample.exe filename numRunways"<<endl;
		cout<<"where numRunways is an integer > 0."<<endl;
		return 0;
	}

	string filename = argv[1];
	int numRunways = stoi(argv[2]);
	
	cout << "The filename is: " << filename << endl;
	cout << "The number of runways is: " << numRunways <<endl;
	
	//
	//Opening the file, reading one line (just the first one of the file here) and parsing it
	//
	ifstream inputFile;
	inputFile.open(filename);  // opening the file for reading
	string line;
	
	cout << "The first line of the file contains the following information: " << endl;
	
	if(getline(inputFile, line))  //gets the next line from the file and saves it in 'line', if there is one
	{
		stringstream sst(line);  //stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
		string token;
		int time = 0;
		string callSign = "";
		string flightNum = "";
		string size = "";
		string requestType = "";
		
		sst >> token;  //grabbing the next token (reading time)
		time = stoi(token); //converting time (string format) to an int
		sst >> callSign;  //grabbing the next token (reading call sign)
		sst >> flightNum;  //grabbing the next token (reading flight number)
		sst >> size;  //grabbing the next token (reading plane size)
		sst >> requestType;  //grabbing the next token (reading request type, either landing or takeoff)

		//To show that we parsed all the relevant information:
		cout << "time=" << time << " callSign=" << callSign << " flightNum=" << flightNum << " size=" << size;
		cout << " requestType=" << requestType << endl;
	}
}
