//
//  GPA.hpp
//  lab7tester
//
//  Created by William Pinkston on 9/23/16.
//  Copyright © 2016 Xunil_programming. All rights reserved.
//

#ifndef GPA_hpp
#define GPA_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>

#include "GPAInterface.h"
#include "StudentInterface.h"
#include "Student.hpp"

class GPA : public GPAInterface {
protected:
    set<StudentInterface*,Comparator> m_Set;
    /*The key of the map should be the student ID*/
    map<unsigned long long int,StudentInterface*> m_Map;
    
public:
    GPA();
    ~GPA();
    
    map<unsigned long long int,StudentInterface*> getMap();
    set<StudentInterface*,Comparator> getSet();
    
    bool importStudents(string mapFileName, string setFileName);
    bool importGrades(string fileName);
    
    string querySet(string fileName);
    string queryMap(string fileName);
    
    void clear();
    
};

#endif /* GPA_hpp */
