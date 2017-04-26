# include <limits.h>
# include <string.h>
# include <stdio.h>

# define NO_OF_CHARS 256


int max (int a, int b)
{
 	return (a > b)? a: b;
}


void badChar( char *str, int size, int badchar[NO_OF_CHARS])
{
    int i;

  
    for (i = 0; i < NO_OF_CHARS; i++)
         badchar[i] = -1;


    for (i = 0; i < size; i++){

         badchar[(int) str[i]] = i;
		 
}
}

void search( char *text,  char *pattern)
{
    int m = strlen(pattern);
    int n = strlen(text);

    int badchar[NO_OF_CHARS];
    badChar(pattern, m, badchar);

    int s = 0;  
    while(s <= (n - m))
    {
        int j = m-1;

        while(j >= 0 && pattern[j] == text[s+j])
            j--;

        if (j < 0)
        {
            printf("\n pattern occurs at shift = %d", s);

            s += (s+m < n)? m-badchar[text[s+m]] : 1;

        }

        else
            
            s += max(1, j - badchar[text[s+j]]);
    }
}

int main()
{
    char text[] = "AABCABCACCBAC";
    char pattern[] = "ABC";
    
    search(text, pattern);
    return 0;
}
