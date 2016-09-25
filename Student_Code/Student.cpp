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
    return "";
}

string Student::getGPA() {
    return "";
}

void Student::addGPA(double classGrade) {
    
}

string Student::toString() {
    return "";
}
