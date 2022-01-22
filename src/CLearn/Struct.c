#include <stdio.h>

struct B; //对结构体B进行不完整声明

//结构体A中包含指向结构体B的指针
struct A
{
    struct B *partner;
    //other members;
};

//结构体B中包含指向结构体A的指针，在A声明完后，B也随之进行声明
struct B
{
    struct A *partner;
    //other members;
};

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} book = {"C 语言", "NOWCODER", "编程语言", 123456};

struct bs{
    unsigned a:4;
    unsigned  :4;    /* 空域 不能使用*/
    unsigned b:4;    /* 从下一单元开始存放 */
    unsigned c:4
};

struct bs
{
    unsigned a : 1;
    unsigned b : 3;
    unsigned c : 4;
} bit, *pbit;

int end;
int main()
{
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n",
           book.title, book.author, book.subject, book.book_id);

    bit.a = 1;                                       /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.b = 7;                                       /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.c = 15;                                      /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    printf("%d,%d,%d\n", bit.a, bit.b, bit.c);       /* 以整型量格式输出三个域的内容 */
    pbit = &bit;                                     /* 把位域变量 bit 的地址送给指针变量 pbit */
    pbit->a = 0;                                     /* 用指针方式给位域 a 重新赋值，赋为 0 */
    pbit->b &= 3;                                    /* 使用了复合的位运算符 "&="，相当于：pbit->b=pbit->b&3，位域 b 中原有值为 7，与 3 作按位与运算的结果为 3（111&011=011，十进制值为 3） */
    pbit->c |= 1;                                    /* 使用了复合位运算符"|="，相当于：pbit->c=pbit->c|1，其结果为 15 */
    printf("%d,%d,%d\n", pbit->a, pbit->b, pbit->c); /* 用指针方式输出了这三个域的值 */

    scanf("%d", &end);
    return 0;
}