//
//  main.cpp
//  lab7tester
//
//  Created by William Pinkston on 9/23/16.
//  Copyright © 2016 Xunil_programming. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
#include "Factory.h"
#include "StudentInterface.h"
#include "GPAInterface.h"

#include <iomanip>

int main(int argc, const char * argv[]) {
    GPAInterface* G_obj = Factory::getGPA();
    string one;
    string two;
    getline(cin,one);
    getline(cin,two);
    G_obj->importStudents(one, two);
    map<unsigned long long int,StudentInterface*> G_map = G_obj->getMap();
    cout << G_map[11812277]->toString();
    
    return 0;
}
