#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define SPADE   "\xE2\x99\xA0"  // define four different suits
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"


void SendCard(int cards[][11], int order)
{   
    srand((unsigned)time(NULL));
    int x = rand()%100000;
    srand((unsigned)x);
    for (int i=0; i < 4; i++)
    {
        cards[i][order] =rand()%36;
    }
}

void PrintCard(int cards[][11], int order, string suits[])
{
    int index = 0;
    cout << "YOUR CARD: ";
    for (index = 0; index < order+1; index++)
    {
        cout << cards[0][index] % 9 + 1 << suits[cards[0][index] / 9] << " ";
    }
    cout << endl;
}

bool IfEndGame(int cards[][11], int order, bool ifend)
{
    int total = 0;
    int elimination = 0;
    for (int j = 0; j < 4; j++)
    {
        total = 0;
        for (int p = 0; p <= order; p++)
        {
            total += cards[j][p] % 9 + 1;
           
        }
        if (total > 21 && j == 0)
        {
            ifend = 0;
            return ifend;
        }
        if (total > 21 && j != 0)
        {
            cards[j][10] = 100;
        }
    }
    for (int u = 0; u < 4; u++)
    {
        if (cards[u][10] == 100)
        {
            elimination += 1;
        }
    }
    if (elimination >= 3)
    {
        ifend = 0;
        return ifend;
    }
    else
    {
        ifend = 1;
        return ifend;
    }
    
}

void ShowEndCard(int cards[][11], int order, string suits[], int rank[])
{
    int total = 0;
    for (int i = 0; i < 4; i++)
    {
        total = 0;
        if (i == 0)
        {
            cout << "YOUR FINAL CARD: ";
        }
        else
        {
            cout << "FINAL CARD OF PLAYER" << i+1 << ": ";
        }
        for (int index = 0; index < order; index++)
        {
            total += (cards[i][index] % 9) + 1;
            cout << cards[i][index] % 9 + 1 << suits[cards[i][index] / 9] << " ";
        }
        rank[i] = total;
        cout << "    " << "TOTAL POINTS = " << total << endl;
    }
}

void RankCard(int points[])
{
    int NO = 1;
    for (int k = 1; k < 4; k++)
    {
        if ((points[0] < points[k] && points[k] < 22) || (points[0] > points[k] && points[0] > 21))
        {
            NO += 1;
        }
    }
    cout << endl <<  "You ranked No." << NO << " !!!";
}

int main()
{
    cout << "Welcome to BlackJack2.0" << endl;
    string suits[4] = {SPADE, CLUB, HEART, DIAMOND};
    int round = 0;
    int number = 4;
    int Y_N = 1;
    int cards[4][11];
    int finalcount[4];
    char key;
    while (Y_N && round < 10)
    {
        cout << "ROUND " << round+1 << ":   " << "-------------------------------+----------------------------" << endl;
        SendCard(cards, round);
        PrintCard(cards, round, suits);
        Y_N = IfEndGame(cards, round, Y_N);
        round += 1;

        cout << "Continue Or Not (Y or N) : ";
        cin >> key;
        if (key == 'Y')
        {
            continue;
        }
        else
        {
            cout << "The Game Is Paused By Player...";
            break;
        }
    }
    cout << endl << "-------------------------+++++GAME OVER+++++---------------------------" << endl << endl;
    ShowEndCard(cards, round, suits, finalcount);
    RankCard(finalcount);
    return 0;
}