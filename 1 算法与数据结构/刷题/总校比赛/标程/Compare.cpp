#include <stdio.h>
#include <string.h>

char a[10001], b[10001];

int main() {
    scanf("%s%s", a, b);
    if (strlen(a) == strlen(b)) {
        if (strcmp(a, b) < 0) {
            printf("<\n");
        } else if (strcmp(a, b) > 0) {
            printf(">\n");
        } else {
            printf("=\n");
        }
    } else if (strlen(a) < strlen(b)) {
        printf("<\n");
    } else {
        printf(">\n");
    }
    return 0;
}