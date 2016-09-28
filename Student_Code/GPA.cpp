//
//  GPA.cpp
//  lab7tester
//
//  Created by William Pinkston on 9/23/16.
//  Copyright © 2016 Xunil_programming. All rights reserved.
//

#include "GPA.hpp"

GPA::GPA()
{
    //
}
GPA::~GPA()
{
    this->clear();
}

map<unsigned long long int,StudentInterface*> GPA::getMap() {
    return m_Map;
}

set<StudentInterface*,Comparator> GPA::getSet()
{
    return m_Set;
}

//------------------------------------------------------------------
// utility functions

//filter a file
bool filter(string filename)
{
    
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
bool GPA::importStudents(string mapFileName, string setFileName)
{
    //----------------------------------
    //read map file
    //
//    mapFileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+mapFileName;
//    setFileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+setFileName;
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

bool GPA::importGrades(string fileName)
{
//    fileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+fileName;
    ifstream in_file_test;
    in_file_test.open(fileName);
    int fCheck = in_file_test.peek();
    if (fCheck != EOF)
    {
        string fileLine;
        int counter = 0;
        while (getline(in_file_test,fileLine))
        {
            counter++;
        }
        if (counter%3 == 0)
        {
            in_file_test.close();
            ifstream in_file;
            in_file.open(fileName);
            int num_ID;
            string className;
            string classGrade;
            while(getline(in_file, fileLine) && getline(in_file, className) && getline(in_file, classGrade))
            {
                double DclassGrade = 0;
                if (classGrade == "A")
                {
                    DclassGrade = 4.0;
                }
                else if (classGrade == "A-")
                {
                    DclassGrade = 3.7;
                }
                else if (classGrade == "B+")
                {
                    DclassGrade = 3.4;
                }
                else if (classGrade == "B")
                {
                    DclassGrade = 3.0;
                }
                else if (classGrade == "B-")
                {
                    DclassGrade = 2.7;
                }
                else if (classGrade == "C+")
                {
                    DclassGrade = 2.4;
                }
                else if (classGrade == "C")
                {
                    DclassGrade = 2.0;
                }
                else if (classGrade == "C-")
                {
                    DclassGrade = 1.7;
                }
                else if (classGrade == "D+")
                {
                    DclassGrade = 1.4;
                }
                else if (classGrade == "D")
                {
                    DclassGrade = 1.0;
                }
                else if (classGrade == "D-")
                {
                    DclassGrade = 0.7;
                }
                else if (classGrade == "E")
                {
                    DclassGrade = 0.0;
                }
                num_ID = atoi(fileLine.c_str());
                if (m_Map.find(num_ID) != m_Map.end()) {
                    m_Map[num_ID]->addGPA(DclassGrade);
                }
                else
                {
                    for (StudentInterface* s: m_Set)
                    {
                        if (s->getID() == num_ID)
                        {
                            s->addGPA(DclassGrade);
                        }
                    }
                }
            }
            return true;
        } else {
            //missing line in the file
            return false;
        }
        
    } else {
        //no file to open
        return false;
    }
}

string GPA::querySet(string fileName)
{
//    cout << "GPA::querySet called with parameter: \n"+fileName <<endl<<endl;
//    fileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+fileName;
    
    stringstream sout;
    ifstream in_file_test;
    in_file_test.open(fileName);
    int check = in_file_test.peek();
    set<StudentInterface*,Comparator>::iterator sI = m_Set.begin();
    if (check != EOF) {
        ifstream in_file;
        in_file.open(fileName);
        string fileLine = "";
        bool fRead = true;
        while (fRead) {
            getline(in_file,fileLine);
            if (fileLine != "") {
                int numID = atoi(fileLine.c_str());
                sI = m_Set.begin();
                for (int i = 0; i < m_Set.size(); i++) {
                    if (numID == (*sI)->getID()) {
                        string set_GPA = (*sI)->getGPA();
                        float Iset_GPA = atof(set_GPA.c_str());
                        sout << (*sI)->getID() << " ";
                        sout << fixed << setprecision(2) << Iset_GPA << " ";
                        sout << (*sI)->getName() << endl;
                        break;
                    }
                    sI++;
                }
            } else {
                fRead = false;
            }
        }
    }
    return sout.str();
}

string GPA::queryMap(string fileName)
{
//    fileName = "/Users/Howl/Documents/BYU/CS/CS_235/lab7/Files/"+fileName;
    
    stringstream sout;
    ifstream in_file_test;
    in_file_test.open(fileName);
    int check = in_file_test.peek();
    map<unsigned long long int,StudentInterface*>::iterator mI = m_Map.begin();
    if (check != EOF)
    {
        ifstream in_file;
        in_file.open(fileName);
        bool fRead = true;
        while (fRead)
        {
            string fileLine = "";
            getline(in_file,fileLine);
            if (fileLine != "")
            {
                int numID = atoi(fileLine.c_str());
                mI = m_Map.begin();
                for (int i = 0; i < m_Map.size(); i++)
                {
                    if (numID == mI->second->getID())
                    {
                        string map_GPA = mI->second->getGPA();
                        float Imap_GPA = atof(map_GPA.c_str());
                        sout.precision(20);
                        sout << mI->second->getID() << " ";
                        sout.precision(2);
                        sout << fixed << Imap_GPA << " ";
                        sout << mI->second->getName() << endl;
                        break;
                    }
                    mI++;
                }
            } else {
                fRead = false;
            }
        }
    }
    return sout.str();
}

void GPA::clear(){
    set<StudentInterface*,Comparator>::iterator sI = m_Set.begin();
    for (int i = 0; i < m_Set.size(); i++)
    {
        (*sI)->delete;
        sI++;
    }
    m_Set.clear();
    
    map<unsigned long long int,StudentInterface*>::iterator mI = m_Map.begin();
    for (int i = 0; i < m_Map.begin(); i++)
    {
        m_Map->delete;
        mI++;
    }
    m_Map.clear();
}



