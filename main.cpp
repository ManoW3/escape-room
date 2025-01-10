/*
 * Mano Wertman & Ayaan Gill
 * Escape Room
 * 1/9/2025
 * Extra: Used colors, many more functions, and the chrono library for more accurate timing. (and printf in things written by mano)
 */
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include <ctype.h>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;
using namespace std::chrono; // to measure time for the escaping the vault

void badInput() {
    // Function to handle invalid input
    printf("Your really think ur funny huh? that input is invalid!\n");
}

void introduction() {
    // Function to introduce the game to the player
    cout << "Welcome to the Bank Heist Escape Room. You will be given a set of challenges and clues to be able to successfully infiltrate, loot, and escape a high security bank. Make sure to pay attention to different things like capital letters and use of numbers. These will be your only clues. Good luck!" << endl;
    cout << "Note: if you give an invalid input, it will mark it as wrong" << endl;
    cout << "Press Enter to Continue";
    cin.ignore();
}

bool distract() {
    // Function to distract guards at the entrance
    char choice;
    printf("There are guards at the entrance, luckily you came prepared. You have a few choices:\n\ta. THROW A BANANA PE3L ON THE GROUND AND RUN PAST, HOPE THEY TRIP\n\tb. BOOGIE BOMB THEM AND T4KE KEYCARD\n\tc. PEW PEW THEM AND TAKE THE1R KEY CARDS\n\td. COVER YOUR EYES AND WALK PA5T (IF YOU CAN'T SEE THEM, THEY CAN'T SEE YOU)\n");
    cin >> choice;
    choice = tolower(choice);
    if (choice == 'a') {
        // Guard distraction fails
        printf("They unfortunately do NOT trip, and you are caught :( \n");
        return false;
    } else if (choice == 'b') {
        // Successfully distracts guards
        printf("Great choice, they are now dancing uncontrollably and can't stop you from sneaking through\n");
        return true;
    } else if (choice == 'c') {
        // Player fails to outshoot guards
        printf("It didn't work, one of them had a faster pew pew than you :( \n");
        return false;
    } else if (choice == 'd') {
        // Player fails to sneak past guards
        printf("Unfortunately, they were still able to see you and realized what you were trying to do :( \n");
        return false;
    } else {
        // Handle invalid input
        badInput();
        return false;
    }
}

bool enterVault() {
    // Function to enter the vault by entering a code
    int code;
    printf("You walk up to the vault and swipe the card, however there is a 4-digit code that you have to insert:\n");
    cin >> code;
    if (code == 3415) {
        // Player enters the correct code
        printf("Wow good job! You now enter the vault.\n");
        printf("There is: \033[38;2;255;102;0mM\033[37money, platin\033[38;2;255;255;0mU\033[37mm, d\033[34mIC\033[37med cheese, d\033[31mIAM\033[37monds, and trea\033[32mS\033[37mures across the rainbow\n");
        return true;
    } else {
        // Incorrect code triggers alarm
        printf("WRONG!!!\n ALARM SOUNDING!!!\n");
        return false;
    }
}

bool disableAlarm() {
    // Function to disable the alarm by entering the correct password
    string password;
    printf("The alarm is about to go off!!! What is the password? (Case Sensitive, all one word)\n");
    cin.ignore(); // Fix leftover newline
    getline(cin, password);
    return password == "IAMMUSIC";
}

bool lootVault() {
    // Function to loot the vault
    srand(time(0));
    int vaultAmt = 10000000 + (rand() % 50000000); // Random vault amount
    int amtTaken = 0;
    cout << "You have successfully entered the bank. The current balance is: " << vaultAmt << endl;
    printf("How much money do you want to take out?(Enter a negative number): ");
    cin >> amtTaken;

    if (abs(amtTaken) >= (vaultAmt / 2)) {
        // Player gets caught for taking too much money
        printf("You are very greedy, and it took you too long to retrieve all the money. You have been caught and sentenced to life in jail\n");
        return false;
    } else {
        // Player successfully retrieves money
        cout << "You have successfully retrieved $" << abs(amtTaken) << " from the vault.\n";
        return true;
    }
}

bool escapeVault() {
    // Function to escape the vault by timing footsteps
    printf("Great! Now you have to escape the vault, however you have to time your footsteps!\nPress enter every 0.5(\u00b10.05) seconds 10 times in a row to continue to the next step of the operation (at least 7/10 times).\nPress enter to start\n");
    cin.ignore();
    cin.ignore();
    printf("3!\n");
    this_thread::sleep_for(chrono::seconds(1));
    printf("2!\n");
    this_thread::sleep_for(chrono::seconds(1));
    printf("1!\n");
    this_thread::sleep_for(chrono::seconds(1));
    printf("GO!!!!\n");
    int score = 0;
    for (int i = 0; i < 10; i++) {
        // Start timing
        auto start = chrono::high_resolution_clock::now();
        cin.ignore();
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;
        double duration_ms = duration.count();

        if (duration_ms > 450 && duration_ms < 550) {
            // Good timing
            printf("Good Timing!\n");
            score++;
        } else
            // Bad timing
            printf("FAIL!!!\n");
    }
    printf("\nYou had %d well-timed steps", score);
    if (score >= 7) {
        // Success
        printf(" and managed to avoid tripping the alarms!\n");
        return true;
    } else {
        // Failure
        printf(" which was not enough, and now you are caught because you are uncoordinated\n");
        return false;
    }
}

bool climbVault() {
    // Function to climb out of the vault by recalling the earlier 
    this_thread::sleep_for(chrono::seconds(3));
    printf("\033[2J\033[1;1H");
    int code2;
    printf("You start climbing the wall to escape the bank, but you start to slip. There is a box of food near you, but you must enter the 4-digit code from earlier to regain strength and climb to the roof\nEnter Code: ");
    cin >> code2;
    if (code2 == 3415) {
        // Correct code
        printf("Correct! You have regained strength by eating the food from the secret food box. You are now able to climb to the roof of the bank to make your escape!\n");
        return true;
    } else {
        // Incorrect code
        printf("WRONG!!!\n ALARM SOUNDING!!!\n");
        return false;
    }
}

bool glide() {
    // Function to answer a riddle to get glider redeploy
    string riddle;
    printf("You find Peely on the roof. He says if you can answer his riddle he will give you glider redeploy to glide down to escape the bank successfully.\n'What Fortnite emote uses Dababy's song BOP?': ");
    cin.ignore();
    getline(cin, riddle);
    if (riddle == "Jabba Switchaway") {
        // Correct answer
        printf("Correct! You have successfully escaped the bank!\n");
        return true;
    } else {
        // Incorrect answer
        printf("WRONG!!!\n ALARM SOUNDING!!! YOU HAVE BEEN CAUGHT AND SENT TO JAIL\n");
        return false;
    }
}

int main() {
    // Main game sequence
    introduction();
    if (!distract()) return 0;
    if (!enterVault()) return 0;
    if (!disableAlarm()) return 0;
    if (!lootVault()) return 0;
    if (!escapeVault()) return 0;
    if (!climbVault()) return 0;
    if (!glide()) return 0;

    // Successful completion message
    printf("Congratulations! You completed all the challenges and escaped successfully.\n");
    return 0;
}
