#ifndef TABOLSY_H
#define TABOLSY_H

#include <string>
#include <sstream>
#include <map>
#include <vector>


namespace tabolsy {

/* some typedefs */
typedef std::vector<std::string> stringList;
typedef std::map <std::string ,stringList> tableData;
typedef std::map<std::string , int> stringIntMap;


class table {
    tableData data;
    stringList attributesInOrder;
    stringIntMap maxValues;
    void printSeparatorLine();
    void printAttributes();
    void printValues();

public:
    void addAttribute (const std::string&);
    void removeAttribute (const std::string &);
    stringList getAttributes ();
    int calculateWidth();
    void print();

    template <class T>
    void addDataValue(const std::string attribute , const T& value) {
        std::ostringstream os;
        os <<value;
        std::string valueStr(os.str());
        data[attribute].push_back(valueStr);
        maxValues[attribute] = std::max(maxValues[attribute],(int)valueStr.length());
    }

};





}






#endif // TABOLSY_H
