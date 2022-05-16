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

fstream file ;
void loadFile();

void countWords();

void countLines();

void countChars();

void findWord()

void reapeted_word();

void into_upper();

void mergeFiles();

void into_lower();

void first_char_capital();

void mainTextEditor();

int main() {

    loadFile();
    while (true) {
        mainTextEditor();
    }
    return 0;
}
void loadFile(){

    char fileName[81];

    cout << "Welcome to your text editor program\n"
            "Please, input file name :";

    cin >> fileName ;

    file.open(fileName);

    if(file.fail()){
        cout << "This is a new file. I created it for you\n";
        file.open(fileName, std::fstream::out );

    }else {
        cout << "This File Already Exists\n";
    }

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
void countWords(){

    string word  ;
    int counter = 0;

    while(file.peek() != EOF) { // Iterate till it is the end of file is reached and avoid EOF char
        file >> word;

        if (regex_search(word, regex("[a-zA-Z]+"))){ // find every sequence of alphas.
            counter ++ ;
        }
    }
    cout << counter << endl ;

}
void countChars(){
    int charCounter = 0;

    while(  file.peek() != EOF) { // Iterate till it is the end of file is reached and avoid EOF char
        if (file.get()){  // if there is chars in file add one to charCounter.
            charCounter ++ ;    } // count every char except spaces
    }
    cout << charCounter << endl;

}
void countLines(){
    int linesCounter = 0;

    while(!file.eof() && file.peek() != EOF) { // Iterate till it is the end of file is reached and avoid EOF char

        if (file.get() == '\n'){
            linesCounter ++ ;
        }

    }
    linesCounter ++ ;
    cout << linesCounter << endl ;

}
string tolower(string &word){ // overload tolower function to make a lower case strings.
    for (char &c : word){
        c = tolower(c);
    }
    return word ;
}
void findWord(){

    string userWord = "NONE";
    string fileWord ;

    cout << "Please Enter a word to find:";
    cin >> userWord;

    while(!file.eof() && file.peek() != EOF) {
        file >> fileWord;

        if (tolower(fileWord) == tolower(userWord)){
            cout << "Word was found in the file";
            break;
        }else {
            cout << "Word was not found in the file";
            break;
        }
    }
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

void into_lower (){

    ifstream datafile ;
    ofstream into_lower;
    char name [80] , c ;



    do{
        cout <<"pls enter your file name : ";
        cin >> name;

        datafile.open(name);

        into_lower.open("into_lower.txt");
    }
    while(!datafile);
    while (datafile.peek()!=EOF){
        c = datafile . get();
        into_lower.put(tolower(c)) ;
    }
    datafile.close();
    into_lower.close();


}

void first_char_capital(){
    fstream File;
    char name[80] ;
    char token[250] ;
    string data ;
    do{
        cout << "pls enter your file name : ";
        cin >> name;
        File.open(name);

    } while (File.fail());

    File.getline(token,250,EOF);
    data+=token ;
    File.close() ;
    File.open(name,ios::out);
    data[0]=toupper(data[0]);
    File.put(data[0]);

    for (int i=1 ; i<data.length()-1 ;i++){
        if (data[i] == ' ' || data[i]=='\n' ){
            File.put(data[i]);

            if (isalpha(data[i+1])){

                data[i+1]= toupper(data[i+1]);
                File.put(data[i+1]);
                i++;
            }

            else {
                File.put(data[i+1]);
            }
        }

        else {
            data [i]=tolower(data[i]);
            File.put(data[i]);

        }
    }
    File.close();

}
void mainTextEditor(){
    bool validInput = false ;

    do {
        int filterChoice = 0;
        cout << "\n-----------------------------------\n"
                "Please Choose a filter to apply it to your image\n"
                "\nPress 1 to merge two files "
                "\nPress 2 to count words"
                "\nPress 3 to count lines"
                "\nPress 4 to count characters"
                "\nPress 5 to find word"
                "\nPress 0 to Exit"
                "\n-----------------------------------\n";


        cin >> filterChoice;

        if (filterChoice >= 0 && filterChoice <= 3) {

            switch (filterChoice) {
                case 0 :
                    exit(0);
                case 1:
                    mergeFiles();
                    validInput = true;
                    break;
                case 2 :
                    countWords();
                    validInput = true;
                    break;
                case 3 :
                    countLines();
                    validInput = true;
                    break;
                case 4 :
                    countChars();
                    validInput = true;
                    break;
                case 5 :
                    findWord() ;
                    validInput = true;
                    break;

            }
        }
    }while (! validInput);



}
