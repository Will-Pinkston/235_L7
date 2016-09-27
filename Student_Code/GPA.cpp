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
                        //cout << num_id << endl;
                        //cout << name << endl;
                        //cout << address << endl;
                        //cout << phone << endl;
//                        if (writeEnable) {
//                            m_Map.insert(pair<unsigned long long int, StudentInterface*>(num_id,new Student(num_id, name, address, phone)));
                            //cout << endl << "written" << endl << endl;
                        }
//                    } else {
//                        fRead = false;
//                        return false;
//                    }
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
     */
    fileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+fileName;
    //bool fTest = filter(fileName);
    //if (!fTest) {
    //    return false;
    //}
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
            //--------------------------------
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
            //--------------------------------
            getline(in_file, className);
            if (className != "") {
                getline(in_file, grade);
                if (grade != "") {
                    if (writeEnable) {
                        if (grade == "A") {
                            classGrade = gradeA;
                        } else if (grade == "A-") {
                            classGrade = gradeA - 0.3;
                        } else if (grade == "B+") {
                            classGrade = gradeA - 0.6;
                        } else if (grade == "B") {
                            classGrade = gradeA - 1;
                        } else if (grade == "B-") {
                            classGrade = gradeA - 1.3;
                        } else if (grade == "C+") {
                            classGrade = gradeA - 1.6;
                        } else if (grade == "C") {
                            classGrade = gradeA - 2;
                        } else if (grade == "C-") {
                            classGrade = gradeA - 2.3;
                        } else if (grade == "D+") {
                            classGrade = gradeA - 2.6;
                        } else if (grade == "D") {
                            classGrade = gradeA - 3;
                        } else if (grade == "D-") {
                            classGrade = gradeA - 3.3;
                        } else if (grade == "E") {
                            classGrade = gradeA - 4;
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
    
    /* Compute the GPA by finding the average of all the grades with a matching student ID
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










