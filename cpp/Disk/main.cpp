#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
using namespace std;

#include <stdio.h>
#include <Windows.h>


int main()
{
	int width = 120;
	int height = 30;
	float aspect = (float)width / height;
	float pixelAspect = 11.0f / 24.0f;

	char gradient[] = " .:oO#$@$#Oo:. ";
	int gradienSize = size(gradient) - 2;

	wchar_t* screen = new wchar_t[width * height + 1];
	screen[width * height] = '\0';

	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	for (int t = 0; t < 100000; t++) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				float x = (float)i / width * 2.0f - 1.0f;
				float y = (float)j / height * 2.0f - 1.0f;

				x *= aspect * pixelAspect;
				x += sin(t * 0.001);
				y *= cos(t * 0.001);

				char pixel = ' ';
				float dist = sqrt(x * x + y * y);
				int color = (int)(1.0f / dist);

				if (color < 0) color = 0;
				else if (color > gradienSize) color = gradienSize;

				pixel = gradient[color];
				screen[i + j * width] = pixel;
			}
		}
		WriteConsoleOutputCharacter(hConsole, screen, width * height, { 0,0 }, &dwBytesWritten);
	}
	
	getchar();
}