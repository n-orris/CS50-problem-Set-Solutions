#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //loops throught the candidates to check the name voted for is valid
    // if it finds a match then it adds a vote, if no match at end of loop it returns false
    for (int x = 0; x < candidate_count; x++) {
        if (strcmp(name, candidates[x].name) == 0)
        
        {
            candidates[x].votes += 1;
            return true;
        }
    }
    return false;
    
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int leader = 0;
    // loops through the candidate scores. if current candidate has more votes than previous loop then it replaces the leader 
    for (int j = 0; j < candidate_count; j++)
    {
       if (candidates[j].votes > candidates[j - 1].votes)
       {
           leader = candidates[j].votes;
       }
       
    }
    // prints out all candidate names that have the highest # of votes
    string winner[candidate_count];
    for (int y = 0; y < candidate_count; y++)
    {
        
       if (candidates[y].votes == leader)
       {
           printf("%s\n", candidates[y].name);
       }
       
    }
    
    
    return;
}

