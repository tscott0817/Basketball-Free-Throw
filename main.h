#ifndef FINAL_PROJECT_TSCOTT5_MAIN_H
#define FINAL_PROJECT_TSCOTT5_MAIN_H

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void init();

void InitGL();

void mainMenu();
void display();

void kbd(unsigned char key, int x, int y);

void kbdS(int key, int x, int y);

void cursor(int x, int y);

void timer(int dummy);

void mouse(int button, int state, int x, int y);


#endif /* FINAL_PROJECT_TSCOTT5_MAIN_H */
