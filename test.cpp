#include <iostream>
#include "tabolsy.h"

using namespace std;
int main()
{

    tabolsy::table t;
    t.addAttribute("ID");
    t.addAttribute("Number");
    t.removeAttribute ("IDDsxdf");
    t.addAttribute ("Email");
    t.addDataValue ("Email" , "moyle2010@gmail.com");
    t.addDataValue ("Number" , "1123214");
    t.addDataValue ("Number" , "112214");

    t.addDataValue("ID" , 1);
    t.addDataValue("ID" , 2);
    t.addDataValue ("Email" , "samy0@gmail.com");

    t.print();


}
