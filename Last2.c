#include <stdio.h>
#include <stdlib.h>

int main() {
    int a,b;
    printf("Bai 2:");
    printf("Nhap 2 so nguyen a, b: ");
    scanf("%d %d", &a, &b);
    FILE * filePointer;
    filePointer = fopen("test.txt", "w");
    if(filePointer == NULL)
    {
        printf("Error writing file.\n");
        return 1;
    }
    fprintf(filePointer,"%d %d",a,b);
    fclose(filePointer);

    int fa, fb;
    filePointer = fopen("test.txt", "r");
    fscanf(filePointer,"%d %d", &fa, &fb);
    fclose(filePointer);
    printf("Dap an la: %d", fa+fb);
    return 1;
}