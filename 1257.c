#include <stdio.h>
#include <string.h>

int main() {
    int lines;
    scanf("%d", &lines);

    while (lines > 0) {
        int numLines;
        scanf("%d", &numLines);

        int totalHash = 0;
        int i = 0;
        while (i < numLines) {
            char line[100];
            scanf("%s", line);

            int lineHash = 0;
            int j = 0;
            while (j < strlen(line)) {
                int charValue = line[j] - 'A' + i + j;
                lineHash += charValue;
                j++;
            }

            totalHash += lineHash;
            i++;
        }

        printf("%d\n", totalHash);
        lines--;
    }

    return 0;
}
