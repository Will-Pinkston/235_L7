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

//------------------------------------------------------------------
// utility functions

//filter a file
bool filter(string filename) {
    
    ifstream in_file;
    in_file.open(filename);
    int fcheck = in_file.peek();
    if (fcheck == EOF) {
        return false;
    }
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
        int check = in_file.peek();
        if(check == EOF) {
            if (writeEnable == true) {
                fRead = false;
            } else {
                writeEnable = true;
                in_file.clear();
                in_file.seekg(0,ios::beg);
            }
        } else if (num_id == 0) {
            fRead = false;
            return false;
        } else {
            getline(in_file,name);
            if (name != "") {
                getline(in_file,address);
                if (address != "") {
                    getline(in_file, phone);
                    if(phone != "") {
                        //
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
    in_file.close();
    
    return true;
}

//------------------------------------------------------------------
//------------------------------------------------------------------
bool GPA::importStudents(string mapFileName, string setFileName) {
    cout << "GPA::importStudents called with parameters: \n"+mapFileName+"\n"+setFileName <<endl<<endl;
    //----------------------------------
    //read map file
    //
    mapFileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+mapFileName;
    setFileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+setFileName;
    //check for faulty files
    bool mTest = filter(mapFileName);
    bool sTest = filter(setFileName);
    if (!mTest || !sTest) {
        return false;
    }
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
                        if (writeEnable) {
                            m_Map.insert(pair<unsigned long long int, StudentInterface*>(num_id,new Student(num_id, name, address, phone)));
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
                        if (writeEnable) {
                            StudentInterface* addS =new Student(num_id, name, address, phone);
                            m_Set.insert(addS);
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
    fileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+fileName;
    // check if valid file
    ifstream iFile_test;
    iFile_test.open(fileName);
    int ifileItest = iFile_test.peek();
    if (ifileItest == EOF) {
        return false;
    }
    
    map<unsigned long long int,StudentInterface*>::iterator mI = m_Map.begin();
    set<StudentInterface*,Comparator>::iterator sI = m_Set.begin();
    float gradeA = 4.0;
    float classGrade = -1;
    int numID;
    string fileLine;
    string className;
    string grade;
    
    ifstream in_file;
    in_file.open(fileName);
    //-----------------------------------------------------
    //read and parse file data
    string MorS;
    bool fRead = true;
    bool writeEnable = false;
    while (fRead) {
        getline(in_file,fileLine);
        numID = atoi(fileLine.c_str());
        int check = in_file.peek();
        if(check == EOF) {
            if (writeEnable == true) {
                fRead = false;
            } else {
                writeEnable = true;
                in_file.clear();
                in_file.seekg(0,ios::beg);
            }
        } else if (numID == 0) {
            fRead = false;
            return false;
        } else {
            //---------------------------------------------
            //is a map or a set?
            //check map
            bool IDfound = false;
            mI = m_Map.begin();
            for (int i = 0; i < m_Set.size(); i++) {
                if (mI->second->getID() == numID) {
                    MorS = "M";
                    IDfound = true;
                } else {
                    mI++;
                }
            }
            if (!IDfound) {
                sI = m_Set.begin();
                for (int i = 0; i < m_Map.size(); i++) {
                    if ((*sI)->getID() == numID) {
                        MorS = "S";
                        IDfound = true;
                    } else {
                        sI++;
                    }
                }
            }
            //---------------------------------------------
            getline(in_file, className);
            if (className != "") {
                getline(in_file, grade);
                if (grade != "") {
                    if (writeEnable) {
                        if (grade == "A") {
                            classGrade = 4.0;
                        } else if (grade == "A-") {
                            classGrade = 3.7;
                        } else if (grade == "B+") {
                            classGrade = 3.4;
                        } else if (grade == "B") {
                            classGrade = 3.0;
                        } else if (grade == "B-") {
                            classGrade = 2.7;
                        } else if (grade == "C+") {
                            classGrade = 2.4;
                        } else if (grade == "C") {
                            classGrade = 2.0;
                        } else if (grade == "C-") {
                            classGrade = 1.7;
                        } else if (grade == "D+") {
                            classGrade = 1.4;
                        } else if (grade == "D") {
                            classGrade = 1.0;
                        } else if (grade == "D-") {
                            classGrade = 0.7;
                        } else if (grade == "E") {
                            classGrade = 0.0;
                        } else {
                            cout << "Incorrect grade read." << endl;
                        }
                        //-------- -------- -------- ---- --- -- -
                        // write to the student's file
                        // void Student::addGPA(double classGrade)
                        if (classGrade != -1) {
                            if (MorS == "M") {
                                m_Map[numID]->addGPA(classGrade);
                            } else if (MorS == "S") {
                                sI = m_Set.begin();
                                for (int i = 0; i < m_Map.size(); i++) {
                                    if ((*sI)->getID() == numID) {
                                        (*sI)->addGPA(classGrade);
                                        break;
                                    } else {
                                        sI++;
                                    }
                                }

                            }
                        }
                        //-------- -------- -------- ---- --- -- -
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
    in_file.close();
    //-----------------------------------------------------
    return true;
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
    m_Set.clear();
    m_Map.clear();
}










