#include <iostream>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <string>
#include <cstdio>

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
        printf("there are dIAMonds, Money, platinUm, treaSures, and dICed cheese");
        return true;
    }
    if (!code) {
        badInput();
        return false;
    }
    else {
        printf("WRONG!!!\n ALARM SOUNDING!!!\n");
        return false;
    }
}

bool disableAlarm() {
    time_t start = time(nullptr);                     // gets the current time using the things we learned earlier
    string guess;
    while (true){
        
        if (cin.peek() != EOF) {                          // Checks if the user inputed anything
            getline(cin, guess);
            break;
        }

        time_t current = time(nullptr);
        printf("%ld\n", current - start);
        if (current - start >= 3) {
            printf("You ran out of time and got caught, you will now be going to jail for the rest of your life (he won't drop by then)");
            return false;
        }
    }
    if (guess == "IAMMUSIC")
        return true;
    return false;
}

// int lootVault() {
//    srand(time(0));
//    cout << rand() % 1 << endl;
// }

// bool escapeVault() {
    
// }

// bool climbVault() {
//     int code2;
//     cout << "\033[2J\033[1;1H";
//     printf("You start climbing the wall to escape the bank, but you start to slip. There is a box of food near you, but you must enter the 4 digit code from earlier to regain strength and climb to the roof\nEnter Code: ");
//     getline(cin, code2);        //User input to see if they remember the code from earlier

//     if(code2 == 3415){          //If the user inputted code is equal to 3415, this will run
//         printf("Correct! You have regained strength by eating the food from the secret food box. You are now able to climb to the roof of the bank to make your escape!\n");
//         return true;
//     }
//     else{
//         printf("WRONG!!!\n ALARM SOUNDING!!!\n");
//         return false;
//     }
// }

// bool glide() {
//     string riddle;
//     printf("You find Peely on the roof. He says if u can answer his riddle he will give you glider redeploy to glide down to escape the bank successfully.\n'What fortnite emote uses Dababy's song BOP?': ");
//     cin.ignore();
//     getline(cin, riddle);                   //allows for spaces in user input

//     if(riddle == "Jabba Switchaway"){        //if user unput is equal to this this will run
//         printf("Correct! You have successfully escaped the bank!");
//         return 0;
//     }
//     else{                                   //if not this will run
//         printf("WRONG!!!\n ALARM SOUNDING!!! YOU HAVE BEEN CAUGHT AND SENT TO JAIL\n");
//         return 0;
//     }

// }


int main() {

    bool test = disableAlarm();
    printf("%d\n", test);

    return 0;
}
