/*
        Text Editor program

        FCAI – Programming 1 – 2022 - Assignment 3

        Date: 8 May 2022

        Author1 : Abdullah Ibrahim  ID : 20210590
        Author2 : Kareem Magdy      ID : 20211071
        Author3 : Mohammed Reyad    ID : 20211074

        Teaching Assistant: Eng. Afaf
*/


#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

void mergeFiles();

int main() {
    mergeFiles();
    return 0;
}

void mergeFiles(){

    ifstream originalFile ;
    ifstream newFile ; // the new file to merge with original one.
    ofstream mergedFile ;

    char name1[81]; // file 1 name
    char name2[81]; // file 2 name


    do {
        cout << "----------------------------------\n"
                "Please enter a valid file names.\n"
                "Please, enter original file name:";
        cin >> name1;
        cout << "Please, enter new file name:";
        cin >> name2;


        originalFile.open(name1);
        newFile.open(name2);
        mergedFile.open("Merged File.txt");

    }while(!originalFile || !newFile) ; // While file names are not valid, get another file names from user


    mergedFile << originalFile.rdbuf() << ' ' << newFile.rdbuf(); // read buffers of file 1 & 2 and save it in mergedFile.

    originalFile.close();
    newFile.close();
    mergedFile.close();


}