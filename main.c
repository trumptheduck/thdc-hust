#include <stdio.h>
#include <stdbool.h>

int printArray(int array[], int length) {
    for(int i = 0; i < length; i++) {
      printf("%d ", array[i]);
      if (i == length-1) {printf("%s","\n");};
    }
    return 0;
}
void cloneArray(int self[], int target[],int length) {
    for (int i = 0; i<length; i++) {
        self[i]=target[i];
    }
}
void normalBubbleSort(int rawArray[],int length) {
    int i, j, temp;
    bool isFinished = true;
    int copiedArray[length];
    cloneArray(copiedArray,rawArray,length);
    for (i = 0;i < length-1;i++) {
        isFinished = true;
        for (j = 0; j < length-i-1;j++) {
            if (copiedArray[j] > copiedArray[j+1]){
                temp = copiedArray[j];
                copiedArray[j] = copiedArray[j+1];
                copiedArray[j+1] = temp;
                isFinished = false;
            }
        }
        if (isFinished) {
            break;
        }
    }
    printArray(copiedArray,length);
}
void pointerBubbleSort(int rawArray[],int length) {
    int i, j, temp;
    bool isFinished = true;
    int copiedArray[length];
    cloneArray(copiedArray,rawArray,length);
    int* pointer = copiedArray;
    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (*(pointer + j) < *(pointer + i)) {
                temp = *(pointer + i);
                *(pointer + i) = *(pointer + j);
                *(pointer + j) = temp;
            }
        }
    }
    printArray(copiedArray,length);
}
void normalSort10(int inputArray[]) {
    int array[20];
    int indexGreater=19;
    int indexLesser=0;
    for (int i = 0;i<20;i++) {
        if (inputArray[i] > 10) {
            array[indexGreater] = inputArray[i];
            indexGreater--;
        } else {
            array[indexLesser] = inputArray[i];
            indexLesser++;
        }
    }
    printArray(array,20);
}
void pointerSort10(int inputArray[]) {
    int copiedArray[20];
    int indexGreater=19;
    int indexLesser=0;
    int* pointer = copiedArray;
    int* pointerOrg = inputArray;
    for (int i = 0;i<20;i++) {
        if (*(pointerOrg+i) > 10) {
            *(pointer+indexGreater) = *(pointerOrg+i);
            indexGreater--;
        } else {
            *(pointer+indexLesser) = *(pointerOrg+i);
            indexLesser++;
        }
    }
    printArray(copiedArray,20);
}
void normalFind10(int inputArray[]) {
    bool isTenExisted = false;
    for (int i = 0;i<20;i++) {
        if (inputArray[i] == 10) {
            printf("Vi tri cua 10:i = %d \n",i);
            isTenExisted = true;
        } 
    }
    if (!isTenExisted) {
        printf("Khong co \n");
    }
}
void pointerFind10(int inputArray[]) {
    bool isTenExisted = false;
    int* pointer = inputArray;
    for (int i = 0;i<20;i++) {
        if (*(pointer+i) == 10) {
            printf("Vi tri cua 10:i = %d \n",i);
            isTenExisted = true;
        } 
    }
    if (!isTenExisted) {
        printf("Khong co \n");
    }
}
int main() {
    int inputArray[20];
    printf("%s","Hay nhap cac phan tu cua mang \n");
    for (int i = 0;i<20;i++) {
        printf("Nhap n[%d]",i);
        scanf("%d",&inputArray[i]);
    }
    printf("Mang ban dau:");
    printArray(inputArray,20);
    printf("Cau 1(Normal):");
    normalSort10(inputArray);
    printf("Cau 2(Normal):");
    normalFind10(inputArray);
    printf("Cau 3(Normal):");
    normalBubbleSort(inputArray,20);
    printf("Cau 1(Pointer):");
    pointerSort10(inputArray);
    printf("Cau 2(Pointer):");
    pointerFind10(inputArray);
    printf("Cau 3(Pointer):");
    pointerBubbleSort(inputArray,20);

    return 0;
}