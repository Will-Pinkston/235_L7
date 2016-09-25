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
#include "StudentInterface.h"

class Student : public StudentInterface {
protected:
    unsigned long long int m_ID;
    string m_Name;
    string m_Address;
    string m_Phone;
    int m_GPA;
    
public:
    Student(int num_id, string name, string address, string phone);
    
    /*
     * getID()
     *
     * Returns the ID of the Student.
     */
    unsigned long long int getID();
    
    /*
     * getName()
     *
     * Returns the name of the Student
     */
    
    string getName();
    
    /*
     * getGPA()
     *
     * Returns the string representation of the Student's GPA.
     */
    
    string getGPA();
    
    /*
     * addGPA()
     *
     * Incorporates the given course grade into the Student's overall GPA.
     */
    
    void addGPA(double classGrade);
    
    /*
     * toString()
     *
     * The student object will be put into string representation. Student info will be
     * ordered ID, name, address, phone number, and GPA. Each piece of information will
     * be on its own line. GPA will not have a newline following it and the precision
     * of the GPA will be set to two decimal places. For example,
     *
     * 123456789
     * Ben Thompson
     * 17 Russell St, Provo, UT 84606
     * 555-555-5555
     * 3.12
     *
     * Returns a string representation of the student object There is no trailing new line.
     */
    string toString();
};

#endif /* Student_hpp */
