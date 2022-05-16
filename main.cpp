/*

        Text Editor program

        FCAI – Programming 1 – 2022 - Assignment 4

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

void findWord();

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
    file;
    char name[80];
    string word, token;
    int count = 0;
    do{
        cout << "pls enter your file name : ";
        cin >> name;
        file.open(name);

    }
    while(!file);

    cout << "enter your word : " << "\n ";
    cin >> word;

    transform(word.begin(),word.end(),word.begin(),::tolower);  // transform all letters of your word you search for into lower case
    while (file>> token ) {
        transform(token.begin(),token.end(),token.begin(),::tolower);   // transform every word you read from your file int lower case to check if it is equal to your word or not
        if (word == token){
            count++;


        }
    }
    cout << word << " repeated " << count << " time/s ";
    file.close();

}
void into_upper(){
    file ;
    ofstream target_file;
    char name [80],token[101];
    char c;
    do{
        cout <<"pls enter your file name : ";
        cin >> name;

        file.open(name);

        target_file.open("file_in_capital.txt");

    }
    while(!file);

    while (file.peek()!=EOF){  // loop till the end of your file
        c = file . get() ;  //get every char in your read file
        target_file.put(toupper(c)) ;  // convert every read char into upper case
    }
    file.close();
    target_file.close();
}

void into_lower (){

    file ;
    ofstream into_lower;
    char name [80] , c ;



    do{
        cout <<"pls enter your file name : ";
        cin >> name;

        file.open(name);

        into_lower.open("into_lower.txt");
    }
    while(!file);
    while (file.peek()!=EOF){
        c = file . get();
        into_lower.put(tolower(c)) ;
    }
    file.close();
    into_lower.close();


}

void first_char_capital(){
    file;
    char name[80] ;
    char token[250] ;
    string data ;
    do{
        cout << "pls enter your file name : ";
        cin >> name;
        file.open(name);

    } while (file.fail());

    file.getline(token,250,EOF);
    data+=token ;
    file.close() ;
    file.open(name,ios::out);
    data[0]=toupper(data[0]);
    file.put(data[0]);

    for (int i=1 ; i<data.length()-1 ;i++){
        if (data[i] == ' ' || data[i]=='\n' ){
            file.put(data[i]);

            if (isalpha(data[i+1])){

                data[i+1]= toupper(data[i+1]);
                file.put(data[i+1]);
                i++;
            }

            else {
                file.put(data[i+1]);
            }
        }

        else {
            data [i]=tolower(data[i]);
            file.put(data[i]);

        }
    }
    file.close();

}

int read_from_file(){
    string file_name;
    cout << endl << "please enter the file name..." << endl;
    cin >> file_name;
    ifstream user_file(file_name);

    if (user_file.is_open()){
        cout << "The content of the file is: " << endl;
        string myline;
        while (getline(user_file,myline)){
            cout << myline << endl;
        }
    }
    else{
        cout << "enable to open the file." << endl;
        return 0;
    }
    return 0;
}

int write_to_file(){
    string file_name;
    cout << endl << "please enter the file name..." << endl;
    cin >> file_name;
    ifstream user_file(file_name);

    if (user_file){
        cout << "This file is already exist" << endl;
        ofstream output_file;
        string add_text;
        cout << "What do you want to write to this file? " << endl;
        cin.ignore();
        getline(cin,add_text);

        output_file.open(file_name, ios :: app);

        output_file <<" "<<add_text;
        cout << "done" << endl;

        output_file.close();
    }

    else{
        cout << "This file is not exist, and I will create it for you" << endl;
        ofstream out_file;
        out_file.open(file_name, ios :: app);
        string add_text;
        cout << "What do you want to write to this file? " << endl;
        getline(cin,add_text);

        out_file << add_text;

        cout << endl;

        out_file.close();
    }
    return 0;
}

int delete_the_content(){
    string file_name;
    cout << endl << "please enter the file name..." << endl;
    cin >> file_name;
    ifstream file(file_name);
    ofstream output_file;

    if (file.is_open()){
        output_file.open(file_name);

        output_file << "";

        cout << "done" << endl;

        output_file.close();
    }
    else{
        cout << "Enable to open this file" << endl;
        return 0;
    }

    return 0;
}

int encrypt_content(){
    string file_name;
    cout << endl << "please enter the file name..." << endl;
    cin >> file_name;
    ifstream in_file(file_name);
    ofstream output_file;
    string myword;
    string words;


    while (getline(in_file,myword)){
        for (int i = 0; i < myword.length(); i++){
            words += myword[i];
        }
    }
    cout << words;

    output_file.open(file_name);

    while (output_file.is_open()){
        for (int i = 0; i < words.length(); i++){
            int c = words[i];
            c = c + 1;
            words[i] = char(c);
            output_file << words[i];
        }
        output_file.close();
    }


    return 0;
}

int decrypt_content(){
    string file_name;
    cout << endl << "please enter the file name..." << endl;
    cin >> file_name;
    ifstream in_file(file_name);
    ofstream output_file;
    string myword;
    string words;


    while (getline(in_file,myword)){
        for (int i = 0; i < myword.length(); i++){
            words += myword[i];
        }
    }
    cout << words;

    output_file.open(file_name);

    while (output_file.is_open()){
        for (int i = 0; i < myword.length(); i++){
            int c = words[i];
            c = c - 1;
            words[i] = char (c);
            output_file << words[i];
        }
        output_file.close();
    }

    return 0;
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
                "\nPress 6 to count your repeated word "
                "\nPress 7 to convert into upper case"
                "\nPress 8 to convert into lower case "
                "\nPress 9 to turn file content to 1st caps "
                "\nPress 10 to add new text to the end of a file "
                "\nPress 11 to display the content of a file "
                "\nPress 12 to empty a file "
                "\nPress 13 to encrypt a file content "
                "\nPress 14 to decrypt a file content "
                "\nPress 0 to Exit"
                "\n-----------------------------------\n";


        cin >> filterChoice;

        if (filterChoice >= 0 && filterChoice <= 14 ) {

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

                case 6 :
                    reapeted_word() ;
                    validInput = true;
                    break;
                case 7 :
                    into_upper() ;
                    validInput = true;
                    break;
                case 8 :
                    into_lower() ;
                    validInput = true;
                    break;
                case 9 :
                    first_char_capital() ;
                    validInput = true;
                    break;

                case 10 :
                    read_from_file() ;
                    validInput = true;
                    break;

                case 11 :
                    write_to_file() ;
                    validInput = true;
                    break;

                case 12 :
                    delete_the_content() ;
                    validInput = true;
                    break;

                case 13 :
                    encrypt_content() ;
                    validInput = true;
                    break;

                case 14 :
                    decrypt_content() ;
                    validInput = true;
                    break;


            }
        }
    }while (! validInput);


}
