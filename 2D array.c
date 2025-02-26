#include <assert.h>  
#include <ctype.h>  
#include <limits.h>  
#include <math.h>  
#include <stdbool.h>  
#include <stddef.h>  
#include <stdint.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

char* readline();  
char* ltrim(char*);  
char* rtrim(char*);  
char** split_string(char*);  
int parse_int(char*);  

int hourglassSum(int arr_rows, int arr_columns, int** arr) {  
    int maxSum = INT_MIN;  
    
    for (int i = 0; i < 4; i++) {  
        for (int j = 0; j < 4; j++) {  
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] +  
                      arr[i+1][j+1] +  
                      arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];  
            maxSum = (sum > maxSum) ? sum : maxSum;  
        }  
    }  
    
    return maxSum;  
}  

int main()  
{  
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");  
    if (fptr == NULL) {  
        perror("Unable to open output file");  
        return EXIT_FAILURE;  
    }  

    int** arr = malloc(6 * sizeof(int*));  
    if (arr == NULL) {  
        perror("Unable to allocate memory for rows");  
        return EXIT_FAILURE;  
    }  

    for (int i = 0; i < 6; i++) {  
        arr[i] = malloc(6 * sizeof(int));  
        if (arr[i] == NULL) {  
            perror("Unable to allocate memory for columns");  
            return EXIT_FAILURE;  
        }  

        char** arr_item_temp = split_string(rtrim(readline()));  
        for (int j = 0; j < 6; j++) {  
            int arr_item = parse_int(arr_item_temp[j]);  
            arr[i][j] = arr_item;  // Fixed assignment here  
        }  
        
        free(arr_item_temp);  // Free the temporary array  
    }  

    int result = hourglassSum(6, 6, arr);  

    fprintf(fptr, "%d\n", result);  
    fclose(fptr);  

    // Free the allocated memory for the 2D array  
    for (int i = 0; i < 6; i++) {  
        free(arr[i]);  
    }  
    free(arr);  

    return 0;  
}  

char* readline() {  
    size_t alloc_length = 1024;  
    size_t data_length = 0;  

    char* data = malloc(alloc_length);  
    if (data == NULL) {  
        return NULL;  // Return NULL on allocation failure  
    }  

    while (true) {  
        char* cursor = data + data_length;  
        char* line = fgets(cursor, alloc_length - data_length, stdin);  
        if (!line) {  
            break;  
        }  
        data_length += strlen(cursor);  
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {  
            break;  
        }  

        alloc_length <<= 1;  // Double the allocation length  
        data = realloc(data, alloc_length);  
        if (!data) {  
            return NULL;  // Return NULL on reallocation failure  
        }  
    }  

    if (data[data_length - 1] == '\n') {  
        data[data_length - 1] = '\0';  
        data = realloc(data, data_length);  
    } else {  
        data = realloc(data, data_length + 1);  
    }  

    if (data) {  
        data[data_length] = '\0';  
    }  
    return data;  
}  

char* ltrim(char* str) {  
    if (!str) {  
        return NULL;  
    }  
    while (*str != '\0' && isspace(*str)) {  
        str++;  
    }  
    return str;  
}  

char* rtrim(char* str) {  
    if (!str) {  
        return NULL;  
    }  
    char* end = str + strlen(str) - 1;  
    while (end >= str && isspace(*end)) {  
        end--;  
    }  
    *(end + 1) = '\0';  
    return str;  
}  

char** split_string(char* str) {  
    char** splits = NULL;  
    char* token = strtok(str, " ");  
    int spaces = 0;  

    while (token) {  
        splits = realloc(splits, sizeof(char*) * (spaces + 1));  
        if (!splits) {  
            return splits;  
        }  
        splits[spaces++] = token;  
        token = strtok(NULL, " ");  
    }  

    return splits;  
}  

int parse_int(char* str) {  
    char* endptr;  
    int value = strtol(str, &endptr, 10);  
    if (endptr == str || *endptr != '\0') {  
        exit(EXIT_FAILURE);  
    }  
    return value;  
}
