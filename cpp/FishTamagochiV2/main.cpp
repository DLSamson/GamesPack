#if defined(_WIN32)
    #define _WINDOWS
#else
    #define _LINUX
#endif

#include<iostream>
#include<string.h>

#if defined(_WINDOWS)
    #include <Windows.h>
#elif defined(_LINUX)
    #include <unistd.h>
#endif

using namespace std;

//Variables
bool IS_ALIVE = true;
int FOOD = 10;
int HEALTH = 100;
int MONEY = 25;
int DIFFICULTY = 1;
string NAME;

//Printing new data;
void print_data() {
    cout << "Name:\t\t\t" << NAME << endl;
    cout << "Status:\t\t\t" << (IS_ALIVE ? "ALIVE" : "DEAD") << endl;
    cout << endl;
    cout << "Health:\t\t\t" << HEALTH << "<3" << endl;
    cout << "Money:\t\t\t" << MONEY << "$" << endl;
    cout << "Food:\t\t\t" << FOOD << endl;
    cout << "Difficulty level:\t" << DIFFICULTY << endl;
    cout << endl;
}
void print_menu() {
    cout << "Work:\t1" << endl;
    cout << "Feed:\t2" << endl;
    cout << "Shop:\t3" << endl;
    cout << "Exit:\t0" << endl;
    cout << endl;
}

//Util functions
void delay(float seconds) {
    #if defined(_WINDOWS)
        Sleep(seconds * 1000);
    #elif defined(_LINUX)
        usleep(seconds * 1000000); 
    #endif
}
void clear_screen() {
    #if defined(_WINDOWS)
        system("cls");
    #elif defined(_LINUX)
        system("clear");
    #endif
}
float get_rand(int max = 10) {
    return (rand() % max) + 1;
}

//Fish Actions
void feed_fish() {
    if(FOOD > 0) {
        FOOD--;
        if(HEALTH > 100) {
            cout << "Your fish feels bad\n"
            << "Don't over feed it!" << endl;
            delay(1.f);
        }
        HEALTH += 1.5 * get_rand() 
            + DIFFICULTY * 0.2f 
            - (HEALTH > 100 ? 10 * DIFFICULTY : 0);

        cout <<  endl << "Feeding fish..."<< endl;
    }
    else {
        cout << "You don't have enough food!" << endl;
    }
    delay(0.1f);
}
void update_fish() {
    HEALTH -= 0.7 * get_rand() + (DIFFICULTY * 0.2f);
    if(HEALTH < 1) {
        IS_ALIVE = false;
    }
}

//Game actions
void start_work() {
    cout << "You need to solve some math to gain money!" << endl;
    int one = (get_rand(10 * DIFFICULTY)) * DIFFICULTY;
    int two = (get_rand(10 * DIFFICULTY)) * DIFFICULTY;
    float result;
    cout << "Solve this: " << one << " + " << two << endl;
    // cout << " Result: " << (float)one+two << endl;
    cout << "The answer is: ";
    cin >> result;

    if(result == one+two) {
        int money = 10 * DIFFICULTY;
        MONEY += money;
        cout << "You gained: " << money << "$" << endl;
        DIFFICULTY++;
    }
    else {
        cout << "You failed. No money gained" << endl;
        if(DIFFICULTY > 1)
            DIFFICULTY--;
    }
    delay(1.7f);
}
void print_shop() {
    cout << "Small package:\t1\t\t10$" << endl;
    cout << "Medium package:\t2\t\t25$" << endl;
    cout << "Big package:\t3\t\t45$" << endl;
    cout << endl;
    cout << "Exit:\t\t4" << endl;
    cout << endl;
}
void open_shop() {
    int choice;
    bool is_shop = true;
    while (is_shop)
    {
        clear_screen();
        print_data();
        print_shop();
        cout << "Enter a command: ";
        cin >> choice;
        switch (choice) {
        case 1:
            //Small
            if(MONEY > 9) {
                MONEY -= 10;
                FOOD += 5;
            }
            else {
                cout << "You don't have enough money!" << endl;
            }
            delay(1.f);
            break;
        case 2:
            //Medium
            if(MONEY > 24) {
                MONEY -= 25;
                FOOD += 12;
            }
            else {
                cout << "You don't have enough money!" << endl;
            }
            delay(1.f);
            break;
        case 3:
            //Big
            if(MONEY > 44) {
                MONEY -= 45;
                FOOD += 20;
            }
            else {
                cout << "You don't have enough money!" << endl;
            }
            delay(1.f);
            break;
        case 4:
            //Exit
            is_shop = false;
            break;

        default:
            cout << "I dont understand the command!" << endl;
            cout << "Try again" << endl;
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    clear_screen();
    cout << "Enter a name: ";
    cin >> NAME;
    cout << "Here comes your new Pet Fish" << endl;
    cout << "Take care of it" << endl;
    delay(3.f);

    while(IS_ALIVE) {

        clear_screen();
        print_data();
        print_menu();
        cout << "Enter a command: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            clear_screen();
            start_work();
            break;
        case 2:
            feed_fish();
            break;
        case 3:
            clear_screen();
            open_shop();
            break;
        
        
        case 0:
            cout << "Exiting the game..." << endl;
            delay(3.f);
            return 0;
        default:
            cout << "I don't understand..." << endl;
            cout << "Try again!" << endl;
            delay(1.f);
            break;
        }
        update_fish();
    }

    cout << "Your fish died somehow" << endl;
    cout << "You failed." << endl;
    cout << endl;
    cout << "Game over" << endl;
    delay(3.f);
    return 0;
}