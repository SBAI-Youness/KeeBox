#include <stdio.h>
#include "../include/tinyfiledialogs.h"

int main() {
    const char *filePath = tinyfd_openFileDialog(
        "Select a file",   // title
        "",                // default path
        0,                 // number of filters
        NULL,              // filters
        NULL,              // description of filters
        0                  // allow multiple selections?
    );

    if (filePath) {
        printf("Selected file: %s\n", filePath);
    } else {
        printf("No file selected.\n");
    }

    return 0;
}
