#include <iostream>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <string>

using namespace std;

void badInput () {
    printf("Your really think ur funny huh? that input is invalid!\n");
}

void introduction() {
    cout<<"Welcome to the Bank Heist Escape Room. You will be given a set of challenges and clues to be able to successfully infiltrate, loot, and escape a high security bank. Make sure to pay attention to different things like capital letters and use of numbers. These will be your only clues. Good luck!" << endl << "Note: if you give an invalid input, it will mark it as wrong";
    cout << "Press Enter to Continue";
    cin.ignore();
}

bool distract() {
    int choice;
    printf("There are guards at the entrance, luckily you came prepared, You have a few choices:\n\t1. THROW A BANANA PE3L ON THE GROUND AND RUN PAST, HOPE THEY TRIP\n\t2. BOOGIE BOMB THEM AND T4KE KEYCARD\n\t3. PEW PEW THEM AND TAKE THE1R KEY CARDS\n\t4. COVER YOUR EYES AND WALK PA5T (IF YOU CAN'T SEE THEM, THEY CAN'T SEE YOU)\n");
    cin >> choice;
    if (choice == 1){
        printf("They unfortunatley do NOT trip, and you are caught :(\n");
        return false;
    }
    if (choice == 2) {
        printf("Great choice, they are now dancing uncontrollably and can't stop you from sneaking through\n");
        return true;
    }
    if (choice == 3) {
        printf("It didn't work, one of them had a faster pew pew then you :(\n");
        return false;
    }
    if (choice == 4) {
        printf("Unfortunateley, they were still able to see you and they realized what you were trying to do :(\n");
        return false;
    }
    else {
        badInput();
        return false;
    }
}

bool enterVault() {
    int code;
    printf("You walk up to the vault and swipe the card, however there is a 4-digit code that you have to insert:\n");
    cin >> code;
    if (code == 3415) {
        printf("Wow good job! You now enter the vault.\n");
        return true;
    }
    if (!code) {
        badInput();
        return false;
    }
    else {
        printf("WRONG ALARM SOUNDING!!!\n");
        return false;
    }
}

// bool disableAlarm() {
    
// }

// int lootVault() {
    
// }

// bool escapeVault() {
    
// }

// bool climbVault() {
    
// }

// bool glide() {
    
// }
int main() {
    enterVault();
    return 0;
}