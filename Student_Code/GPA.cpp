//
//  GPA.cpp
//  lab7tester
//
//  Created by William Pinkston on 9/23/16.
//  Copyright © 2016 Xunil_programming. All rights reserved.
//

#include "GPA.hpp"

GPA::GPA() {
    //
}

map<unsigned long long int,StudentInterface*> GPA::getMap() {
    return m_Map;
}

set<StudentInterface*,Comparator> GPA::getSet() {
    return m_Set;
}

bool GPA::importStudents(string mapFileName, string setFileName) {
    mapFileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+mapFileName;
    ifstream in_file;
    in_file.open(mapFileName);
    string fileLine;
    //input variables
    int num_id = -1;
    string name = "";
    string address = "";
    string phone = "";
    //input loop, if the loop reaches the end of a file writeEnable
    //when set, the loop writes into the file and then ends
    bool fRead = true;
    bool writeEnable = false;
    while (fRead) {
        getline(in_file,fileLine);
        num_id = atoi(fileLine.c_str());
        if(num_id == 0) {
            fRead = false;
        } else if (num_id == EOF) {
            writeEnable = true;
            in_file.clear();
            in_file.seekg(0,ios::beg);
        } else {
            getline(in_file,name);
            if (name != "") {
                getline(in_file,address);
                if (address != "") {
                    getline(in_file, phone);
                    if(phone != "") {
                        cout << num_id << endl;
                        cout << name << endl;
                        cout << address << endl;
                        cout << phone << endl;
                    } else {
                        fRead = false;
                    }
                } else {
                    fRead = false;
                }
            } else {
                fRead = false;
            }
        }
    }
    in_file.close();
    
    return false;
}

bool GPA::importGrades(string fileName) {
    return false;
}

string GPA::querySet(string fileName) {
     return "";
}

string GPA::queryMap(string fileName) {
    return "";
}

void GPA::clear(){}





