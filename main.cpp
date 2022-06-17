//
// COMP2711,8801 Computer Programming 2
// Flinders University
//

#include <iostream>
#include <string>
#include <unistd.h>

#include "Rolodex.h"

using namespace std;

auto verbose      = false; // Log Rolodex actions
auto printCurrent = false; // Output only the current Rolodex card
auto duplicate    = false; // no duplicated
auto report       = false;

void rolodex()
{
    string word;
    int insertCount = 0;
    int forwardCount = 0;
    int backwardCount = 0;
    int dupCount = 0;
    int removeCount = 0;
    Rolodex rolodex;
    while (cin >> word) {
        bool deletion = false;
        if(word[0] == '-')
        {
            deletion = true;
            word = word.erase(0,1);
            if(word.empty())
            {
                continue;
            }
        }

            if (rolodex.isBeforeFirst() || rolodex.currentValue() <= word) {
                while (!rolodex.isAfterLast() && rolodex.currentValue() < word) {
                    rolodex.rotateForward();
                    if (verbose)
                        cerr << "rotateForward\n";
                    forwardCount += 1;
                }

                if(deletion)
                {
                    if(rolodex.currentValue() == word)
                    {
                        rolodex.removeCurrent(word);
                        if (verbose)
                            cerr << "removeCurrent\n";
                        removeCount += 1;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    if(duplicate)
                    {
                        if(rolodex.currentValue() == word)
                        {
                            dupCount += 1;
                            continue;
                        }
                    }
                    rolodex.insertBeforeCurrent(word);
                    if (verbose)
                        cerr << "insertBeforeCurrent\n";
                    insertCount += 1;
                }

            }
            else if (rolodex.isAfterLast() || rolodex.currentValue() >= word) {
                while (!rolodex.isBeforeFirst() && rolodex.currentValue() > word) {
                    rolodex.rotateBackward();
                    if (verbose)
                        cerr << "rotateBackward\n";
                    backwardCount += 1;
                }



                if(deletion)
                {
                    if(rolodex.currentValue() == word)
                    {
                        rolodex.removeCurrent(word);
                        if (verbose)
                            cerr << "removeCurrent\n";
                        removeCount += 1;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    if(duplicate)
                    {
                        if(rolodex.currentValue() == word)
                        {
                            dupCount += 1;
                            continue;
                        }
                    }
                    rolodex.insertAfterCurrent(word);
                    if (verbose)
                        cerr << "insertAfterCurrent\n";
                    insertCount += 1;
                }

            }
    }

    if(report)
    {
        cout << insertCount << " " << dupCount << " " << removeCount << " " << forwardCount << " " << backwardCount << endl;
    }
    else if (printCurrent) {
        cout << rolodex.currentValue() << '\n';
    }
    else { // Output all Rolodex card values (default)
        while (!rolodex.isBeforeFirst()) {
            rolodex.rotateBackward();
        }
        rolodex.rotateForward(); // Go to the first card
        while (!rolodex.isAfterLast()) {
            cout << rolodex.currentValue() << '\n';
            rolodex.rotateForward();
        }
    }
}


int main(int argc, char** argv)
{
    int c;
    while ((c = getopt(argc, argv, "vcdr")) != EOF) {
        switch (c) {
        case 'v':
            verbose = true;
            break;
        case 'c':
            printCurrent = true;
            break;
            case 'd':
                duplicate = true;
                break;
            case 'r':
                report = true;
                break;
        }
    }
    argc -= optind;
    argv += optind;
    rolodex();
    return 0;
}
