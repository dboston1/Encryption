#include<Encryption.h>

void Encryption::start(char* argv[], const Enums::Mode& mode, const Enums::Type& type){
    if(type == Enums::STREAM){
        Encryption::start_Stream(argv);
    }
    else{
        if(mode == Enums::ENCRYPT){
            Encryption::start_Block_Encrypt(argv);
        }
        else{
            Encryption::start_Block_Decrypt(argv);
        }
    }
}

void Encryption::start_Stream(char* argv[]){
    Encryption::parseInput(argv[2]);
    Encryption::setKey(argv[4]);
    Encryption::XOR();
    Encryption::writeOutputFile(argv[3]);
}

void Encryption::start_Block_Encrypt(char* argv[]){
    Encryption::parseInput(argv[2]);
    Encryption::addPadding();
    Encryption::setKey(argv[4]);
    Encryption::XOR();
    Encryption::swap();
    Encryption::writeOutputFile(argv[3]);
}

void Encryption::start_Block_Decrypt(char* argv[]){
    Encryption::parseInput(argv[2]);
    Encryption::setKey(argv[4]);
    Encryption::swap();
    Encryption::XOR();
    Encryption::removePadding();
    Encryption::writeOutputFile(argv[3]);
}

void Encryption::parseInput(const string& inputFileName){
    char c;
    ifstream istr(inputFileName);
    while(istr.get(c)){
        input += c;
    }
}

void Encryption::setKey(const string& keyFileName){
    ifstream fOpen(keyFileName);
    char c;
    while(fOpen.get(c)){
        key += c;
    }
}

void Encryption::XOR(){      
    char c;
    char keyC;
    char newC;
    unsigned int keyIndex = 0;
    for(unsigned int i = 0; i < input.size(); i++){
        if(keyIndex == key.size()){
            keyIndex = 0;
        }
        c = input.at(i);
        keyC = key.at(keyIndex);
        newC = c ^ keyC;
        input.at(i) = newC;
        keyIndex++;
    }
}

void Encryption::swap(){      
    int startIndex = 0;
    int endIndex = input.size() - 1;
    unsigned int keyIndex = 0;
    int ascii;
    char placeHolder;
    for(unsigned int i = 0; i < input.size(); i++){
        if(keyIndex == key.size()){
            keyIndex = 0;
        }
        if(startIndex >= endIndex){
            return;
        }
        ascii = (int(key.at(keyIndex))) % 2;
        if(ascii == 1){
            placeHolder = input.at(endIndex);
            input.at(endIndex) = input.at(startIndex);
            input.at(startIndex) = placeHolder;
            endIndex--;
        }
        startIndex++;
        keyIndex++;
    }
        
}

void Encryption::removePadding(){     
    char c = input.back();
    while(c == char(128)){
        input.pop_back();
        c = input.back();
    }
}

void Encryption::addPadding(){
   if(input.size() % 8 != 0){
        int remainder = 8 - (input.size() % 8);
        for(int i = 0; i < remainder; i++){
            input += char(128);
        }
    } 
}

void Encryption::writeOutputFile(const string& outputFileName){
    ofstream ostr(outputFileName);
    ostr << input;
}























