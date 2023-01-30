// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[26];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //word = tolower(word);
    //tolower convert a char to a char
    int i = hash(word);
    node *tmp = malloc(sizeof(node));
    tmp = table[i];
    while(tmp->next!=NULL)
    {
        if (strcasecmp(word, tmp->word)==0)
        {
            return true;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    free(tmp);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        return false;
    }
    else
    {
        char tmpword[LENGTH+1];
        // char *tmpword should malloc memory
        while (fscanf(dic, "%s", tmpword) != EOF)
        //note the difference between fscanf and fread
        {
            int i = hash(tmpword);
            node *tmp = malloc(sizeof(node));
            if (tmp==NULL)
            {
                return false;
            }
            strcpy(tmp->word, tmpword);
            //use strcpy instead of = ?
            tmp->next = table[i];
            table[i]=tmp;
        }
            // node *curr = table[i];
            // if (curr == NULL)
            // {
            //     table[i] = malloc(sizeof(node));
            //     curr = table[i];
            //     (curr->word) = temp; // copy char[] or word needs to be char*
            // }
            // else
            // {
            //     while (curr->next != NULL)
            //     {
            //         curr = curr->next;
            //     }
            //     curr->next = malloc(sizeof(node));
            //     curr->next->word = temp;
            // }

            
        fclose(dic);
        return true;
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int count = 0;
    node *tmp = malloc(sizeof(node));
    for (int i = 0; i < N; i++)
    {
        tmp = table[i];
        if (tmp != NULL)
        {
            tmp = tmp->next;
            count++;
        }
    }
    free(tmp);
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }

    if (table[N-1]==NULL)
    {
        return true;
    }
    return false;
}
