//
//  Student.cpp
//  lab7tester
//
//  Created by William Pinkston on 9/23/16.
//  Copyright © 2016 Xunil_programming. All rights reserved.
//

#include "Student.hpp"

Student::Student(int num_id, string name, string address, string phone) {
    m_ID = num_id;
    m_Name = name;
    m_Address = address;
    m_Phone = phone;
}

unsigned long long int Student::getID() {
    return 1;
}

string Student::getName() {
    return m_Name;
}

string Student::getGPA() {
    return "";
}

void Student::addGPA(double classGrade) {
    
}

string Student::toString() {
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
    stringstream ss;
    ss << m_ID <<"\n"<< m_Name <<"\n"<< m_Address <<"\n"<< m_Phone <<"\n"<< m_GPA;
    return ss.str();;
}





