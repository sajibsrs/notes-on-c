#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 256

int main()
{
    const char file_name[] = "quotes.txt";
    FILE *p_file;

    char buffer[BSIZE];
    char **pp_list = NULL;
    int items = 0, quote;

    // Open the file for reading
    p_file = fopen(file_name, "r");

    // Check if the file opened successfully
    if (p_file == NULL) {
        fprintf(stderr, "Unable to open file %s\n", file_name);
        exit(1);
    }

    // Use a dynamic resizing strategy for pp_list
    int capacity = 100;
    pp_list = (char **)malloc(sizeof(char *) * capacity);

    // Check if memory allocation was successful
    if (pp_list == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    while (fgets(buffer, BSIZE, p_file) != NULL) {
        // Remove newline characters from the end of the line
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Allocate memory for the line and copy it
        pp_list[items] = strdup(buffer);
        items++;

        if (items >= capacity) {
            // Double the capacity when needed
            capacity *= 2;
            pp_list = (char **)realloc(pp_list, sizeof(char *) * capacity);

            // Check if memory allocation was successful after resizing
            if (pp_list == NULL) {
                fprintf(stderr, "Unable to allocate memory\n");
                exit(1);
            }
        }
    }

    // Close the file
    fclose(p_file);

    if (items != 0) {
        // Generate a random quote index
        srand((unsigned)time(NULL));
        quote = rand() % items;
        printf("%s\n", pp_list[quote]);
    } else {
        fprintf(stderr, "List is empty\n");
    }

    // Free allocated memory
    for (int i = 0; i < items; i++) {
        free(pp_list[i]);
        pp_list[i] = NULL;
    }
    free(pp_list);
    pp_list = NULL;

    return 0;
}
