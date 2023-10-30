#include <iostream>
#include <fstream>
#include <string>

void captureNote(){     //Function for the user to take notes, that will then be stored in a text file
    std::fstream notesFile;
    notesFile.open("notes.txt", std::fstream::app);

    //User enters note
    std::string text;
    std::cout << "Enter your note: ";
    std::getline(std::cin, text);

    if(notesFile.is_open()){
        notesFile << text << "\n";

        notesFile.close();
        std::cout << "Note taken!" << "\n";

    }else{
        std::cerr << "Unable to open file for writing." << "\n";
    }


}

void listNotes(){

}

void listCommands(){
    std::cout << "Here are all the commands:" << "\n";
    std::cout << "1. capture - Used to take note. './main capture'" << "\n";
    std::cout << "2. read - List all notes. './main read'" << "\n";
    std::cout << "3. help - List all commands. './main capture'" << "\n";
}



int main(int argc, char* argv[]){

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <argument>" << std::endl;
        return 1;
    }

    std::string command =  argv[1];
    // Arguement 1 determines which command to use
    if(command == "capture"){
        captureNote();
    }else if(command == "help"){
        listCommands();
    }else{
        std::cout << "Command not found, run './sBCapture help' to list all possible commands";
    }
    return 0;
}