#include <assert.h>
#include "test_str.h"
#include "str.h"

void test_strcpy() {
    char s1[100] = "12345678", s2[100] = "4321", sans[100] = "4321";
    assert(my_strcmp(my_strcpy(s1, s2), sans) == 0);
    my_strcpy(s1, "12345678"), my_strcpy(s2, ""), my_strcpy(sans, "");
    assert(my_strcmp(my_strcpy(s1, s2), sans) == 0);
    my_strcpy(s1, "12345678"), my_strcpy(s2, "a"), my_strcpy(sans, "a");
    assert(my_strcmp(my_strcpy(s1, s2), sans) == 0);
    my_strcpy(s1, "12345678"), my_strcpy(s2, "aeae"), my_strcpy(sans, "aeae");
    assert(my_strcmp(my_strcpy(s1, s2), sans) == 0);
    return;
}

void test_strcat() {
    char s1[100] = "f", s2[100] = "4321", sans[100] = "f4321";
    assert(my_strcmp(my_strcat(s1, s2), sans) == 0);
    my_strcpy(s1, "89"), my_strcpy(s2, "4321"), my_strcpy(sans, "894321");
    assert(my_strcmp(my_strcat(s1, s2), sans) == 0);
    my_strcpy(s1, "123"), my_strcpy(s2, "4321"), my_strcpy(sans, "1234321");
    assert(my_strcmp(my_strcat(s1, s2), sans) == 0);
    return;
}

void test_strcmp() {
    char s1[100] = "1234", s2[100] = "1235";
    assert(my_strcmp(s1, s2) < 0);
    my_strcpy(s1, "1234"), my_strcpy(s2, "1233");
    assert(my_strcmp(s1, s2) > 0);
    my_strcpy(s1, "1234"), my_strcpy(s2, "1234");
    assert(my_strcmp(s1, s2) == 0);
    my_strcpy(s1, ""), my_strcpy(s2, "");
    assert(my_strcmp(s1, s2) == 0);
    return;
}

void test_strlen() {
    char s[100] = "lolkek";
    assert(my_strlen(s) == 6);
    my_strcpy(s, "");
    assert(my_strlen(s) == 0);
    my_strcpy(s, "kaktak?tochnonerabotaet?");
    assert(my_strlen(s) == 24);
    my_strcpy(s, "a");
    assert(my_strlen(s) == 1);
    return;
}
