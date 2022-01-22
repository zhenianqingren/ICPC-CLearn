#include <stdio.h>
#include <string.h>
// typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
// typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的
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

    strcpy(book.title, "C 教程");
    strcpy(book.author, "Nowcoder");
    strcpy(book.subject, "编程语言");
    book.book_id = 12345;

    printf("书标题 : %s\n", book.title);
    printf("书作者 : %s\n", book.author);
    printf("书类目 : %s\n", book.subject);
    printf("书 ID : %d\n", book.book_id);

    printf("TRUE 的值: %d\n", TRUE);
    printf("FALSE 的值: %d\n", FALSE);

    scanf("%d",&end);
    return 0;
}