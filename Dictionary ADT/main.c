#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Dictionary.h"


int main() {
    Dictionary d;
    initDict(&d, 26);

    Student s1 = newStudent("111", newName("Jolo", "Na", "Tangpuz"), 'M', newDate(26, 12, 1999), "BSIT", 3);
    Student s2 = newStudent("222", newName("Nouffa", "Si", "Ali"), 'F', newDate(10, 8, 1999), "BSTM", 2);
    Student s3 = newStudent("333", newName("Pasar", "Ko", "Dsa"), 'M', newDate(7, 7, 7777), "BSCS", 1);

    insertSorted(&d, s1);
    insertSorted(&d, s2);
    insertSorted(&d, s3);

    accessStud(d, "111");
    accessStud(d, "222");
    accessStud(d, "333");

    deleteStud(&d, "222");

    visualize(d);

    return 0;
}
