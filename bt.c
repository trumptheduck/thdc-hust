#include <stdio.h>

void fun(int n) {
    if (n > 0) {
        fun(--n);
        printf("%d",n);
        fun(--n);
    }
}
int main() {
    fun(3);
    return 0;
}