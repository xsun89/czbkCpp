#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getCount(const char *source, const char *sub, int *count)
{
    int ret = 0;
    char *str = (char*)source;
    if(source == NULL || sub == NULL || count == NULL)
    {
        ret = -1;
        return ret;
    }
    do
    {
        str = strstr(str, sub);
        if(str != NULL)
        {
            (*count)++;
            str = str + strlen(sub);
        }else
        {
            break;
        }
    }while(*str != '\0');
    return ret;
}

int getStr1Str2(char *source, char *buf1, char *buf2)
{
    int ret = 0;
    int count = 0;
    if(source == NULL || buf1 == NULL || buf2 == NULL)
        return ret;
    while(*source != '\0')
    {
        count++;
        if(count%2 == 0)
        {
            *buf1++ = *source++;
        }
        else
        {
            *buf2++ = *source++;
        }
    }
    *buf1 = '\0';
    *buf2 = '\0';
    ret = 1;

    return ret;
}

int getKeyByValude(char *keyvaluebuf,  char *keybuf,  char *valuebuf, int * valuebuflen)
{
    int ret = 0;
    int count = 0;
    char *p = keyvaluebuf;
    if(keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)
        return ret;
    while(*keyvaluebuf != '=')
    {
        *keybuf++ = *keyvaluebuf++;
        p++;
    }
    p++;
    while(*p != '\0')
    {
        count++;
        *valuebuf++ = *p++;
    }
    *keybuf = '\0';
    *valuebuf = '\0';
    *valuebuflen = count;
    ret = 1;

    return ret;
}

int mainTest()
{
    char *source = "abcabcdefg1234567abcd7896dabcdas";
    const char *sub = "abcd";
    int count = 0;
    int ret = getCount(source, sub, &count);
    printf("count=%d \n", count);

    const char *inBuf = "      abcdefg     ";
    char outBuf[30];

    int rv;
    rv = trimSpace(inBuf, outBuf);
    printf("return value=%d, in buf =%s and out buf=%s\n", rv, inBuf, outBuf);

    char buf1[30] = {0};
    char buf2[30] = {0};
    rv = getStr1Str2("a", buf1, buf2);
    printf("return value=%d, buf1 =%s and buf2=%s\n", rv, buf1, buf2);

    char *keyValueBuf = "key1=abcdef";
    char key[30] = {0};
    char value[30] = {0};
    int valLen = 0;

    rv = getKeyByValude(keyValueBuf, key, value, &valLen);
    printf("return value=%d, key =%s and value=%s valueLen=%d\n", rv, key, value, valLen);
    return 0;
}