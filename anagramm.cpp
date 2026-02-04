/* 
 * File:   anagramm.cpp
 * Authors: Linus Wigger and Othmar Wigger
 * 
 *
 * Created on 14. Oktober 2010, 10:24
 * last changed 2010-11-23
 */

// compile with:
// g++ anagramm.cpp -o anagramm -lncurses

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <string>
#include <ctime>

using namespace std;

/*
 * 
 */

string urstoff, nochda, anagr;
int h_1;
int h_2;
char h_c;

void ausgabe(string str1, string str2) {
    int i;
    clear();
    for (int i=0; i<str1.length(); i++) {
        mvprintw(2,i,"%c",str1[i]);
    }
    for (int i=0; i<str2.length(); i++) {
        mvprintw(4,i,"%c",str2[i]);
    }
    mvprintw(12,1,"C=clear, Q=quit, S=store");
    refresh();
}

void mix() {
    for (int i=0; i<nochda.length(); i++) {
        h_1=rand()%nochda.length();
        h_2=rand()%nochda.length();
        h_c=nochda[h_1];
        nochda[h_1]=nochda[h_2];
        nochda[h_2]=h_c;
    }
}

int main(int argc, char** argv) {
    int i;

    srand(time(0));

    if (argc <= 1 ) {
	cout << "usage: " << argv[0] << " \"String\"" << endl;
	exit(1);
    }
    urstoff = nochda = argv[1];
    initscr();
    bool playing=1;
    ausgabe(nochda, anagr);

    while (playing){
        int c=getch();
        if (c == 'Q') {
            playing=0;
        } else if ((int)c == 0xe0 ) {
            playing=0;
        } else if (c == 'S') {
            ofstream o_file ("anagramm.out", ios::app);
            o_file << urstoff << " " << anagr << endl;
            o_file.close();
        } else if (c == 'C') {
            nochda = urstoff;
            anagr = "";
            ausgabe(nochda, anagr);
        } else if (c == 'C') {
        } else {
            i = nochda.find(c);
            if (i != string::npos) {
                anagr += c;
                nochda.erase (i,1);
            }
            mix();
            ausgabe(nochda, anagr);
        }
    }
    endwin();
    return 0;
}
