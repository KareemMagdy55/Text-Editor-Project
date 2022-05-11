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
#include "algorithm"

using namespace std;

void reapeted_word();

void into_upper();

void mergeFiles();

int main() {

    mergeFiles();
    reapeted_word();
    into_upper();

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

void reapeted_word(){
    fstream datafile;
    char name[80];
    string word, token;
    int count = 0;
    do{
        cout << "pls enter your file name : ";
        cin >> name;
        datafile.open(name);

    }
    while(!datafile);

    cout << "enter your word : " << "\n ";
    cin >> word;
    transform(word.begin(),word.end(),word.begin(),::tolower); // transform all letters of your word you search for into lower case
    while (datafile>> token ) {
        transform(token.begin(),token.end(),token.begin(),::tolower);  // transform every word you read from your file int lower case to check if it is equal to your word or not
        if (word == token){
            count++;


        }
    }
    cout << word << " repeated " << count << " time/s ";
    datafile.close();

}
void into_upper(){
    ifstream datafile ;
    ofstream target_file;
    char name [80],token[101];
    char c;
    do{
        cout <<"pls enter your file name : ";
        cin >> name;

        datafile.open(name);

        target_file.open("file_in_capital.txt");

    }
    while(!datafile);

    while (datafile.peek()!=EOF){  // loop till the end of your file
        c = datafile . get() ;  //get every char in your read file
        target_file.put(toupper(c)) ;  // convert every read char into upper case

    }
    datafile.close();
    target_file.close();


}

