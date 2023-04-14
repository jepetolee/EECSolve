#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);

const int Count = 7, NumofCard = 52;
using namespace std;

int ComaptibleCheck[Count];
bool CardSelected[NumofCard] = {false};

int CheckTheIterNAdd(int Iter)
{
    for (int PreviousIter = 0; PreviousIter < Iter; PreviousIter++)
    {
        if (ComaptibleCheck[Iter] == ComaptibleCheck[PreviousIter])
        {
            break;
            return Iter--;
        }
    }
    CardSelected[ComaptibleCheck[Iter]] = true;
    return Iter;
}

void PickTheCard()
{
    for (int Iter = 0; Iter < Count; Iter++)
    {
        ComaptibleCheck[Iter] = (rand() % NumofCard);
        Iter = CheckTheIterNAdd(Iter);
    }
}

void PrintTheCard(int Iter)
{
    int Num = int(Iter % 13);
    int Kind = int(Iter / 13);

    if (Num < 9)
    {
        int cardnum = Num + 2;
        printf("%d ", cardnum);
    }
    else if (Num == 9)
        printf("Jack ");
    else if (Num == 10)
        printf("Queen ");
    else if (Num == 11)
        printf("King ");
    else if (Num == 12)
        printf("Ace ");

    if (Kind == 0)
        printf("Spade\n");
    else if (Kind == 1)
        printf("Diamond\n");
    else if (Kind == 2)
        printf("Heart\n");
    else if (Kind == 3)
        printf("Clover\n");
}

void PrintTheResult()
{
    for (int Iter = 0; Iter < NumofCard; Iter++)
    {
        if (CardSelected[Iter] == true)
            PrintTheCard(Iter);
    }
}

int main()
{
    PickTheCard();
    PrintTheResult();
}
