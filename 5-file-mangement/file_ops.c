#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
    printf("Created file: %s\n", filename);
}

void delete_file(const char *filename) {
    if (unlink(filename) == 0) {
        printf("Deleted file: %s\n", filename);
    } else {
        perror("Error deleting file");
    }
}

void copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "r");
    FILE *destination = fopen(dest, "w");
    
    if (source == NULL || destination == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }
    
    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
    
    fclose(source);
    fclose(destination);
    printf("Copied %s to %s\n", src, dest);
}

void move_file(const char *src, const char *dest) {
    if (rename(src, dest) == 0) {
        printf("Moved %s to %s\n", src, dest);
    } else {
        perror("Error moving file");
    }
}

int main() {
    // Create files
    create_file("test1.txt");
    create_file("test2.txt");
    
    // Copy file
    copy_file("test1.txt", "test1_copy.txt");
    
    // Move file
    move_file("test2.txt", "test2_moved.txt");
    
    // Delete files
    delete_file("test1.txt");
    delete_file("test1_copy.txt");
    delete_file("test2_moved.txt");
    
    return 0;
}
