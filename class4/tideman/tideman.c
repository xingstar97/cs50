#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool cycle(int start, int end);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i<candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[i]=rank;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j<candidate_count; j++)
        if (ranks[i]<ranks[j])
        {
            preferences[i][j]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i<candidate_count; i++)
    {
        for (int j = 0; j<candidate_count; j++)
        {
            if(i == j) continue;
            else{
            if (preferences[i][j]>preferences[j][i])
            {
                pairs[pair_count].winner=i;
                pairs[pair_count].loser=j;
                pair_count++;
            }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i<pair_count; i++)
    {
        int a = pairs[i].winner;
        int b = pairs[i].loser;
        int c = pairs[i+1].winner;
        int d = pairs[i+1].loser;
        if (preferences[a][b]<preferences[c][d])
        {
            pairs[i].winner = pairs[i+1].winner;
            pairs[i].loser = pairs[i+1].loser;
        }
    }
    return;
}


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
   
    for (int i = 0; i<pair_count;i++)
    {
        if(cycle(pairs[i].winner, pairs[i].loser) != 0)
        {
            locked[pairs[i].winner][pairs[i].loser]=true;
        }
    }

    return;
}

    bool cycle(int start, int end)
    {
        if (start == end)
        return true;

        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[end][i]!=0)
            {
                if (cycle(i, start)==0)
                return true;
            }
        }

    }

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i<candidate_count; i++)
    {
        int count = 0;
        for (int j = 0; j <candidate_count; j++)
        {
            if (locked[j][i]==0)
            {
                count++;

            }
            
        }
        if (count == candidate_count)
            // no locked pairs with all other candidates instead of one
            {
                printf("%s\n", candidates[i]);
            }    
    }
    return;
}