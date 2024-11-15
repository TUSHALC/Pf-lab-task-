#include <stdio.h>
int maxPieces(int n) {
    if (n == 0) {
        return 0;
    }

    if (n < 0) {
        return -1;
    }

    int cut1 = maxPieces(n - 1); 
    int cut2 = maxPieces(n - 2); 
    int cut3 = maxPieces(n - 3);  

    int result = (cut1 > cut2) ? cut1 : cut2;
    result = (result > cut3) ? result : cut3;

    if (result >= 0) {
        return result + 1;  
    
    } else {
        return -1;  
    }
}

int main() {
    int length;

    printf("Enter the length of the rope: ");
    scanf("%d", &length);

    int max = maxPieces(length);

    if (max >= 0) {
        printf("Maximum number of pieces: %d\n", max);
    } else {
        printf("It is not possible to cut the rope into valid pieces.\n");
    }

    return 0;
}
