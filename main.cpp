#include "stringDoublePointEx.h"
int splitString(char *source, const char c, char (*retBuf)[20], int *retLength)
{
    int ret;
    if(source == NULL || retLength == NULL) {
        ret = -1;
        return ret;
    }
    char *p = source;
    char *temp = p;
    int count = 0;
    printf("%d\n", &retBuf);
    printf("%d\n", &retBuf+1);
    while (*p != '\0')
    {
        p = strchr(p, c);
        if(p != NULL)
        {
            int len = p - temp;
            memcpy(retBuf[count], temp, len);
            retBuf[count][len] = '\0';
            p = p + 1;
            temp = p;
            count++;
        } else
        {
            break;
        }
    }
    ret = 0;
    *retLength = count;
}

int splitString2(char *source, const char c, char **retBuf, int *retLength) {
    int ret;
    if (source == NULL || retBuf == NULL || retLength == NULL) {
        ret = -1;
        return ret;
    }

    char *p = source;
    char *temp = p;
    int count = 0;
    while (*p != '\0') {
        p = strchr(p, c);
        if (p != NULL) {
            int len = p - temp;
            memcpy(retBuf[count], temp, len);
            retBuf[count][len] = '\0';
            p = p + 1;
            temp = p;
            count++;
        } else {
            break;
        }
    }
    ret = 0;
    *retLength = count;
}

int creat_res_FREE(char***ppp,int count,int cnt1)  //三级指针分配作输出
{
    int err = 1;
    int i = 0;
    char**src=*ppp

    if (src == NULL)
    {
        err = 0;
        printf("分配失败\n");
        return err;
    }
    for (i = 0;i<count;i++)
    {
        if(src[i] != NULL) free(src[i]);
    }
    free(src);

    *ppp=NULL;;
    return err;
}

int main()
{
    char *source = "abcs,1234,4567,efgh,abch,";
    char c = ',';
    int retLength = 0;
    char retBuf[20][20];
    memset(retBuf, 0, sizeof(retBuf));

    int rv = splitString(source, c, retBuf, &retLength);
    for(int i=0; i<retLength; i++)
    {
        printf("%s\n", retBuf[i]);
    }

    char **retBuf2 = (char**) malloc(20*sizeof(char*));
    printf("sizeof &retBuf2 %d\n", sizeof(&retBuf2));
    printf("sizeof retBuf2 %d\n", sizeof(retBuf2));
    printf("sizeof *retBuf2 %d\n", sizeof(*retBuf2));

    char *buf2[] = {"abc", "def", "hijh"};
    printf("sizeof &buf2 %d\n", sizeof(&buf2));
    printf("sizeof buf2 %d\n", sizeof(buf2));
    printf("sizeof *buf2 %d\n", sizeof(*buf2));

    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    char cc[10][30];

    for(int i= 0; i<10; i++)
    {
        sprintf(cc[i], "%d%d%d", i, i, i);
    }


    int* p = &a[0][0];

    printf("sizeof(&a):%d \n", sizeof(&a));
    printf("sizeof(a):%d \n", sizeof(a));
    printf("sizeof(*a):%d \n", sizeof(*a));

    printf("sizeof(&cc):%d \n", sizeof(&cc));
    printf("sizeof(cc):%d \n", sizeof(cc));
    printf("sizeof(*cc):%d \n", sizeof(*cc));

    typedef char (*pBuf)[30];
    pBuf my = (pBuf)cc;
    printf("sizeof(&pBuf):%d \n", sizeof(&my));
    printf("sizeof(pBuf):%d \n", sizeof(my));
    printf("sizeof(*pBuf):%d \n", sizeof(*my));

    printf("%s\n", *(my+1));

    if(retBuf2 == NULL)
    {
        return -1;
    }

    for(int i=0; i<20; i++)
    {
        retBuf2[i] = (char*) malloc(20);
    }

    rv = splitString2(source, c, retBuf2, &retLength);
    for(int i=0; i<retLength; i++)
    {
        printf("%s\n", retBuf[i]);
    }

    for(int i=0; i<20; i++)
    {
        if(retBuf2[i] != NULL)
            free(retBuf2[i]);
    }

    if(retBuf2 != NULL)
        free(retBuf2);

    return 0;
}
/*
void printArray(int *a, int size)
{
    int i = 0;

    printf("printArray: %d\n", sizeof(a));

    for(i=0; i<size; i++)
    {
        printf("%d\n", a[i]);
    }
}
int main()
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    char cc[10][30];


    int* p = &a[0][0];

    printf("sizeof(&a):%d \n", sizeof(&a));
    printf("sizeof(a):%d \n", sizeof(a));
    printf("sizeof(*a):%d \n", sizeof(*a));

    printf("sizeof(&cc):%d \n", sizeof(&cc));
    printf("sizeof(cc):%d \n", sizeof(cc));
    printf("sizeof(*cc):%d \n", sizeof(*cc));

    printArray(p, 6);

    getchar();

    return 0;
}

*/