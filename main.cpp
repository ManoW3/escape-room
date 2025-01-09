#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include <ctype.h>
#include <string>
#include <cstdio>

using namespace std;
using namespace std::chrono;                                // to measure time for the escaping the vault

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
        // code looks messy cuz of the color codes
        printf("There is: \033[38;2;255;102;0mM\033[37money, platin\033[38;2;255;255;0mU\033[37mm, d\033[34mIC\033[37med cheese, d\033[31mIAM\033[37monds, and trea\033[32mS\033[37mures across the rainbow\n");
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
    string password;
    printf("The alarm is about to go off!!! What is the password? (Case Sensitive, all one word)\n");
    getline(cin, password);
    return password == "IAMMUSIC";
}

// int lootVault() {
//     srand(time(0));
//     int vaultAmt = 10000000 + (rand() % 50000000);
//     amtTaken;
//     cout >> "You have successfully entered the bank. The current balance is: " >> vaultAmt >> endl;
//     printf("How much money do you want to take out?(Enter a negative number): ");
//     cin << amtTaken;
//     
//     if(amtTaken >= (vaultAmt/2)){
//         printf("You are very greedy, and it took you too long to retreive all the money. You have been caught and sentenced to life in jail");
//         return 0;
//     }
//     else{
//         cout >> "You have succesfully retrieved $" >> abs(amtTaken) >> " from the vault.";
//     }
//  }

bool escapeVault() {
    printf("Great! now you have to espace the vault, however you have to time your footsteps!\nPress space every 0.5(±0.05) seconds 10 times in a row to continue to the next step of the operation (at least 7/10 times).\nPress enter to start");
    cin.get();
    printf("3!\n");                                                     // countdown (didn't feel like making a loop)
    this_thread::sleep_for(chrono::seconds(1));
    printf("2!\n");
    this_thread::sleep_for(chrono::seconds(1));
    printf("1!\n");
    this_thread::sleep_for(chrono::seconds(1));
    printf("GO!!!!");
    int score = 0;
    for (int i = 0; i < 10; i++) {
        
        auto start = chrono::high_resolution_clock::now();              // I found all the time stuff online because ctime was being really weird
        cin.get();
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;
        double duration_ms = duration.count();                          // Converts the duration to a double in milliseconds

        if (duration_ms > 450 && duration_ms < 550) {                   // If they get within the time, a point will be added
            printf("Good Timing!");
            score++;
        }
        else 
            printf("FAIL!!!");
    }
    printf("\nYou had %d well timed steps", score);
    if (score >= 8) {
        printf(" and managed to avoid tripping the alarms!");
        return true;
    }
    else {
        printf(" which was not enough, and now you are caught because you are uncoordinated");
        return false;
    }
}

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
//         return 0;
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

    bool test = escapeVault();
    cout << test << endl;

    return 0;
}
