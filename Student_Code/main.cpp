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

using namespace std;

int main(int argc, const char * argv[]) {
    GPAInterface* G_obj = Factory::getGPA();
    string one;
    string two;
    getline(cin,one);
    getline(cin,two);
    G_obj->importStudents(one, two);
    map<unsigned long long int,StudentInterface*> G_map = G_obj->getMap();
    set<StudentInterface*,Comparator> G_set = G_obj->getSet();
    
    map<unsigned long long int,StudentInterface*>::iterator mI = G_map.begin();
    set<StudentInterface*,Comparator>::iterator sI = G_set.begin();
    
    cout << "quit (q)" << endl;
    string q;
    cin >> q;
    if (q == "q") {
        G_obj->clear();
    }
    return 0;
}




