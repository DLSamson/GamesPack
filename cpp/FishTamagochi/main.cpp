#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include<math.h>
#include<time.h>

using namespace std;

//Технические переменные
int loadspeed;
int speedanim;

int one = 0;
int two = 0;
int three = one + two;
int minimum = 0;
int maximum = 50;
int answer = 0;
//int index = 0;
bool death;
//Игровые переменные
int health;
int money;
int food;
int extra;
int move;
char died;
int difficult;
int diflevel;
int amountwork;

void Data() {
#define save ofstream out("data.txt"); out << health << "\n" << food << "\n" << money << "\n" << extra << "\n" << difficult << "\n" << diflevel << "\n" << amountwork << "\n" << death; out.close();
#define load ifstream in("data.txt"); in >> health >> food >> money >> extra >> difficult >> diflevel >> amountwork >> death; in.close();
}
void animations() {
	//Скорость анимации рыбки
	int speedanim = 300
		//*	//Кадр плавания(влево)
#define frame0l cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~_,,,_~ ~\n"; cout << "~ ~ ~ ~ ~<0)(8888><(~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame1l cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ _,,,_ ~ ~\n"; cout << "~ ~ ~ ~ <0)(8888><( ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame2l cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~_,,,_~ ~ ~\n"; cout << "~ ~ ~ ~<0)(8888><(~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame3l cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ _,,,_ ~ ~ ~\n"; cout << "~ ~ ~ <0)(8888><( ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame4l cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~_,,,_~ ~ ~ ~\n"; cout << "~ ~ ~<0)(8888><(~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame5l cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ _,,,_ ~ ~ ~ ~\n"; cout << "~ ~ <0)(8888><( ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame6l cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~_,,,_~ ~ ~ ~ ~\n"; cout << "~ ~<0)(8888><(~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame7l cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ _,,,_ ~ ~ ~ ~ ~\n"; cout << "~ <0)(8888><( ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame8l cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~_,,,_~ ~ ~ ~ ~ ~\n"; cout << "~<0)(8888><(~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
	//Плывет(лево)
#define anim1l frame0l; Sleep(speedanim); system("cls"); frame1l; Sleep(speedanim); system("cls"); frame2l; Sleep(speedanim); system("cls"); frame3l; Sleep(speedanim); system("cls"); frame4l; Sleep(speedanim); system("cls");  frame5l; Sleep(speedanim); system("cls"); frame6l; Sleep(speedanim); system("cls"); frame7l; Sleep(speedanim); system("cls"); frame8l; Sleep(speedanim); system("cls");

//*	//Кадр плавания(право)
#define frame0r cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~_,,,_~ ~ ~ ~ ~ ~ ~\n"; cout << ")><8888)(0> ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame1r cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ _,,,_ ~ ~ ~ ~ ~ ~\n"; cout << "~)><8888)(0>~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame2r cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~_,,,_~ ~ ~ ~ ~ ~\n"; cout << "~ )><8888)(0> ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame3r cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ _,,,_ ~ ~ ~ ~ ~\n"; cout << "~ ~)><8888)(0>~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame4r cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~_,,,_  ~ ~ ~ ~\n"; cout << "~ ~ )><8888)(0> ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame5r cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ _,,,_ ~ ~ ~ ~\n"; cout << "~ ~ ~)><8888)(0>~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame6r cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~_,,,_~ ~ ~ ~\n"; cout << "~ ~ ~ )><8888)(0> ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame7r cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ _,,,_ ~ ~ ~\n"; cout << "~ ~ ~ ~)><8888)(0>~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame8r cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~_,,,_~ ~ ~\n"; cout << "~ ~ ~ ~ )><8888)(0> ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
	//Плывет(право)
#define anim1r frame0r; Sleep(speedanim); system("cls"); frame1r; Sleep(speedanim); system("cls"); frame2r; Sleep(speedanim); system("cls"); frame3r; Sleep(speedanim); system("cls"); frame4r; Sleep(speedanim); system("cls");  frame5r; Sleep(speedanim); system("cls"); frame6r; Sleep(speedanim); system("cls"); frame7r; Sleep(speedanim); system("cls"); frame8r; Sleep(speedanim); system("cls");

//* //Кадры плавания(право)(Экстра)
#define frame0re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~_,,,_~ ~ ~ ~ ~ ~ ~\n"; cout << ")><8888)(0> ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame1re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ _,,,_ ~ ~ ~ ~ ~ ~\n"; cout << "~)><8888)(0>~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame2re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~_,,,_~ ~ ~ ~ ~ ~\n"; cout << "~ )><8888)(0> ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame3re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ _,,,_ ~ ~ ~ ~ ~\n"; cout << "~ ~)><8888)(0>~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame4re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~_,,,_  ~ ~ ~ ~\n"; cout << "~ ~ )><8888)(0> ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame5re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ _,,,_ ~ ~ ~ ~\n"; cout << "~ ~ ~)><8888)(0>~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame6re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~_,,,_~ ~ ~ ~\n"; cout << "~ ~ ~ )><8888)(0> ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame7re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ _,,,_ ~ ~ ~\n"; cout << "~ ~ ~ ~)><8888)(0>~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame8re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~_,,,_~ ~ ~\n"; cout << "~ ~ ~ ~ )><8888)(0> ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame9re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ _,,,_ ~ ~\n"; cout << "~ ~ ~ ~ ~)><8888)(0>~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame10re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ _,,,_ ~ ~\n"; cout << "~ ~ ~ ~ ~ )><8888)(0>\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame11re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~_,,,_~ ~\n"; cout << "~ ~ ~ ~ ~ ~)><8888)(0\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame12re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ _,,,_ ~\n"; cout << "~ ~ ~ ~ ~ ~ )><8888)(\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame13re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~_,,,_~\n"; cout << "~ ~ ~ ~ ~ ~ ~)><8888)\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame14re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ _,,,_\n"; cout << "~ ~ ~ ~ ~ ~ ~()><8888\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame15re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~_,,,\n"; cout << "~ ~ ~ ~ ~ ~ ~(Т)><888\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame16re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ _,,\n"; cout << "~ ~ ~ ~ ~ ~ ~(Ты)><88\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame17re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~_,\n"; cout << "~ ~ ~ ~ ~ ~ ~(Ты )><8\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame18re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ _\n"; cout << "~ ~ ~ ~ ~ ~ ~(Ты л)><\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame19re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~(Ты ло)>\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame20re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~(Ты лох)\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame21re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~(Ты лох)\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame22re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~(Ты лох)\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
#define frame23re cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~(Ты лох)\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n"; cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";

	//Плывет (право)(Экстра)
#define anim1re frame0re; Sleep(speedanim); system("cls"); frame1re; Sleep(speedanim); system("cls"); frame2re; Sleep(speedanim); system("cls"); frame3re; Sleep(speedanim); system("cls"); frame4re; Sleep(speedanim); system("cls");  frame5re; Sleep(speedanim); system("cls"); frame6re; Sleep(speedanim); system("cls"); frame7re; Sleep(speedanim); system("cls"); frame8re; Sleep(speedanim); system("cls"); frame9re; Sleep(speedanim); system("cls"); frame10re; Sleep(speedanim); system("cls"); frame11re; Sleep(speedanim); system("cls"); frame12re; Sleep(speedanim); system("cls"); frame13re; Sleep(speedanim); system("cls"); frame14re; Sleep(speedanim); system("cls"); frame15re; Sleep(speedanim); system("cls"); frame16re; Sleep(speedanim); system("cls"); frame17re; Sleep(speedanim); system("cls"); frame18re; Sleep(speedanim); system("cls"); frame19re; Sleep(speedanim); system("cls"); frame20re; Sleep(speedanim); system("cls"); frame21re; Sleep(speedanim); system("cls"); frame22re; Sleep(speedanim); system("cls"); frame23re; Sleep(speedanim); system("cls");
		;
}
void Health() {
	int health = 100;
	int move = 0;
	char died = 0;
#define die if (health <= 0) {system("cls"); anim1re; Sleep(3000); died = 1;}
#define dying if (move >= 1) {health = health - (10*move+difficult); move = 0;} die; if(died == 1) {cout << "Рыбку не устроило качество жизни.\nРыбка поняла, что тут ей делать нечего.\nРыбка решила свалить зарубеж.\n"; death = true; system("pause"); }

}
void Money() {
	int money = 0;
	int difficult = 0; //0 - easy, 1 - middle, 2 - hard, 3 - ultrahard
	int move = 0;
	int diflevel = 0;
	int amountwork = 4;
	int gain = 0;
	//Проверка очков сложности
#define diflevelcheck if (diflevel <= 0) { difficult = 0; } else if (diflevel > 0 && 5 >= diflevel) { difficult = 1; } else if (diflevel > 5 && 15 >= diflevel) { difficult = 2; } else if (diflevel > 15 && 24 >= diflevel) { difficult = 3; }
	//Рандом чисел и сводка к одному
#define randoming if (difficult == 0) { minimum = 1; maximum = 50; } else if (difficult == 1) { minimum = 50; maximum = 5000; } else if (difficult == 2) { minimum = 5000;  maximum = 50000; } else if (difficult == 3) { minimum = 50000;  maximum = 500000; } else { minimum = 1;  maximum = 50; difficult = 0; } one = minimum + rand() % (maximum - minimum + 1); two = minimum + rand() % (maximum - minimum + 1); three = one + two; answer = 0;
#define randoming_symbols char symbols[] = {'-', '+', '/', '*'}; int index = rand() % 4; char random = symbols[index];
	//Пример и проверка с результатом
#define gaining cout << "???? ????? " << one << " " << random << " " << two << " = ?\n"; cin >> answer; if (three == answer) { gain += 10*difficult+10; cout << "?????????!"<< endl; diflevel++;} else {cout << "?? ?????????!" << endl; move += 1; diflevel -= 3; }

#define gainmoney for (int i = 0; i < amountwork; i++) {randoming randoming_symbols gaining diflevelcheck;  }
	//cout << "Diflevel: " << diflevel << "\nDifficult: " << difficult << endl;

}
void Feeding() {
	int food = 0;
	int extra = 0;
#define amountfood cout<<"Осталось еды: "<< food << endl; //Количество еды
#define feed if (food > 0) {food = food - 1; health= health + 5; extra++; cout << "Рыбка покормлена.\n";} else {system("cls"); cout << "У тебя еды нет, сходи затарься\n";}
	//Эволюция
#define evo if (extra >= 25) {cout << "Ваша рыбка эволюционировала и поняла, что вы ей больше не нужны\n"; Sleep(7000); death = true; save; anim1re;  return 0;}
}
void Market() {
#define market cout << "Это магазин, здесь вы можете купить еду!\n\n"; cout << "1. Маленькая баночка......................20$\n"; cout << "2. Обычная банка..........................30$\n"; cout << "3. Большая банка..........................50$\n"; cout << "4. Огромная банка.........................100$\n"; cout << "5. Назад\n";
}
void Status() {
	int status = 0; //0 -default, 1...? In development
	//Через свитч выбирает картинку и вставит.

}

int main() {
	//Загрузка(1)
	loadspeed = 0;
	speedanim = 300;
	cout << "Loading"; Sleep(loadspeed); cout << "."; Sleep(loadspeed); cout << "."; Sleep(loadspeed); cout << ".\n"; Sleep(loadspeed);
	animations;
	Health;
	Money;
	Feeding;


	//system("color 14");
	system("color 02");
	setlocale(0, "");
	srand(time(0));
    load;
	//Базовые значения
	int health = 60;
	int money = 20;
	int food = 0;
	int extra = 0; //Evo
	int move = 0;
	char died = 0;
	int difficult = 0; //сложность примеров
	int diflevel = -5; //очки сложности
	int amountwork = 4;
	int gain = 0;


	//Delete below?
	int three = 0;
	int gamestart = 0; //начало
	cout << "Игра с рыбкой. Ваша задача: не дать рыбке умереть!\n\n";
	if(death == true) {
        cout << "1. Новая игра." << endl;
	}
	else { cout << "1. Новая игра." << endl << "2. Продолжить игру." << endl; }
	cin >> gamestart;
	cout << endl;
	switch (gamestart) {
	case 1: {
	    death = false;
	    save;
		break;
	}
	case 2: {
	    if(death == false) {
		load;
	    }
	    else {goto MainMenu;}
	    break;
	}
	default: {
		cout << "Ошибка. Иди нахуй. \n\n";
		system("pause");
        return 0;
		break;

	}
	}

	//Загрузка(2)
	cout << "Loading"; Sleep(loadspeed); cout << "."; Sleep(loadspeed); cout << "."; Sleep(loadspeed); cout << ".\n"; Sleep(loadspeed);

MainMenu:
	system("cls");
	for (;;) {  //Основное меню

		//cout << Картинка; //Статус рыбки
		cout << "1. Заработать денег.             " << "В кармане:      " << money << "$\n";
		cout << "2. Покормить рыбку.              " << "В холодильнике: " << food << "\n";
		cout << "3. Купить еду.                   " << "Здоровье рыбки: " << health << "%\n";
		cout << ""; //??? Потом

		cout << "\n99. Выйти из игры" << "\n";

		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			cout << "тебе нужно будет решить " << amountwork << " примера" << endl;
			gainmoney
				move++;
			dying
				cout << "Всего заработано: " << gain << "$" << endl;
			money += gain;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			system("cls");
			feed
				evo
				break;
		}
		case 3: {
#define notmoney cout<<"Ты бомж, сходи заработай денег!\n"; system("pause");
			for (;;) {
				system("cls");
				cout << "В кармане: " << money << "$" << endl << "В холодильнике: " << food << endl << "Здоровье рыбкиы: " << health << "%\n" << endl;
				market
					int buy = 0;
				cin >> buy;
				switch (buy) {
				case 1: {if (buy == 1 && money >= 20) { money = money - 20; food++; break; } else if (buy == 1 && money < 20) { notmoney break; }}
				case 2: {if (buy == 2 && money >= 30) { money = money - 30; food = food + 2; break; } else if (buy == 2 && money < 30) { notmoney break; }}
				case 3: {if (buy == 3 && money >= 50) { money = money - 50; food = food + 5; break; } else if (buy == 3 && money < 50) { notmoney break; }}
				case 4: {if (buy == 4 && money >= 100) { money = money - 100; food = food + 10; break; } else if (buy == 4 && money < 100) { notmoney break; }}
				case 5: {system("cls"); goto MainMenu; }
				default: {cout << "Вводи номер пункта, епта\n"; system("pause"); system("cls"); save; }
				}
			}
		}
		case 42: {
			health = health - 100000;
			die;
			cout << "Пока ты смотрел на рыбку, она сбежала от тебя\n"; Sleep(7000); cout << "Ты лох"; Sleep(1000); cout << "."; Sleep(1000); cout << "."; Sleep(1000); cout << ".\n"; Sleep(5000);
            death = true;
            save;
			system("pause");

		}
		case 99: { save; return 0; }
		default: {
			cout << "Кажется мы потеряли взаимопонимание...\n"; Sleep(5000);

			system("pause");
			save;
			return 0;
		}
		}

	}
}
