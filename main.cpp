#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;





int tranMaxs = 0;
int itemMaxs = 0;



int getSupp(int x, int** items)
{
    int supp = 0;
    for(int y = 0; y <= tranMaxs; y++)
    {
        supp += items[y][x];
    }
    return supp;
}

int** readSupps(int** items)
{
    int supps[80000][2];
    for(int x = 0; x <= itemMaxs; x++)
    {
        int supp = getSupp(x, items);
        supps[x][0] = x;
        supps[x][1] = supp;
    }
    return supps;
}

void printSupp()
{
    for(int x = 0; x <= itemMaxs; x++)
    {
        int supp = getSupp(x);
        cout << x << "-.-" << supp <<  endl;
    }
}

void apriori()
{

}


int main()
{
    static int items[80000][80000];
    std::ifstream file("small");
    std::string str;

    while (std::getline(file, str))
    {
        int tran = stoi( str.substr(0, str.find(" ")) );
        int item = stoi( str.substr(str.find(" "), str.length()) );

        if(tran >= tranMaxs) tranMaxs = tran;
        if(item >= itemMaxs) itemMaxs = item;


        //items[tran][item] = 1;

    }
    int items[tranMaxs+1][itemMaxs+1];

    while (std::getline(file, str))
    {
        int tran = stoi( str.substr(0, str.find(" ")) );
        int item = stoi( str.substr(str.find(" "), str.length()) );



        items[tran][item] = 1;

    }
    //printBoth();
    //printRel(items, lastItem);
    //readSupps();
    return EXIT_SUCCESS;
}
