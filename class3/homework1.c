#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main (int argc, string argv[])
{
    int length = strlen(argv[1]);

    if (argc!=2)
    {
        printf("Missing substitution key\n");
        return 1;
    }
    else if (length !=26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    else
    {
    string key = argv[1];
    string plain = get_string("Plaintext: ");
    int n = strlen(plain);

    for (int i = 0; i<n; i++)
    {
        
        if (islower(plain[i]))
        {
           //plain[i] = toupper(plain[i]); 
           plain[i] = key[plain[i]-'a'];
           plain[i] = tolower(plain[i]);
        }
        else if (isupper(plain[i]))
        {
            //plain[i]=plain[i];
            plain[i] = key[plain[i]-'A'];
            plain[i] = toupper(plain[i]);
        }
        else
        {
            plain[i]=plain[i];
        }
    }

    printf("ciphertext: %s\n", plain);
    return 0;
    }
}