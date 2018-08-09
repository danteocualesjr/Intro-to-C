#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/

// Always specify the return type. Also, indicate whether a function, argument, or variable will return, accept, or hold an int, char, or etc.
void swap(int* a, int* b)
{
    int temp_val = *a;

    *a = *b;
    *b = temp_val;
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
    
    Do not just use the `strlen` function from the standard library.
*/

// "\0" stands for "null character" or "null terminator"
// "*s" means "pointer s"
// In C, a string is simply an array of characters
int string_length(char *s)
{
    int n = 0;

    while (*s != '\0')
    {
        s++;
        n++;
    }

    return n;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
char *x;
char *y = 'Goodbye';

void string_copy(char *x, char *y)
{
    while (*y != '\0')
    {
        *x = *y;
        y++;
        x++;
    }
    *x = '\0';
}

/* 
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.
    
    For example, given matching strings, this function should 
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a positive value. Given strings
    m = "aardvark" and n = "zebra", should return a negative
    value.
    
    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
    if (*m > *n)
    {
        return 1;
    }
    else if (*m < *n) 
    {
        return -1;
    }
    else if (*m == '\0' && *n == '\0')
    {
        return 0;
    }
    return string_compare(++m, ++n);
}

// Alternative solution
// int string_compare(char *m, char *n)
// {
//     for (; *m == *n; m++, n++)
//     {
//         if (*m == '\0')
//         {
//             return 0;
//         }
//     }
//     return *m - *n;
// }

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char *hello = "Hello";
    char *world = "World";

    char buffer[1024];
    string_copy(buffer, hello);

    printf("Buffer is %s\n", buffer);
    printf("Length is %d\n", string_length(buffer));
    printf("Comparison is %d\n", string_compare(hello, world));

    return 0;
}
#endif
