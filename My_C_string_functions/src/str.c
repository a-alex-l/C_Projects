#include "str.h"
#include <stddef.h>

char * my_strcpy(char * s1, const char * s2) {
    char *ans = s1;
    for (; *s2 != 0; s1++, s2++) {
        *s1 = *s2;
	}
    *(s1) = 0;
    return ans;
}


int my_strcmp(const char *s1, const char *s2) {
    for (; *s1 != 0 && *s2 != 0; s1++, s2++) {
        if (*s1 != *s2) {
            return ((int)(*s1 - *s2));
		}
	}
	if (s1 == 0 && s2 == 0) {
    	return 0;
	} else {
		return (int)(*s1 - *s2);
	}
}

size_t my_strlen(const char *s) {
    const char *start = s;
    for (; *(s) != 0;) { 
		s++;
	}
    return (size_t)(s - start);
}

char * my_strcat(char * s1, const char * s2) {
    char *ans = s1;
    my_strcpy(s1 + my_strlen(s1), s2);
    return ans;
}
