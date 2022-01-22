#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// r	以只读方式打开文件，该文件必须存在。
// r+	以读/写方式打开文件，该文件必须存在。
// rb+	以读/写方式打开一个二进制文件，只允许读/写数据。
// rt+	以读/写方式打开一个文本文件，允许读和写。
// w	打开只写文件，若文件存在则文件长度清为零，即该文件内容会消失；若文件不存在则创建该文件。
// w+	打开可读/写文件，若文件存在则文件长度清为零，即该文件内容会消失；若文件不存在则创建该文件。
// a	以附加的方式打开只写文件。若文件不存在，则会创建该文件；如果文件存在，则写入的数据会被加到文件尾后，即文件原先的内容会被保留（EOF 符保留）。
// a+	以附加方式打开可读/写的文件。若文件不存在，则会创建该文件，如果文件存在，则写入的数据会被加到文件尾后，即文件原先的内容会被保留（EOF符不保留）。
// wb	以只写方式打开或新建一个二进制文件，只允许写数据。
// wb+	以读/写方式打开或新建一个二进制文件，允许读和写。
// wt+  以读/写方式打开或新建一个文本文件，允许读和写。
// at+	以读/写方式打开一个文本文件，允许读或在文本末追加数据。
// ab+  以读/写方式打开一个二进制文件，允许读或在文件末追加数据。
int main()
{
    FILE *fp = NULL;
    // fp = fopen("D:/C.txt", "w+");
    // char *content = (char *)malloc(sizeof(char) * 255);
    // while (scanf("%s", content))
    // {
    //     if (!strcmp(content, "EXIT"))
    //         break;
    //     fprintf(fp, content);
    //     fprintf(fp, "\n");
    //     free(content);
    //     content = (char *)malloc(sizeof(char) * 255);
    // }
    // free(content);
    // content = NULL;

    // fprintf(fp, "This is testing for fprintf...\n");
    // fputs("This is testing for fputs...\n", fp);
    // fclose(fp);
    // fp = NULL;

    char buffer[5];
    fp = fopen("D:/C.txt", "r");
    while (fgets(buffer, 5, fp))
        for (int i = 0; i < 5; i++)
            printf("%c", buffer[i]);
    fclose(fp);

    getchar();
    return 0;
}