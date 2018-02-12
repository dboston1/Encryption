#ifndef Encryption_H_INCLUDE
#define Encryption_H_INCLUDE

#include<Enums.h>
#include<iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::getline;
#include<fstream>
using std::ofstream;
using std::ifstream;
using std::ws;
#include<sstream>
using std::stringstream;
#include<string>
using std::string;

class Encryption{
public:
    void start(char* argv[], const Enums::Mode& mode, const Enums::Type& type);
private:
    void start_Block_Encrypt(char* argv[]);
    void start_Block_Decrypt(char* argv[]);
    void start_Stream(char* argv[]);
    void swap();
    void parseInput(const string& inputFileName);
    void XOR();
    void setKey(const string& keyFileName);
    void writeOutputFile(const string& outputFileName);
    void removePadding();
    void addPadding();
    string input;
    string key;
};


#endif
