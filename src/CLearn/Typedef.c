#include <stdio.h>
#include <string.h>
// typedef ������Ϊ���Ͷ���������ƣ�#define ��������Ϊ���Ͷ��������Ҳ��Ϊ��ֵ������������������Զ��� 1 Ϊ ONE��
// typedef ���ɱ�����ִ�н��͵ģ�#define �������Ԥ���������д����
#define TRUE 1
#define FALSE 0
#define Integer int
typedef struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} Book;

Integer end;

int main()
{
    Book book;

    strcpy(book.title, "C �̳�");
    strcpy(book.author, "Nowcoder");
    strcpy(book.subject, "�������");
    book.book_id = 12345;

    printf("����� : %s\n", book.title);
    printf("������ : %s\n", book.author);
    printf("����Ŀ : %s\n", book.subject);
    printf("�� ID : %d\n", book.book_id);

    printf("TRUE ��ֵ: %d\n", TRUE);
    printf("FALSE ��ֵ: %d\n", FALSE);

    scanf("%d",&end);
    return 0;
}