//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

	float x=420;
	float y=685;
	int sx =20;
	int sy =10;
	float oppx =235; 			// for opponent car
	float oppy=195;			// for opponent car
	int food[8][8];
	int score=00;
	int menu=0;
	int arrowx=220, arrowy=505;
	int fast=1;
	int restart=0;	
	int lifes=3;
	int flag1=0;
	int level=1;
	
	


// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}



/*
 * Main Canvas drawing function.
 * */
//Board *b;

void GameDisplay()/**/{	

	if(menu==0)
	{
				// FOR MENU

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	DrawString( 200, 600, "MENU FOR THE DODGE EM GAME", colors[RED]);
	DrawString( 250, 500, "1) START A NEW GAME", colors[WHITE]);
	DrawString( 250, 450, "2) SEE HIGH SCORES", colors[WHITE]);
	DrawString( 250, 400, "3) HELP", colors[WHITE]);
	DrawString( 250, 350, "4) EXIT", colors[WHITE]);
	
	int gap_turn = 60;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BLUE];
	DrawRectangle(arrowx, arrowy, swidth-350, sheight-3, scolor);
	
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
	}

	else if(menu==6 || menu==1)
	{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.


	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	if(score>=50)
		level=2;

	if(level==2)
	{
		x=420;
		y=685;
		sx =20;
		sy =10;
		oppx =235; 			// for opponent car
		oppy=195;			// for opponent car
		food[8][8];
		score=00;
		menu=0;
		arrowx=220, arrowy=505;
		fast=1;
		restart=0;	
		lifes=3;
		flag1=0;
		level=1;
	}


	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	DrawString( 500, 780, "SCORE ="+ to_string(score), colors[MISTY_ROSE]);
	
	DrawString( 50, 780, "LIFE REMAINING ="+ to_string(lifes), colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	// Drawing player car
	
	float width = 10; 
	float height = 7;
	float* color = colors[BLUE]; 
	float radius = 1.0;
	DrawRoundRect(x-20,y-18,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x-20+width*3,y-18,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x-20+width*3,y-18+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x-20,y-18+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x-20, y-18+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x-20+width, y-18+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x-20+width*3, y-18+height*2, width, height, color, radius/2); // body right rect
		
	// Drawing opponent car
		
		 width = 10; 
		 height = 7;
		 color = colors[RED]; 
		 radius = 1.0;
	DrawRoundRect(oppx-20,oppy-18,width,height,color,radius); // bottom left tyre
	DrawRoundRect(oppx-20+width*3,oppy-18,width,height,color,radius); // bottom right tyre
	DrawRoundRect(oppx-20+width*3,oppy-18+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(oppx-20,oppy-18+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(oppx-20, oppy-18+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(oppx-20+width, oppy-18+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(oppx-20+width*3, oppy-18+height*2, width, height, color, radius/2); // body right rect

	// Drawing Arena (outer)
	int gap_turn = 60;
	
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	DrawRectangle(sx-20, sy+5, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx+20 + swidth + gap_turn, sy+5, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth-100, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth-100, scolor); // right up
	DrawRectangle(sx+20 + swidth + gap_turn, sy+705, swidth, sheight, scolor); // top right
	DrawRectangle(sx-20, sy+705, swidth, sheight, scolor); // top left
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth-100, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth-100, scolor); // left down

	// Drawing Arena (1st inner)
		 gap_turn = 60;
		 sx = 20;
		 sy = 10;
		 swidth = 800/2 - gap_turn/2; // half width
		 sheight = 10;
		 scolor = colors[BROWN];
	DrawRectangle(sx+90-20, sy+75, swidth-90, sheight, scolor); // bottom left
	DrawRectangle(sx+20 + swidth + gap_turn, sy+75, swidth-90, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn-90, sy+sheight+70, sheight*2, swidth-100-70, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-90, sy+sheight+swidth+gap_turn, sheight*2, swidth-100-70, scolor); // right up
	DrawRectangle(sx+20 + swidth + gap_turn, sy+710-75, swidth-90, sheight, scolor); // top right
	DrawRectangle(sx+90-20, sy+710-75, swidth-90, sheight, scolor); // top left
	DrawRectangle(sx-sheight*2+90, sy+sheight+swidth+gap_turn, sheight*2, swidth-100-70, scolor); // left up
	DrawRectangle(sx-sheight*2+90, sy+sheight+70, sheight*2, swidth-100-70, scolor); // left down
	
	

	// Drawing Arena (2nd inner)
		 gap_turn = 60;
		 sx = 20;
		 sy = 10;
		 swidth = 800/2 - gap_turn/2; // half width
		 sheight = 10;
		 scolor = colors[BROWN];
	DrawRectangle(sx+180-20, sy+145, swidth-180, sheight, scolor); // bottom left
	DrawRectangle(sx+20 + swidth + gap_turn, sy+145, swidth-180, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn-180, sy+sheight+140, sheight*2, swidth-100-140, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-180, sy+sheight+swidth+gap_turn, sheight*2, swidth-100-140, scolor); // right up
	DrawRectangle(sx+20 + swidth + gap_turn, sy+710-145, swidth-180, sheight, scolor); // top right
	DrawRectangle(sx+180-20, sy+710-145, swidth-180, sheight, scolor); // top left
	DrawRectangle(sx-sheight*2+180, sy+sheight+swidth+gap_turn, sheight*2, swidth-100-140, scolor); // left up
	DrawRectangle(sx-sheight*2+180, sy+sheight+140, sheight*2, swidth-100-140, scolor); // left down

	// Drawing Arena (3rd inner)
		 gap_turn = 60;
		 sx = 20;
		 sy = 10;
		 swidth = 800/2 - gap_turn/2; // half width
		 sheight = 10;
		 scolor = colors[BROWN];
	DrawRectangle(sx+270-20, sy+215, swidth-270, sheight, scolor); // bottom left
	DrawRectangle(sx+20 + swidth + gap_turn, sy+215, swidth-270, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn-270, sy+sheight+210, sheight*2, swidth-100-210, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-270, sy+sheight+swidth+gap_turn, sheight*2, swidth-100-210, scolor); // right up
	DrawRectangle(sx+20 + swidth + gap_turn, sy+710-215, swidth-270, sheight, scolor); // top right
	DrawRectangle(sx+270-20, sy+710-215, swidth-270, sheight, scolor); // top left
	DrawRectangle(sx-sheight*2+270, sy+sheight+swidth+gap_turn, sheight*2, swidth-100-210, scolor); // left up
	DrawRectangle(sx-sheight*2+270, sy+sheight+210, sheight*2, swidth-100-210, scolor); // left down

	// Drawing Arena (centre part)
		 gap_turn = 60;
		 sx = 20;
		 sy = 10;
		 swidth = 800/2 - gap_turn/2; // half width
		 sheight = 10;
		 scolor = colors[BROWN];
	DrawRectangle(sx+340, sy+285, swidth-280, sheight, scolor); // bottom left
	DrawRectangle(sx-40 + swidth + gap_turn, sy+285, swidth-300, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn-360, sy+sheight+280, sheight*2, swidth-100-210, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-360, sy+sheight+swidth+gap_turn-70, sheight*2, swidth-100-210, scolor); // right up
	DrawRectangle(sx-40 + swidth + gap_turn, sy+710-285, swidth-300, sheight, scolor); // top right
	DrawRectangle(sx+340, sy+710-285, swidth-280, sheight, scolor); // top left
	DrawRectangle(sx-sheight*2+360, sy+sheight+swidth+gap_turn-70, sheight*2, swidth-100-210, scolor); // left up
	DrawRectangle(sx-sheight*2+360, sy+sheight+280, sheight*2, swidth-100-210, scolor); // left down
		 										
			
						// FOODS FOR PLAYER CAR			
						
	int cx=55, cy=685;	

	for(int i=0 ; i<8 ; i++)
	{
		cx=55;
		for(int j=0 ; j<8 ; j++)	  
		{
			if(cx==x && cy==y)				// CONDITION FOR EATING FOODS AND SCORE INCREMENT
			{
				if(food[i][j]==0)
					score++;			
				food[i][j]=1;
			}
			if(food[i][j]==0)
			{		
				if(j==4)
				{					
					cx=cx+100;	
					DrawCircle(cx,cy,7,colors[RED]);										
				}
				else					
					DrawCircle(cx,cy,7,colors[RED]);					
			}			
			cx=cx+90;			
		}
		if(i==3)
			cy=cy-210;		
		else
			cy=cy-70;			
	}
	
	
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}

	if(menu==3)
	{
	
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
			// HELP FOR THE DODGE_EM GAME
	
	DrawString( 200, 800, "HELP FOR THE DODGE_EM GAME", colors[YELLOW]);
	DrawString( 100, 700, "The blue car is the car which is under your control (the player) and the  ", colors[MISTY_ROSE]);
	DrawString( 100, 650, "red one is moved by the computer randomely. when your car touches the ", colors[MISTY_ROSE]);
	DrawString( 100, 600, "red car your one life is lost out of your three(3) lifes. When you lost your  ", colors[MISTY_ROSE]);
	DrawString( 100, 550, "all three lifes then the game is over. ", colors[MISTY_ROSE]);
	DrawString( 100, 500, "You take all the gifts there and you win ", colors[MISTY_ROSE]);	
	DrawString( 100, 450, "NOTE:-More you cross the level more harder it becomes...  ", colors[RED]);
	DrawString( 100, 350, "THE KEYS FOR THIS GAME ARE : ", colors[YELLOW]);	
	DrawString( 100, 300, "1)- Left arrow to move left ", colors[MISTY_ROSE]);
	DrawString( 100, 250, "2)- Right arrow to move right ", colors[MISTY_ROSE]);	
	DrawString( 100, 200, "3)- Up arrow to move up ", colors[MISTY_ROSE]);
	DrawString( 100, 150, "4)- Down arrow to move down ", colors[MISTY_ROSE]);
	DrawString( 100, 100, "5)- Space bar to make the speed of the car faster ", colors[MISTY_ROSE]);
	
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
	
	}
	
			// FOR EXIT OF THE GAME
			
	if(menu==4)
	{
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors	
	
		exit(1); // exit the program when escape key is pressed.
	
		glutSwapBuffers(); // do not modify this line.. or draw anything below this line
	}		

	if(menu==5)
	{
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors	
	
		DrawString( 200, 600, "MENU FOR THE DODGE EM GAME", colors[RED]);
		DrawString( 250, 500, "1) START A NEW GAME", colors[WHITE]);
		DrawString( 250, 450, "2) SEE HIGH SCORES", colors[WHITE]);
		DrawString( 250, 400, "3) HELP", colors[WHITE]);
		DrawString( 250, 350, "4) EXIT", colors[WHITE]);
		DrawString( 250, 300, "5) CONTINUE", colors[WHITE]);
		
		int gap_turn = 60;
		int swidth = 800/2 - gap_turn/2; // half width
		int sheight = 10;
		float *scolor = colors[BLUE];
		DrawRectangle(arrowx, arrowy, swidth-350, sheight-3, scolor);
	
		glutSwapBuffers(); // do not modify this line.. or draw anything below this line
	}
	
//	if(menu==

}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	
	
	
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
			if(::y>280 && ::y<450 && ::x!=55 && ::x!=515)	
				::x=::x-90;							

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
			if(::y>280 && ::y<450 && ::x!=325 && ::x!=785)
				::x=::x+90;	
	
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
			if(::x>375 && ::x<455 && ::y!=265 && ::y!=685)
				::y=::y+70;
				
			if(::arrowy<505)
				::arrowy=::arrowy+50;	

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
			if(::x>375 && ::x<455 && ::y!=55 && ::y!=475)
				::y=::y-70;
				
			if(::arrowy>355)
				::arrowy=::arrowy-50;
				
			else if(menu==5) 	
				{
				if(::arrowy>305)
					::arrowy=::arrowy-50;	
				}
//			else if(::arrowy>355)
//				::arrowy=::arrowy-50;	

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {

	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B')
			{
		if(menu==2 || menu==3)		
			menu=0;
		cout << "b pressed" << endl;

	}
	
	static int flag2=1;
	
	if(key==13)				// THE ARROW TO SELECT THE OPTIONS FROM MENU
	{
		if(flag2==1)
			if(arrowx==220 && arrowy==505)
				menu=1;
		if(flag2!=1)			
			if(arrowx==220 && arrowy==255)			// FLAG2 IS FOR STARTING NEW GAME AND FOR CONTINUE OPTION	
				menu=6;	
		
		if(arrowx==220 && arrowy==455)
			menu=2;				
		
		if(arrowx==220 && arrowy==405)
			menu=3;
	
		if(arrowx==220 && arrowy==355)
			menu=4;
			
		if(arrowx==220 && arrowy==305)
			menu=5;		
	}

	fast=1;				// FOR SPEED UP OF THE CAR
	if(key==32)
		fast=2;
		
		
//	if(x<=oppx+5 && x>=oppx-5 && y<=oppy+5 && y>=oppy-5)
	{	if(key=='R' || key=='r')	
			restart=1;		
	}
	
	if (key == 'p' || key == 'P')
	{
		if(menu==1)		
			menu=5;
	
	}		
			
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

					// FOR MAKING START A NEW GAME FIRST THEN DOING CONTINUE IN OTHERS

	// implement your functionality here
	
	if(menu==1)					//	FOR THE GAME TO PAUSE WHEN MENU IS OPEN
	{
	
			//CAR COLLISION
	flag1=0;		
	if(x<=oppx+5 && x>=oppx-5 && y<=oppy+5 && y>=oppy-5)
	{
		
		if(flag1==0)					// TO MAKE THE LIFE NOT REPEATABLE EVERY TIME
			lifes--;
																		
		x=x; y=y; oppx=oppx; oppy=oppy;
		DrawString( x, y+10, "oops!", colors[WHITE]);
		if(restart==1)
		{
			x=420; y=685;
			oppx =420; oppy=55;			
		}
		restart=0;
		
		glutSwapBuffers(); // do not modify this line.. or draw anything below this line			
		
	}	
	else 
	{
		
				 // CLOCKWISE MOVEMENT OF PLAYER CAR
		
	if(fast==1)
	{		
	
			// RIGHT MOVEMENT OF CAR ON UPPER PART OF THE ARENA
	
		if(y==685 && x>=55 && x<=790)	
			x=x+5;	
		if(y==615 && x>=145 && x<=700)	
			x=x+5;	
		if(y==545 && x>=235 && x<=615)	
			x=x+5;	
		if(y==475 && x>=325 && x<=525)	
			x=x+5;		
						
			// LEFT MOVEMENT OF CAR ON LOWER PART OF THE ARENA			
						
		if(y==265 && x>=330 && x<=515)	
			x=x-5;
		if(y==195 && x>=240 && x<=605)	
			x=x-5;	
		if(y==125 && x>=150 && x<=695)	
			x=x-5;	
		if(y==55 && x>=60 && x<=785)	
			x=x-5;	
			
			// UPPER MOVEMENT OF CAR ON LEFT PART OF THE ARENA
			
		if(x==55 && y>=55 && y<=680)	
			y=y+5;	
		if(x==145 && y>=125 && y<=610)	
			y=y+5;	
		if(x==235 && y>=195 && y<=540)	
			y=y+5;	
		if(x==325 && y>=265 && y<=470)	
			y=y+5;		
					
			// LOWER MOVEMENT OF CAR ON RIGHT PART OF THE ARENA		
						
		if(x==515 && y>=265 && y<=480)	
			y=y-5;
		if(x==605 && y>=195 && y<=550)	
			y=y-5;	
		if(x==695 && y>=125 && y<=620)	
			y=y-5;	
		if(x==785 && y>=55 && y<=690)	
			y=y-5;	
	
	}		
			
				// ANTI-CLOCKWISE MOVEMENT OF OPPONENT CAR
			
		if(oppy==685 && oppx>=55 && oppx<=785)	
			oppx=oppx-5;	
		if(oppy==615 && oppx>=145 && oppx<=695)	
			oppx=oppx-5;	
		if(oppy==545 && oppx>=235 && oppx<=605)	
			oppx=oppx-5;	
		if(oppy==475 && oppx>=325 && oppx<=515)	
			oppx=oppx-5;		
						
		if(oppy==265 && oppx>=325 && oppx<=515)	
			oppx=oppx+5;
		if(oppy==195 && oppx>=235 && oppx<=605)	
			oppx=oppx+5;	
		if(oppy==125 && oppx>=145 && oppx<=695)	
			oppx=oppx+5;	
		if(oppy==55 && oppx>=55 && oppx<=785)	
			oppx=oppx+5;	
			
		if(oppx==55 && oppy>=55 && oppy<=685)	
			oppy=oppy-5;	
		if(oppx==145 && oppy>=125 && oppy<=615)	
			oppy=oppy-5;	
		if(oppx==235 && oppy>=195 && oppy<=545)	
			oppy=oppy-5;	
		if(oppx==325 && oppy>=265 && oppy<=475)	
			oppy=oppy-5;		
						
		if(oppx==515 && oppy>=265 && oppy<=475)	
			oppy=oppy+5;
		if(oppx==605 && oppy>=195 && oppy<=545)	
			oppy=oppy+5;	
		if(oppx==695 && oppy>=125 && oppy<=615)	
			oppy=oppy+5;	
		if(oppx==785 && oppy>=55 && oppy<=685)	
			oppy=oppy+5;	

	}	
	
	flag1=1;
	
			// FASTER MOVEMENT OF THE PLAYER CAR THEN THE USUALL
	if(fast==2)
	{
	
	if(y==685 && x>=55 && x<=790)	
			x=x+10;	
		if(y==615 && x>=145 && x<=700)	
			x=x+10;	
		if(y==545 && x>=235 && x<=615)	
			x=x+10;	
		if(y==475 && x>=325 && x<=525)	
			x=x+10;		
						
		if(y==265 && x>=330 && x<=515)	
			x=x-10;
		if(y==195 && x>=240 && x<=605)	
			x=x-10;	
		if(y==125 && x>=150 && x<=695)	
			x=x-10;	
		if(y==55 && x>=60 && x<=785)	
			x=x-10;	
			
		if(x==55 && y>=55 && y<=680)	
			y=y+10;	
		if(x==145 && y>=125 && y<=610)	
			y=y+10;	
		if(x==235 && y>=195 && y<=540)	
			y=y+10;	
		if(x==325 && y>=265 && y<=470)	
			y=y+10;		
						
		if(x==515 && y>=265 && y<=480)	
			y=y-10;
		if(x==605 && y>=195 && y<=550)	
			y=y-10;	
		if(x==695 && y>=125 && y<=620)	
			y=y-10;	
		if(x==785 && y>=55 && y<=690)	
			y=y-10;	

	}		
	
	
			// RANDOMELY MOVING OF OPPONENT CAR
		
		srand(time(0));
		int move;
/*					// FOR LEFT MOVEMENT
		move=rand()%5;
		if(move==1 || move==3)	
			if(oppy>280 && oppy<450 && oppx!=55 && oppx!=515)	
				oppx=oppx-90;
					// FOR RIGHT MOVEMENT
		move=rand()%5;	
		if(move==1 || move==3)		
			if(oppy>280 && oppy<450 && oppx!=325 && oppx!=785)
				oppx=oppx+90;	
*/					// FOR UP MOVEMENT
		move=rand()%3;		
		if(move==1 || move==2)			
			if(oppx>375 && oppx<465 && oppy!=265 && oppy!=685)
				oppy=oppy+70;
					// FOR DOWN MOVEMENT
		move=rand()%3;		
		if(move==1 || move==2)
			if(oppx>375 && oppx<465 && oppy!=55 && oppy!=475)
				oppy=oppy-70;		
	
	}
	
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutPostRedisplay();
	glutTimerFunc(20.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);
	
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
