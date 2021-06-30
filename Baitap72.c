#include <stdio.h>
#include <string.h>

struct FamilyStruct
{
    char name[128];
    float elecUnit;
    float charges;
} FamilyDefault = {"***",0,0};
typedef struct FamilyStruct Family;

float TienDien(float units) {
    if (units <= 250) {
        return units*2000;
    } else if (units <= 400) {
        return 250*2000 + (units-250)*3000;
    } else if (units <= 500) {
        return 250*2000 + 150*3000 + (units-400)*4000;
    } else {
        return 250*2000 + 150*3000 + 100*4000 + (units-500)*5000;
    }
}

void printFamilyBill(Family family) {
    if (strcmp(family.name,"***") == 0||strcmp(family.name,"") == 0) {
        return;
    }
    printf("==============================\n");
    printf("Ten chu ho: %s \n", family.name);
    printf("So dien tieu thu: %0.0f \n", family.elecUnit);
    printf("Tien dien: %0.0f \n", family.charges);
}

int main() {
    Family family[100];
    for (int i = 0; i < 100; i++) {
        char name[128];
        printf("==============================\n");
        printf("Gia dinh so %d: \n", i);
        printf("Ten chu ho[Nhap *** de ket thuc!]: ");
        scanf("%s",family[i].name);
        if (strcmp(family[i].name,"***") == 0) {
            break;
        }
        printf("So dien thang nay: ");
        scanf("%f", &family[i].elecUnit);
        family[i].charges = TienDien(family[i].elecUnit);
    }
    printf("==============================\n");
    for (int i = 0; i < 100; i++) { 
        if (strcmp(family[i].name,"***") == 0) {
            break;
        }
        printFamilyBill(family[i]);
    }
    return 0;
}