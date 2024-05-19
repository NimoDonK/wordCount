#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>  
  
int main(int argc, char *argv[]) {  
    char ch;  
    int in_word = 0;  
    long char_count = 0;  
    long word_count = 0;  
    FILE *file;  
  
    if (argc != 3) {  
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    if (strcmp(argv[1], "-c") == 0) {  
        file = fopen(argv[2], "r");  
        if (!file) {  
            perror("Error opening file");  
            return 1;  
        }  
        while ((ch = fgetc(file)) != EOF) {  
            char_count++;  
        }  
        fclose(file);  
        printf("�ַ�����%ld\n", char_count);  
    } else if (strcmp(argv[1], "-w") == 0) {  
        file = fopen(argv[2], "r");  
        if (!file) {  
            perror("Error opening file");  
            return 1;  
        }  
        while ((ch = fgetc(file)) != EOF) {  
            if (isspace(ch) || ch == ',' || ch == '#') {  
                if (in_word) {  
                    in_word = 0;  
                    word_count++;  
                }  
            } else {  
                in_word = 1;  
            }  
        }  
        // ����ļ��Ե��ʽ�β����û��������һ���ָ�������Ҳ��Ҫ����  
        if (in_word) {  
            word_count++;  
        }  
        fclose(file);  
        printf("��������%ld\n", word_count);  
    } else {  
        printf("Invalid parameter. Use -c or -w.\n");  
        return 1;  
    }  
  
    return 0;  
}
