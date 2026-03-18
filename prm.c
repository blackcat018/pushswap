#include <string.h>
#include <stdio.h>

void swap(char *a, char *b)
{https://github.com/blackcat018/pushswap/tree/main
    char temp = *a;
    *a = *b;
    *b = temp;
}

void sort(char *str, int start, int end)
{
    for (int i = start; i <= end - 1; i++)
        for (int j = i + 1; j <= end; j++)
            if (str[i] > str[j])
                swap(&str[i], &str[j]);
}

void solve(char *str, int start, int end)
{
    if (start == end)
    {
        puts(str);
        return ;
    }
    sort(str, start, end);
    for (int i = start; i <= end; i++)
    {
        swap(&str[start], &str[i]);
        solve(str, start + 1, end);
        swap(&str[start], &str[i]);
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    solve(av[1], 0, strlen(av[1]) - 1);
    return 0;
}
