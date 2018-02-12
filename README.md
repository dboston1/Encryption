
---------------------------
About:
---------------------------
This is a symmetric encryption / decryption program designed by Drew Boston, Colorado State University (Feb. 2018). It is designed to utilize both block encryption as well as stream encryption, using a user-supplied keyfile. Project specifications can be found at: https://www.cs.colostate.edu/~cs356/assignments/PA1.php.

---------------------------
General / Running Program:
---------------------------
After compiling using "Make", it produces the executable PA1. PA1 can be run with the following command:

./PA1 arg1 arg2 arg3 arg4 arg5

where:
* arg1 = either 'B' or 'b' for block encryption, or 'S' / 's' for stream encryption.
* arg2 = the input filename
* arg3 = the desired output filename (will overwrite existing files with same name / location)
* arg4 = the keyfile (see keyfile notes below)
* arg5 = either 'E' / 'e' for encryption or 'D' / 'd' for decryption. 

For example, 

$ ./PA1 b input.txt output.txt key.txt d

---------------------------
Key / Keyfile Notes:
---------------------------
This program was designed to be symmetric, meaning the same key to encrypt data will also decrypt it. For Block encryption/decryption, the keyfile must contain a key consisting of exactly 64 bits (8 bytes). Spaces, newlines, and other ASCII characters will all count as 1 byte towards this total (i.e. whitespace is not excluded). 


The keyfile should be a textfile containing the exact symmetric key desired for encryption; white space will be considered part of the key (as will any other ASCII characters, including newlines).

---------------------------
Error Codes:
---------------------------
(-1) If an argument is missing, or is not inputted as specified above, the program will print the correct way to run the program to the terminal, and exit with error code (-1). 

(-2) If the keyfile is empty, the program will print such to the terminal, and exit with an error code (-2).

(-3) If the input file does not exist or cannot be opened, a message stating this will print to the terminal, and the program will exit with error code (-3). 

(-4) For Block mode, if the key within the keyfile is not exactly 64 bytes, an error will print to terminal stating this and program will exit with error code (-4).

---------------------------
Additional Notes:
---------------------------
* If the input file is empty, the program will not throw an error; it will simply produce an empty output file.
* Although the majority of methods and variables are private, this is by no means meant to be a secure program, and no further security measures were implemented.
* Due to the way that the input file is stored in a single string (quicker than a vector of substrings), the program is limited by the string class's max_size. As this is over 4 billion characters in c++11 (about a 4GB textfile, or 300 copies of the entire Harry Potter Series), this will not be a problem except in extraordinary circumstances.
* Running the terminal command:

  $ make clean

will remove all object files and the PA1 executable. 
* Running the terminal command:

  $ make package

will create a tar file containing Makefile, README, all .cpp files, and all .h files.


