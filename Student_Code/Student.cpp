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
    m_GPA = 0;
    m_totalGPA = 0;
    m_numClasses = 0;
}

unsigned long long int Student::getID() {
    return m_ID;
}

string Student::getName() {
    return m_Name;
}

string Student::getGPA() {
    stringstream GPP;
    GPP << m_GPA;
    return GPP.str();
}

void Student::addGPA(double classGrade) {
    m_numClasses++;
    m_totalGPA += classGrade;
    m_GPA = (m_totalGPA / m_numClasses);
}

string Student::toString() {
    stringstream ss;
    ss.precision(2);
    ss << m_ID <<"\n"<< m_Name <<"\n"<< m_Address <<"\n"<< m_Phone <<"\n"<< fixed << setprecision(2);
    if (m_GPA != 0) {
        ss << fixed /* << setprecision(2) */ << m_GPA /*- 0.005*/;
    } else {
        ss << fixed /* << setprecision(2) */ << m_GPA;
    }
    return ss.str();;
}





