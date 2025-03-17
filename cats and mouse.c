#include <stdio.h>
#include <stdlib.h>

void catAndMouse(int x, int y, int z) {
    int distA = abs(x - z);
    int distB = abs(y - z);

    if (distA < distB) {
        printf("Cat A\n");
    } else if (distB < distA) {
        printf("Cat B\n");
    } else {
        printf("Mouse C\n");
    }
}

int main() {
    int q, x, y, z;
    scanf("%d", &q);  

    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &x, &y, &z);  
        catAndMouse(x, y, z);
    }

    return 0;
}
