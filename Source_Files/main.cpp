#include<Encryption.h>
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

// CLASS INFORMATION:
//main.cpp performs error-checking, determines method and mode (block vs. stream, decrypt vs. encrypt) and passes control to appropriate class. See README for more information.

void printError(){
    cerr << "ERROR: Missing / Additional Arguments: \n---------------------------------------------------------------------------------------\nPlease run program using 5 arguments in following form: ./PA1 1 2 3 4 5\n1 should be either a 'B' or 'S' for block or stream encryption\n2 is the input filename\n3 is the output filename\n4 is the keyfile (file containing symmetric key)\n5 should be either 'E' for encryption or 'D' for decryption.\nSee README for more information.\n---------------------------------------------------------------------------------------" << endl;
}

int checkValidFile(const string& filename){
    ifstream fOpen(filename);         // opens file to be read 
    if (fOpen.fail()){ 
        cerr << "Failed to Open Input File: " << filename << endl; // 
        return -3;
    }
    return 0;
}

int isEmpty(const string& filename){
    ifstream fOpen(filename);
    if(fOpen.peek() == EOF){    // note: this considers a file containing only white space as NOT empty; use if((fOpen >> ws).peek() == EOF){ if only white space is considered non-valid.
        return -1;
    }
    return 0;   
}

int validBlockKeySize(const string& keyFileName){
    ifstream fOpen(keyFileName);
    char c;
    string keyTemp;
    while(fOpen.get(c)){
        keyTemp += c;
    }
    if(keyTemp.size() != 8){
        return -1;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    // check for correct number of arguments 
    if (argc != 6){          
        printError();
        return -1;
    }
    // Parse arguments:
    string inputFileName;
    string outputFileName;
    string keyFileName;
    
    //error checking:
    string stringType;
    string stringMode;
    stringstream ss1(argv[1]);
    stringstream ss2(argv[5]);
    ss1 >> stringType;
    ss2 >> stringMode;
    
    if(stringType.compare("B") != 0 && stringType.compare("b") != 0 && stringType.compare("S") != 0 && stringType.compare("s") != 0){
        printError();
        return -1;
    }
    if(stringMode.compare("E") != 0 && stringMode.compare("e") != 0 && stringMode.compare("D") != 0 && stringMode.compare("d") != 0){
        printError();
        return -1;
    }
    checkValidFile(argv[2]);    // checks for valid input file
    checkValidFile(argv[4]);    // checks for valid key file
    
    if(isEmpty(argv[2]) == -1){     // if input file is empty, create empty output file
        ofstream outputFile(argv[3]);
        return 0;
    }
    
    if(isEmpty(argv[4]) == -1){
        cout << "Key File is Empty: Please Use Valid, Non-Empty Key File" << endl;
        return -2;
    }
        
    // set type and mode
    Enums::Type type = Enums::STREAM;
    Enums::Mode mode = Enums::DECRYPT;
    if(stringType.compare("B") == 0 || stringType.compare("b") == 0){
        type = Enums::BLOCK;
    }
    if(stringMode.compare("E") == 0 || stringMode.compare("e") == 0){
        mode = Enums::ENCRYPT;
    }
    
    // pass control to Encryption class, and one last error check if mode == Block:
    if(type == Enums::BLOCK){
        if(validBlockKeySize(argv[4]) != 0){
            cout << "Error: For Block Mode, Keyfile Must Contain a Key with 64 bits (8 bytes)" << endl;
            return -4;
        }
    }
    Encryption temp;
    temp.Encryption::start(argv, mode, type);
    return 0;
}


        
