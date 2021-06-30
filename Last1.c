#include <stdio.h>
#include <stdlib.h>

void printArray(double array[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        printf("%lf\n", array[i]);
    }
    return;
}   

int main() {
    printf("Bai 1:");
    int arrayLength = 100;
    double array[arrayLength];
    double input;
    int index = 0;
    for (int i = 0; i < arrayLength; i++) {
        printf("Nhap so thuc %d: ", i);
        scanf("%lf", &input);
        if (input >= 0) {
            array[index] = input;
            index++;
        };
    }
    FILE * filePointer;
    filePointer = fopen("So_Duong.dat", "wb");
    if(filePointer == NULL)
    {
        printf("Error writing file.\n");
        return 1;
    }
    fwrite(array,sizeof(double),sizeof(double)*index,filePointer);
    fclose(filePointer);

    double data;
    filePointer = fopen("So_Duong.dat", "rb");
    double output[index];
    for (int i = 0; i < index; i++) {
        fread(&data,sizeof(double),1,filePointer);
        output[i] = data;
    };
    fclose(filePointer);
    printArray(output,index);
    return 1;
}