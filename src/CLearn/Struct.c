#include <stdio.h>

struct B; //�Խṹ��B���в���������

//�ṹ��A�а���ָ��ṹ��B��ָ��
struct A
{
    struct B *partner;
    //other members;
};

//�ṹ��B�а���ָ��ṹ��A��ָ�룬��A�������BҲ��֮��������
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
} book = {"C ����", "NOWCODER", "�������", 123456};

struct bs{
    unsigned a:4;
    unsigned  :4;    /* ���� ����ʹ��*/
    unsigned b:4;    /* ����һ��Ԫ��ʼ��� */
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

    bit.a = 1;                                       /* ��λ��ֵ��Ӧע�⸳ֵ���ܳ�����λ�������Χ�� */
    bit.b = 7;                                       /* ��λ��ֵ��Ӧע�⸳ֵ���ܳ�����λ�������Χ�� */
    bit.c = 15;                                      /* ��λ��ֵ��Ӧע�⸳ֵ���ܳ�����λ�������Χ�� */
    printf("%d,%d,%d\n", bit.a, bit.b, bit.c);       /* ����������ʽ�������������� */
    pbit = &bit;                                     /* ��λ����� bit �ĵ�ַ�͸�ָ����� pbit */
    pbit->a = 0;                                     /* ��ָ�뷽ʽ��λ�� a ���¸�ֵ����Ϊ 0 */
    pbit->b &= 3;                                    /* ʹ���˸��ϵ�λ����� "&="���൱�ڣ�pbit->b=pbit->b&3��λ�� b ��ԭ��ֵΪ 7���� 3 ����λ������Ľ��Ϊ 3��111&011=011��ʮ����ֵΪ 3�� */
    pbit->c |= 1;                                    /* ʹ���˸���λ�����"|="���൱�ڣ�pbit->c=pbit->c|1������Ϊ 15 */
    printf("%d,%d,%d\n", pbit->a, pbit->b, pbit->c); /* ��ָ�뷽ʽ��������������ֵ */

    scanf("%d", &end);
    return 0;
}