#include<iostream>
#include<string.h>
#include<unistd.h>

using namespace std;

//Variables
bool IS_ALIVE = true;
int FOOD = 10;
int HEALTH = 100;
int MONEY = 25;
int DIFFICULTY = 1;
string NAME;
string LAST_MESSAGE = "";

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
    usleep(seconds * 1000000); 
}
void clear_screen() {
    system("clear");
}
float get_rand(int max = 10) {
    return (rand() % max) + 1;
}
void print_message(string message) {
    for(char i : message) {
        delay(0.1f);
        cout.flush();
        cout << i;
    }
}

//Fish Actions
void feed_fish() {
    if(FOOD > 0) {
        FOOD--;
        HEALTH += 1.5 * get_rand() 
            + DIFFICULTY * 0.2f 
            - (HEALTH > 100 ? 10 * DIFFICULTY : 0);
        LAST_MESSAGE += "\nFish feeded!\n";
        if(HEALTH > 100) {
            LAST_MESSAGE = "Your fish feels bad\nDon't over feed it!";
        }
    }
    else {
        LAST_MESSAGE = "You don't have enough food!";
    }
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
        LAST_MESSAGE = "You gained: " +  to_string(money) + "$";
        DIFFICULTY++;
    }
    else {
        LAST_MESSAGE = "You failed. No money gained";
        if(DIFFICULTY > 1)
            DIFFICULTY--;
    }
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
        cout << LAST_MESSAGE << endl;
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
                LAST_MESSAGE = "You don't have enough money!";
            }
            break;
        case 2:
            //Medium
            if(MONEY > 24) {
                MONEY -= 25;
                FOOD += 12;
            }
            else {
                LAST_MESSAGE = "You don't have enough money!";
            }
            break;
        case 3:
            //Big
            if(MONEY > 44) {
                MONEY -= 45;
                FOOD += 20;
            }
            else {
                LAST_MESSAGE = "You don't have enough money!";
            }
            break;
        case 4:
            //Exit
            LAST_MESSAGE = "";
            is_shop = false;
            break;

        default:
            LAST_MESSAGE = "I dont understand the command!\nTry again!";
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    clear_screen();
    print_message("Enter a name: ");
    cin >> NAME;
    print_message("Here comes your new Pet Fish\nTake care of it! ");
    delay(1.f);

    while(IS_ALIVE) {

        clear_screen();
        print_data();
        cout << LAST_MESSAGE << endl;
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
            LAST_MESSAGE = "";
            clear_screen();
            open_shop();
            break;
        
        case 0:
            print_message("Exiting the game...");
            delay(1.f);
            return 0;
        default:
            LAST_MESSAGE = "I don't understand...\nTry again!";
            delay(1.f);
            break;
        }
        update_fish();
    }

    print_message("Your fish died somehow\nYou failed.\n");
    print_message("\n\tGame over\n");
    delay(1.f);
    return 0;
}