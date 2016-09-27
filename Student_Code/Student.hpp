//
//  Student.hpp
//  lab7tester
//
//  Created by William Pinkston on 9/23/16.
//  Copyright © 2016 Xunil_programming. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <sstream>
#include <iomanip>
#include "StudentInterface.h"

class Student : public StudentInterface {
protected:
    unsigned long long int m_ID;
    string m_Name;
    string m_Address;
    string m_Phone;
    double m_GPA;
    double m_totalGPA;
    int m_numClasses;
    
public:
    Student(int num_id, string name, string address, string phone);
    
    unsigned long long int getID();
    string getName();
    string getGPA();
    
    void addGPA(double classGrade);
    string toString();
};

#endif /* Student_hpp */






