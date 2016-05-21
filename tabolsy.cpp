#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "tabolsy.h"
using namespace std;
using namespace tabolsy;


void table::addAttribute(const string &attribute){
    data[attribute] = stringList();
    maxValues[attribute] = attribute.length(); //initialize max length for that attribute
    attributesInOrder.push_back(attribute);
}

void table::removeAttribute(const string &attribute){
    /* remove it from attributeInOrder */
    stringList::iterator it = find(attributesInOrder.begin(),attributesInOrder.end(),attribute);
    if (it == attributesInOrder.end())
        return;

    attributesInOrder.erase(it);

    /* remove it from data */
    data.erase(data.find(attribute));
    /* remove it from maxValues */
    maxValues.erase(maxValues.find(attribute));
}

stringList table::getAttributes() {
    stringList returnVal;
    tableData::iterator it = data.begin();
    while (it !=data.end())
        returnVal.push_back(it->first) , it++;
    return returnVal;
}

void table::printSeparatorLine() {
    cout<<'+';
    stringList::iterator it = attributesInOrder.begin();
    for (;it!=attributesInOrder.end();it++) {
        string attribute = *it;
        int requiredLength = maxValues[attribute] + 2;
        cout <<string (requiredLength,'-');
        cout <<'+';
    }
    cout <<"\n";
}

void table::printAttributes() {
    stringList::iterator it = attributesInOrder.begin();
    cout <<'|';
    for (;it!=attributesInOrder.end();it++) {
        string attribute = *it;
        cout <<' ';
        cout <<attribute;
        int remaining = maxValues[attribute] + 1 - attribute.length();
        cout <<string(remaining,' ');
        cout <<'|';
    }
    cout <<"\n";
}

void table::printValues() {

    size_t maxValueCount = 0;
    for (tableData::iterator it = data.begin();it!=data.end();it++)
        maxValueCount = max (maxValueCount , it->second.size());
    vector<int> counters(attributesInOrder.size() , 0);
    while (maxValueCount--) {
        cout <<'|';
        for (size_t i=0;i<attributesInOrder.size();i++) {
            string attribute = attributesInOrder[i];
            if (counters[i] >= data[attribute].size()){
                cout <<string(maxValues[attribute] + 2 ,' ');
            }
            else {
                string value = data[attribute][counters[i]];
                counters[i]++;
                cout <<' ';
                cout <<value;
                int remaining = maxValues[attribute] + 1 - value.length();
                cout <<string(remaining,' ');
            }
            cout <<'|';
        }
        cout <<endl;
    }
}

void table::print() {


    printSeparatorLine();
    printAttributes();
    printSeparatorLine();
    printValues();
    printSeparatorLine();


}
