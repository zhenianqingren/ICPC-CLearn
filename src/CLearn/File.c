#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// r	��ֻ����ʽ���ļ������ļ�������ڡ�
// r+	�Զ�/д��ʽ���ļ������ļ�������ڡ�
// rb+	�Զ�/д��ʽ��һ���������ļ���ֻ�����/д���ݡ�
// rt+	�Զ�/д��ʽ��һ���ı��ļ����������д��
// w	��ֻд�ļ������ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ��������򴴽����ļ���
// w+	�򿪿ɶ�/д�ļ������ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ��������򴴽����ļ���
// a	�Ը��ӵķ�ʽ��ֻд�ļ������ļ������ڣ���ᴴ�����ļ�������ļ����ڣ���д������ݻᱻ�ӵ��ļ�β�󣬼��ļ�ԭ�ȵ����ݻᱻ������EOF ����������
// a+	�Ը��ӷ�ʽ�򿪿ɶ�/д���ļ������ļ������ڣ���ᴴ�����ļ�������ļ����ڣ���д������ݻᱻ�ӵ��ļ�β�󣬼��ļ�ԭ�ȵ����ݻᱻ������EOF������������
// wb	��ֻд��ʽ�򿪻��½�һ���������ļ���ֻ����д���ݡ�
// wb+	�Զ�/д��ʽ�򿪻��½�һ���������ļ����������д��
// wt+  �Զ�/д��ʽ�򿪻��½�һ���ı��ļ����������д��
// at+	�Զ�/д��ʽ��һ���ı��ļ�������������ı�ĩ׷�����ݡ�
// ab+  �Զ�/д��ʽ��һ���������ļ�������������ļ�ĩ׷�����ݡ�
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