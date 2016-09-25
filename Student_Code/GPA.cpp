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
    cout << "GPA::importStudents called with parameters: \n"+mapFileName+"\n"+setFileName <<endl<<endl;
    //----------------------------------
    //read map file
    mapFileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+mapFileName;
    ifstream in_fileM;
    in_fileM.open(mapFileName);
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
        getline(in_fileM,fileLine);
        num_id = atoi(fileLine.c_str());
        int check = in_fileM.peek();
        if(check == EOF) {
            if (writeEnable == true) {
                fRead = false;
            } else {
                writeEnable = true;
                in_fileM.clear();
                in_fileM.seekg(0,ios::beg);
            }
        } else if (num_id == 0) {
            fRead = false;
            return false;
        } else {
            getline(in_fileM,name);
            if (name != "") {
                getline(in_fileM,address);
                if (address != "") {
                    getline(in_fileM, phone);
                    if(phone != "") {
                        //cout << num_id << endl;
                        //cout << name << endl;
                        //cout << address << endl;
                        //cout << phone << endl;
                        if (writeEnable) {
                            m_Map.insert(pair<unsigned long long int, StudentInterface*>(num_id,new Student(num_id, name, address, phone)));
                            //cout << endl << "written" << endl << endl;
                        }
                    } else {
                        fRead = false;
                        return false;
                    }
                } else {
                    fRead = false;
                    return false;
                }
            } else {
                fRead = false;
                return false;
            }
        }
    }
    in_fileM.close();
    //----------------------------------
    
    //----------------------------------
    //read set file
    setFileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+setFileName;
    ifstream in_fileS;
    in_fileS.open(setFileName);
    fileLine = "";
    //input variables
    num_id = -1;
    name = "";
    address = "";
    phone = "";
    //input loop, if the loop reaches the end of a file writeEnable
    //when set, the loop writes into the file and then ends
    fRead = true;
    writeEnable = false;
    while (fRead) {
        getline(in_fileS,fileLine);
        num_id = atoi(fileLine.c_str());
        int check = in_fileS.peek();
        if(check == EOF) {
            if (writeEnable == true) {
                fRead = false;
            } else {
                writeEnable = true;
                in_fileS.clear();
                in_fileS.seekg(0,ios::beg);
            }
        } else if (num_id == 0) {
            fRead = false;
            return false;
        } else {
            getline(in_fileS,name);
            if (name != "") {
                getline(in_fileS,address);
                if (address != "") {
                    getline(in_fileS, phone);
                    if(phone != "") {
                        cout << num_id << endl;
                        cout << name << endl;
                        cout << address << endl;
                        cout << phone << endl;
                        if (writeEnable) {
                            StudentInterface* addS =new Student(num_id, name, address, phone);
                            m_Set.insert(addS);
                            cout << endl << "written" << endl << endl;
                        }
                    } else {
                        fRead = false;
                        return false;
                    }
                } else {
                    fRead = false;
                    return false;
                }
            } else {
                fRead = false;
                return false;
            }
        }
    }
    
    in_fileS.close();
    //----------------------------------
    return true;
}

bool GPA::importGrades(string fileName) {
    cout << "GPA::importGrades called with parameter: \n"+fileName <<endl<<endl;
    /*
     * importGrades()
     *
     * Read in and parse through the given file. Each part of an entry in the file
     * is given on a separate line in the file. Student ID is first, course is
     * second, and grade is last. There are no blank lines between entries. The
     * following is an example file:
     *
     * 	5291738860
     * 	CHEM134
     * 	A
     * 	9251734870
     * 	BOT180
     * 	B
     * 	9251733870
     * 	PE273
     * 	D+
     * 	5291738760
     * 	HIS431
     *  	A-
     *
     * Compute the GPA by finding the average of all the grades with a matching student ID
     * in the Grade file. The GPA is calculated by taking a Student's total sum GPA and
     * dividing by the number of classes taken. If the given student ID has no matching
     * grades in the Grade file, the GPA is 0.00. It is not necessary to store the course
     * names so long as the total number of courses taken is counted.
     *
     * You may assume that the given student ID exists in the map or set.
     *
     * Use the following point values for each grade.
     *
     *		  A = 4.0  A- = 3.7
     *	B+ = 3.4  B = 3.0  B- = 2.7
     *	C+ = 2.4  C = 2.0  C- = 1.7
     *	D+ = 1.4  D = 1.0  D- = 0.7
     *		  E = 0.0
     *
     * Returns false if an invalid filename is given, otherwise true.
     */
    
    
    
    
    return false;
}

string GPA::querySet(string fileName) {
    cout << "GPA::querySet called with parameter: \n"+fileName <<endl<<endl;
     return "";
}

string GPA::queryMap(string fileName) {
    cout << "GPA::queryMap called with parameter: \n"+fileName <<endl<<endl;
    return "";
}

void GPA::clear(){
    cout << "GPA::clear called" <<endl<<endl;
}





