#include <iostream>
#include <cctype>
#include <vector>//vectors
#include "funcs.h"
std::string removeLeadingSpaces(std::string line){
    bool start = false;
    std::string s = "";
    for(int i = 0; i < line.length(); ++i){
        if(!isspace(line[i])){
            start = true;
        }
        if(start){
            s+=line[i];
        }
    }
    return s;
}

int countChar(std::string line, char c){
    int counter = 0;
    for(int i = 0; i < line.length(); ++i){
        if(line[i] == c){
            ++counter;
        }
    }
    return counter;
}

void executePrograms(){
    int shift = 0;//amount of indents
    int a = 0;//incrementer
    std::vector<std::string> line_vector;//vector to store lines
    std::string program = "";// string for removing all of the spaces
    std::string new_program = "";//string for the new program
    std::string line = "";//every line of code
    while(getline(std::cin, line)){//read in every line individually
        line_vector.push_back(removeLeadingSpaces(line));//make a vector with all the lines to access when adding indents back
        program+= removeLeadingSpaces(line);//append the line without indents into the new program
        program+= "\n";// move the program into a new line for the next line to be read
    }

    std::cout << program << std::endl;// print out the program
    while(a < line_vector.size()){//loop through every vector made in when removing the indents.

        
        for(int i = 0; i < countChar(line_vector[a], '}'); ++i){//counting closing brackets because I can't seem to index into the end of the line properly
            --shift;
        }

        for(int i = 0; i < shift; ++i){//add back the new shifts
            new_program += "\t";
        }
        new_program += line_vector[a];//add the line without indents onto the indents
        
        new_program += "\n";//move everything into the next line for the new line to be written

        
        shift = shift + (countChar(line_vector[a], '{'));//add shift whenever there is a opening bracket
        ++a;//increment a for the while loop
    }
    std::cout << new_program << std::endl;//print out program.
}
