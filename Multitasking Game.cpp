#include <iostream>
#include <cstdio>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#define WINDOW "test"
using namespace std;
using namespace cv;
Point previousPoint;
bool P = false;

int max255 = 255,t = 0;
char bffer[32];
char bffer2[32];
char bffer3[32];
Mat img(475, 900, CV_8UC3, Scalar(255,255,255));
Mat nextimg ;
void On_mouse(int event, int x, int y, int flags, void*);
void gg();
int r1 = 0,r2 = 0,r3 = 0,r4 = 0,r5 = 0, r11= 0, r12 = 0,ball_live = 1,Score = 0,dd = 500,lives = 10,go = 0,eee= 0,ggg = 0, zzz = 0;
float start_v = 0.2,stage = 0;

void ori();
class ball{
public:
    int color;
    int delay;
    float vx;
    float vy;
    float y;
    float x;
    int r1;
    int r2;
    int r3;
};
ball blist[1000];
    ball* b1 = &blist[0];
    ball* b2 = &blist[1];
    ball* b3 = &blist[2];
    ball* b4 = &blist[3];
    ball* b5 = &blist[4];
void On_mouse(int event, int x, int y, int flags, void*)
{

    setMouseCallback(WINDOW, On_mouse, 0);


    //imshow(WINDOW, img);
    //waitKey(1);
    //std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
    if (event == EVENT_LBUTTONDOWN)  //left click to save point(x,y)
	{
	    if(go == 0){
            go = 1;
	    }
		previousPoint = Point(x, y);
		//std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
		if(x >= 475 && x <= 525 && y>=100 && y<=150){
            if(r1 == 1){
                line(img, Point(525,100), Point(525,150), Scalar(255,255,255), 2);
                line(img, Point(475,100), Point(475,150), Scalar(0,0,0), 2);
                r1 = 0;
                imshow(WINDOW, img);
                //waitKey(1);

            }else{
                line(img, Point(475,100), Point(475,150), Scalar(255,255,255), 2);
                line(img, Point(525,100), Point(525,150), Scalar(0,0,0), 2);
                r1=1;
                imshow(WINDOW, img);
                //waitKey(1);

            }
		}
		if(x >= 625 && x <= 675 && y>=225 && y<=275){

            if(r2 == 0){
                line(img, Point(625,225), Point(625,275), Scalar(255,255,255), 2);
                line(img, Point(675,225), Point(675,275), Scalar(0,0,0), 2);
                r2 = 1;
                imshow(WINDOW, img);
                //waitKey(1);
            }else{
                line(img,Point(675,225), Point(675,275) , Scalar(255,255,255), 2);
                line(img, Point(625,225), Point(625,275), Scalar(0,0,0), 2);
                r2= 0;
                imshow(WINDOW, img);
                //waitKey(1);
            }
		}
		if(x >= 800 && x <= 850 && y>=225 && y<=275){

            if(r3 == 1){
                line(img, Point(800,275), Point(850,275), Scalar(255,255,255), 2);
                line(img, Point(800,225), Point(850,225), Scalar(0,0,0), 2);
                r3 = 0;
                imshow(WINDOW, img);
                //waitKey(1);
            }else{
                line(img,Point(800,225), Point(850,225), Scalar(255,255,255), 2);
                line(img, Point(800,275), Point(850,275), Scalar(0,0,0), 2);
                r3= 1;
                imshow(WINDOW, img);
                //waitKey(1);
            }
		}
		if(x >= 500 && x <= 550 && y>=225 && y<=275){

            if(r4 == 1){
                line(img, Point(500,275), Point(550,275), Scalar(255,255,255), 2);
                line(img, Point(500,225), Point(500,275), Scalar(0,0,0), 2);
                r4 = 0;
                imshow(WINDOW, img);
                //waitKey(1);
            }else{
                line(img,Point(500,225), Point(500,275), Scalar(255,255,255), 2);
                line(img, Point(500,275), Point(550,275), Scalar(0,0,0), 2);
                r4= 1;
                imshow(WINDOW, img);
                //waitKey(1);
            }
		}
		if(x >= 275 && x <= 325 && y<=150 && y>=100){

            if(r5 == 1){
                line(img, Point(325,150), Point(275,150), Scalar(255,255,255), 2);
                line(img, Point(275,100), Point(275,150), Scalar(0,0,0), 2);
                r5 = 0;  //go dow
                imshow(WINDOW, img);
                //waitKey(1);
            }else{
                line(img,Point(275,100), Point(275,150), Scalar(255,255,255), 2);
                line(img, Point(325,150), Point(275,150), Scalar(0,0,0), 2);
                r5= 1; //go left
                imshow(WINDOW, img);
                //waitKey(1);
            }
		}
		if(x >= 275 && x <= 325 && y<=275 && y>=225){

            if(r11 == 1){
                line(img, Point(275,275), Point(325,275), Scalar(255,255,255), 2);
                line(img, Point(325,225), Point(325,275), Scalar(0,0,0), 2);
                r11 = 0;  //go dow
                imshow(WINDOW, img);
                //waitKey(1);
            }else{
                line(img,Point(325,225), Point(325,275), Scalar(255,255,255), 2);
                line(img, Point(275,275), Point(325,275), Scalar(0,0,0), 2);
                r11= 1; //go rigt
                imshow(WINDOW, img);
                //waitKey(1);
            }
		}
		if(x >= 500 && x <= 550 && y<= 425 && y>= 375){

            if(r12 == 1){
                line(img, Point(500,375), Point(500,425), Scalar(255,255,255), 2);
                line(img, Point(550,375), Point(550,425), Scalar(0,0,0), 2);
                r12 = 0;  //go left
                imshow(WINDOW, img);
               // waitKey(1);
            }else{
                line(img,Point(550,375), Point(550,425), Scalar(255,255,255), 2);
                line(img, Point(500,375), Point(500,425), Scalar(0,0,0), 2);
                r12= 1; //go rigt
                imshow(WINDOW, img);
                //waitKey(1);
            }
		}
		//waitKey(1);
	}

}

void On_mouse2(int event, int x, int y, int flags, void*)
{

    if (event == EVENT_RBUTTONDOWN)
	{
        //std:cout <<"iiiiiiii"<< endl;
		go = 1;
	}

}
void On_mouse3(int event, int x, int y, int flags, void*)
{

    if (event == EVENT_RBUTTONDOWN)
	{
        //std:cout <<"iiiiiiii"<< endl;
		eee = 1;
	}
	if( event == EVENT_LBUTTONDOWN){
            //std::cout <<" llllllLLLLLLLLL " << endl;
        ggg = 1;
	}

}
void resetball(int i){
    // std:cout <<ball_live<< endl;
    int k = rand() % (6 - 1 + 1) + 1;

    blist[i].color = k;
    if(k == 1){ //yellow
        blist[i].r1 = 0;
        blist[i].r2 = 255;
        blist[i].r3 = 255;
    }else if( k == 2){ //pink
        blist[i].r1 = 255;
        blist[i].r2 = 0;
        blist[i].r3 = 255;
    }else if( k == 3){ // ligt blUe
        blist[i].r1 = 255;
        blist[i].r2 = 255;
        blist[i].r3 = 0;
    }else if( k == 4){ //brown
        blist[i].r1 = 0;
        blist[i].r2 = 100;
        blist[i].r3 = 150;
    }else if( k == 5){ //green
        blist[i].r1 = 100;
        blist[i].r2 = 150;
        blist[i].r3 = 0;
    }else if( k == 6){ //blUe
        blist[i].r1 = 150;
        blist[i].r2 = 50;
        blist[i].r3 = 50;
    }
    blist[i].x = 500;
    blist[i].y = 20;
    blist[i].vx = 0;
    blist[i].vy = 0.2 + stage * 0.1;
    //blist[i].delay = i * 1000;
    //std::cout <<  blist[i].vy << endl;
    if(ball_live < 5){
        blist[i].delay = dd;
        dd+=800*(0.1 * (10-stage*1.4));
    }

}
void resetball2(int i){
    start_v = 0.2;
     //std:cout <<ball_live<< endl;
    int k = rand() % (6 - 1 + 1) + 1;

    blist[i].color = k;
    if(k == 1){ //yellow
        blist[i].r1 = 0;
        blist[i].r2 = 255;
        blist[i].r3 = 255;
    }else if( k == 2){ //pink
        blist[i].r1 = 255;
        blist[i].r2 = 0;
        blist[i].r3 = 255;
    }else if( k == 3){ // ligt blUe
        blist[i].r1 = 255;
        blist[i].r2 = 255;
        blist[i].r3 = 0;
    }else if( k == 4){ //brown
        blist[i].r1 = 0;
        blist[i].r2 = 100;
        blist[i].r3 = 150;
    }else if( k == 5){ //green
        blist[i].r1 = 100;
        blist[i].r2 = 150;
        blist[i].r3 = 0;
    }else if( k == 6){ //blUe
        blist[i].r1 = 150;
        blist[i].r2 = 50;
        blist[i].r3 = 50;
    }
    blist[i].x = 500;
    blist[i].y = 20;
    blist[i].vx = 0;
    blist[i].vy = 0.2;
   // std::cout <<  blist[i].vy << endl;
    blist[i].delay = i * 1000;

}
void conner(int i){
    start_v = 0.2 + stage * 0.1;
    float x = blist[i].x;
    float y = blist[i].y;
   //
        if(x == 500 && y>= 124  &&y <= 125){           //bv1

            if(r1 == 0){
                blist[i].vx = start_v;
                blist[i].vy = 0;
            }else{
                blist[i].vx = -start_v;
                blist[i].vy = 0;
            }
            //std::cout <<  blist[i].vy << endl;
		}
		else if(x >=649 && x <= 651  && y >= 124  &&y <= 125){ //bv2
            blist[i].vx = 0;
            blist[i].vy = start_v;
		}

		else if(x >=649 && x <= 651 && y>= 249 && y<= 251){ //bv3

            if(r2 == 0){
               blist[i].vx = start_v ;
               blist[i].vy = 0;
            }else{
               blist[i].vx = -start_v;
               blist[i].vy = 0;
            }
           // std::cout <<  blist[i].vy << endl;
		}
		else if(x >= 824 && x <= 826 && y>=249 && y<=251){   //bv4

            if(r3 == 0){
               blist[i].vx = 0;
               blist[i].vy = start_v ;
            }else{
               blist[i].vx = 0;
               blist[i].vy = -start_v;
            }
           // std::cout <<  blist[i].vy << endl;
		}
		else if(x >= 524 && x <= 526 && y>=238 && y<=251){  //bv5

            if(r4 == 0){
                blist[i].vx = 0;
                blist[i].vy = start_v ;
            }else{
                blist[i].vx = -start_v;
                blist[i].vy = 0;
            }

        }
        else if(x >= 299 && x <= 301 && y>=124 && y<=126){  //bv5

            if(r5 == 0){
                blist[i].vx = 0;
                blist[i].vy = start_v;
            }else{
                blist[i].vx = -start_v;
                blist[i].vy = 0;
            }
            //std::cout <<  blist[i].vy << endl;
        }
        else if(x >= 299 && x <= 301 && y>=249 && y<=251){  //bv5

            if(r11 == 0){
                blist[i].vx = 0;
                blist[i].vy = start_v ;
            }else{
                blist[i].vx = start_v;
                blist[i].vy = 0;
            }
            //std::cout <<  blist[i].vy << endl;
        }
        else if(x >= 524 && x <= 526 && y>=399 && y<=401){  //bv5

            if(r12 == 0){
                blist[i].vx = -start_v ;
                blist[i].vy = 0;
            }else{
                blist[i].vx = start_v ;
                blist[i].vy = 0;
            }
            //std::cout <<  blist[i].vx << endl;
        }
        else if(x >= 469  && x <= 471  &&  y >= 249 && y <= 251){

            if(blist[i].color == 3){
                Score++;
               // std::cout <<Score<< endl;
            }else{
                lives--;
            }
            ball_live--;
            circle(img, Point(blist[i].x,blist[i].y), 20, Scalar(255,255,255), 2);
            circle(img, Point(470,250), 20, Scalar(255,255,0), 5);
            resetball(i);
        }

        else if(x >= 824  && x <= 826 &&  y >= 399 && y <= 401){

            if(blist[i].color == 1){
                Score++;
               // std::cout <<Score<< endl;
            }
            else{
                lives--;
            }
            ball_live--;
            circle(img, Point(blist[i].x,blist[i].y), 20, Scalar(255,255,255), 2);
            circle(img, Point(825,400), 20, Scalar(0,255,255), 5);
            resetball(i);
        }
        else if(x >= 823  && x <= 828  &&  y >= 99 && y <= 101){

            if(blist[i].color == 2){
                Score++;
                //std::cout <<Score<< endl;
            }
            else{
                lives--;
            }
            ball_live--;
            circle(img, Point(blist[i].x,blist[i].y), 20, Scalar(255,255,255), 2);
            circle(img, Point(825,100), 20, Scalar(255,0,255), 5);
            resetball(i);
        }
        else if(x >= 244  && x <= 246  &&  y >= 124 && y <= 126){

            if(blist[i].color == 4){
                Score++;
               // std::cout <<Score<< endl;
            }
            else{
                lives--;
            }
            ball_live--;
            circle(img, Point(blist[i].x,blist[i].y), 20, Scalar(255,255,255), 2);
            circle(img, Point(245,125), 20, Scalar(0,100,150), 5);
            resetball(i);
        }
        else if(x >= 295  && x <= 303  &&  y >= 395 && y <= 405){

            if(blist[i].color == 5){
                Score++;
               // std::cout <<Score<< endl;

            }
            else{
                lives--;
            }
            ball_live--;
            circle(img, Point(blist[i].x,blist[i].y), 20, Scalar(255,255,255), 2);
            circle(img, Point(300,405), 20, Scalar(100,150,0), 5);
            resetball(i);
        }
        else if(x >= 649  && x <= 651  &&  y >= 399 && y <= 401){

            if(blist[i].color == 6){
                Score++;
                //std:cout <<Score<< endl;
            }else{
                lives--;
            }
            ball_live--;
            circle(img, Point(blist[i].x,blist[i].y), 20, Scalar(255,255,255), 2);
            circle(img, Point(650,400), 20, Scalar(150,50,50), 5);
            resetball(i);
        }


}
void bv(){

    while(1){
        setMouseCallback(WINDOW, On_mouse, 0);
        if(b1->delay <= 0){

            circle(img, Point(b1->x, b1->y), 20, Scalar(255,255,255), 2);
            circle(img, Point(b1->x+ b1->vx, b1->y+ b1->vy), 20, Scalar(b1->r1,b1->r2,b1->r3), 2);
            b1->x= b1->x + b1->vx; b1->y = b1->y + b1->vy;
            imshow(WINDOW, img);
            //waitKey(1);
            conner(0);
        }else{
            b1->delay--;
            if(b1->delay<= 0){
                ball_live++;
            }
        }
        if(b2->delay <= 0){

            circle(img, Point(b2->x, b2->y), 20, Scalar(255,255,255), 2);
            circle(img, Point(b2->x+ b2->vx, b2->y+b2->vy), 20, Scalar(b2->r1,b2->r2,b2->r3), 2);
            b2->x= b2->x + b2->vx; b2->y = b2->y + b2->vy;
            imshow(WINDOW, img);
            //waitKey(1);
            conner(1);
        }else{
            b2->delay--;
            if(b2->delay<= 0){
                ball_live++;
            }
        }
        if(b3->delay <= 0){

            circle(img, Point(b3->x, b3->y), 20, Scalar(255,255,255), 2);
            circle(img, Point(b3->x+ b3->vx, b3->y+ b3->vy), 20, Scalar(b3->r1,b3->r2,b3->r3), 2);
            b3->x= b3->x + b3->vx; b3->y = b3->y + b3->vy;
            imshow(WINDOW, img);
            //waitKey(1);
            conner(2);
        }else{
            b3->delay--;
            if(b3->delay<= 0){
                ball_live++;
            }
        }
        if(b4->delay <= 0){

            circle(img, Point(b4->x, b4->y), 20, Scalar(255,255,255), 2);
            circle(img, Point(b4->x+ b4->vx, b4->y+ b4->vy), 20, Scalar(b4->r1,b4->r2,b4->r3), 2);
            b4->x= b4->x + b4->vx; b4->y = b4->y + b4->vy;
            imshow(WINDOW, img);
            //waitKey(1);
            conner(3);
        }else{
            b4->delay--;
            if(b4->delay<= 0){
                ball_live++;
            }
        }
        if(b5->delay <= 0){

            circle(img, Point(b5->x, b5->y), 20, Scalar(255,255,255), 2);
            circle(img, Point(b5->x+ b5->vx, b5->y+ b5->vy), 20, Scalar(b5->r1,b5->r2,b5->r3), 2);
            b5->x= b5->x + b5->vx;b5->y = b5->y + b5->vy;
            imshow(WINDOW, img);
            //waitKey(1);
            conner(4);
        }else{
            b5->delay--;
            if(b5->delay<= 0){
                ball_live++;
            }
        }
        if(dd > 500){
            dd--;
        }

        putText(img,std::string(bffer) , Point(40,300), 0, 1, Scalar(100,132,255),5);
    if(Score > 50){
        stage = 5;
    }else if(Score > 40){
        stage = 4;
    }else if(Score > 30){
        stage = 3;
    }else if(Score > 20){
        stage = 2;
    }else if(Score > 10){
        stage = 1;
    }
    itoa(stage,bffer,10);
    putText(img,std::string(bffer) , Point(40,300), 0, 1, Scalar(0,0,0),5);

    putText(img,std::string(bffer2) , Point(40,155), 0, 1, Scalar(100,132,255),5);
    itoa(Score,bffer2,10);
    putText(img,std::string(bffer2) , Point(40,155), 0, 1, Scalar(0,0,0),5);

    putText(img,std::string(bffer3) , Point(40,440), 0, 1, Scalar(100,132,255),5);

    itoa(lives,bffer3,10);
    putText(img,std::string(bffer3) , Point(40,440), 0, 1, Scalar(0,0,0),5);

            if(r1 == 0){
                line(img, Point(475,100), Point(475,150), Scalar(0,0,0), 2);
            }else if(r1==1){
                line(img, Point(525,100), Point(525,150), Scalar(0,0,0), 2);
            }
            if(r2 == 0){
                line(img, Point(625,225), Point(625,275), Scalar(0,0,0), 2);
            }else if(r2==1){
                line(img, Point(675,225), Point(675,275), Scalar(0,0,0), 2);
            }
            if(r3 == 0){
                line(img, Point(800,225), Point(850,225), Scalar(0,0,0), 2);
            }else if(r3==1){
                line(img, Point(800,275), Point(850,275), Scalar(0,0,0), 2);
            }
            if(r4 == 0){
                line(img, Point(500,225), Point(500,275), Scalar(0,0,0), 2);
            }else if(r4==1){
                line(img, Point(500,275), Point(550,275), Scalar(0,0,0), 2);
            }
            if(r5 == 0){
                line(img, Point(275,100), Point(275,150), Scalar(0,0,0), 2);
            }else if(r5==1){
                line(img, Point(325,150), Point(275,150), Scalar(0,0,0), 2);
            }
            if(r11 == 0){
                line(img, Point(325,225), Point(325,275), Scalar(0,0,0), 2);
            }else if(r11==1){
               line(img, Point(275,275), Point(325,275), Scalar(0,0,0), 2);
            }
            if(r12 == 0){
                line(img, Point(550,375), Point(550,425), Scalar(0,0,0), 2);
            }else if(r12==1){
                line(img, Point(500,375), Point(500,425), Scalar(0,0,0), 2);
            }
            circle(img, Point(500,125), 5, Scalar(0,0,0), -1);
        circle(img, Point(650,250), 5, Scalar(0,0,0), -1);
        circle(img, Point(525,250), 5, Scalar(0,0,0), -1);
        circle(img, Point(825,250), 5, Scalar(0,0,0), -1);
        circle(img, Point(525,400), 5, Scalar(0,0,0), -1);
        circle(img, Point(300,125), 5, Scalar(0,0,0), -1);
        circle(img, Point(300,250), 5, Scalar(0,0,0), -1);


         if(lives <= 0){
            break;
        }
        imshow(WINDOW, img);
        waitKey(1);
    }

    gg();
}
void gg(){

    rectangle(img, Point(0,0), Point(900,475), Scalar(0,0,0), -1);
    //imshow(WINDOW, img);
    putText(img,std::string("Score : ") , Point(150,120), 0, 2, Scalar(100,132,255),5);
    putText(img,std::string(bffer2) , Point(420,120), 0, 2, Scalar(100,132,255),5);
    putText(img,std::string("G G") , Point(440,220), 0, 1, Scalar(100,132,255),5);
    //rectangle(img, Point(250,280), Point(450,340), Scalar(100,132,255), -1);
    //rectangle(img, Point(500,280), Point(700,340), Scalar(100,132,255), -1);
    putText(img,std::string("*Click left button to try again") , Point(5,300), 0, 1, Scalar(100,132,255),3);
    putText(img,std::string("*Click right button to end the game") , Point(5,400), 0, 1, Scalar(100,132,255),3);
    imshow(WINDOW, img);
    waitKey(1);

    while(1){
    go = 0;
    setMouseCallback(WINDOW, On_mouse3, 0);
    if(eee == 1){
        break;
    }else if(ggg == 1){
        ori();
        break;
    }
    imshow(WINDOW, img);
    waitKey(1);
    }
    if(eee == 0){
        bv();
    }
}
void ori(){
    r1 = 0;r2 = 0;r3 = 0;r4 = 0;r5 = 0; r11= 0; r12 = 0;ball_live = 1;Score = 0;dd = 500;lives = 10;go = 0;eee= 0;ggg = 0; zzz= 1;
    start_v = 0.2;
    stage = 0;

    srand((unsigned)time(NULL));

    for( int i  = 0; i < 5; i++){
        resetball2(i);
    }
    blist[1].delay = 1000;
    blist[2].delay = 1500;
    blist[3].delay = 2000;
    blist[4].delay = 2500;

    rectangle(img, Point(0,0), Point(900,475), Scalar(255,255,255), -1);

    rectangle(img, Point(0,0), Point(200,550), Scalar(100,132,255), -1);

    putText(img, std::string("Score"), Point(40,100), 0, 1, Scalar(0,0,0),2);

    rectangle(img, Point(20,120), Point(150,180), Scalar(0,0,0), 1);

    putText(img, std::string("Stage"), Point(40,240), 0, 1, Scalar(0,0,0),2);
    rectangle(img, Point(20,260), Point(150,320), Scalar(0,0,0), 1);
    putText(img,std::string(bffer) , Point(40,300), 0, 1, Scalar(0,0,0),5);

    putText(img,std::string("Lives") , Point(40,380), 0, 1, Scalar(0,0,0),2);
    rectangle(img, Point(20,400), Point(150,460), Scalar(0,0,0), 1);

    line(img, Point(475,100), Point(475,150), Scalar(0,0,0), 2);
    line(img, Point(625,225), Point(625,275), Scalar(0,0,0), 2);
    line(img, Point(800,225), Point(850,225), Scalar(0,0,0), 2);
    line(img, Point(500,225), Point(500,275), Scalar(0,0,0), 2);
    line(img, Point(325,225), Point(325,275), Scalar(0,0,0), 2);
    line(img, Point(550,375), Point(550,425), Scalar(0,0,0), 2);
    line(img, Point(275,100), Point(275,150), Scalar(0,0,0), 2);

    line(img, Point(475,0), Point(475,100), Scalar(0,0,0), 2);
    line(img, Point(525,0), Point(525,100), Scalar(0,0,0), 2);
    //r1
    line(img, Point(525,100), Point(625,100), Scalar(0,0,0), 2);
    line(img, Point(475,150), Point(625,150), Scalar(0,0,0), 2);
    //L1
    line(img, Point(325,150), Point(525,150), Scalar(0,0,0), 2);
    line(img, Point(475,100), Point(275,100), Scalar(0,0,0), 2);

    circle(img, Point(245,125), 20, Scalar(0,100,150), 5);

    line(img, Point(325,150), Point(325,225), Scalar(0,0,0), 2);
    line(img, Point(275,150), Point(275,375), Scalar(0,0,0), 2);
    line(img, Point(325,275), Point(325,375), Scalar(0,0,0), 2);

    circle(img, Point(300,405), 20, Scalar(100,150,0), 5);

    line(img, Point(325,225), Point(440,225), Scalar(0,0,0), 2);
    line(img, Point(325,275), Point(440,275), Scalar(0,0,0), 2);
    //R2
    line(img, Point(625,100), Point(675,100), Scalar(0,0,0), 2);
    line(img, Point(625,150), Point(625,225), Scalar(0,0,0), 2);
    line(img, Point(675,100), Point(675,225), Scalar(0,0,0), 2);

    line(img, Point(625,225), Point(500,225), Scalar(0,0,0), 2);
    line(img, Point(800,275), Point(550,275), Scalar(0,0,0), 2);

    line(img, Point(550,275), Point(550,375), Scalar(0,0,0), 2);
    line(img, Point(500,275), Point(500,375), Scalar(0,0,0), 2);

    //line(img, Point(550,425), Point(550,475), Scalar(0,0,0), 2);
     line(img, Point(500,425), Point(550,425), Scalar(0,0,0), 2);

    line(img, Point(550,425), Point(625,425), Scalar(0,0,0), 2);
    line(img, Point(550,375), Point(625,375), Scalar(0,0,0), 2);

    circle(img, Point(650,400), 20, Scalar(150,50,50), 5);

    line(img, Point(500,425), Point(335,425), Scalar(0,0,0), 2);
    line(img, Point(500,375), Point(335,375), Scalar(0,0,0), 2);

    line(img, Point(675,225), Point(800,225), Scalar(0,0,0), 2);

    line(img, Point(800,125), Point(800,225), Scalar(0,0,0), 2); line(img, Point(800,375), Point(800,275), Scalar(0,0,0), 2);
    line(img, Point(850,125), Point(850,375), Scalar(0,0,0), 2);
    //line(img, Point(550,375), Point(625,375), Scalar(0,0,0), 2);
    //bcirc
    circle(img, Point(470,250), 20, Scalar(255,255,0), 5);
    circle(img, Point(825,100), 20, Scalar(255,0,255), 5);
    circle(img, Point(825,400), 20, Scalar(0,255,255), 5);

    circle(img, Point(500,125), 5, Scalar(0,0,0), -1);

}

void R(){
    while(1){
    rectangle(img, Point(0,0), Point(900,475), Scalar(100,132,255), -1);
    putText(img, std::string("Rules"), Point(400,50), 0, 1, Scalar(0,0,0),2);
    putText(img, std::string("1. Set walls to send moving balls to the correspondent destinations."), Point(5,100), 0, 0.8, Scalar(0,0,0),2);
    putText(img, std::string("2. Balls will decide which way to go when they reach corners."), Point(5,150), 0, 0.8, Scalar(0,0,0),2);
    putText(img, std::string("3. If you set walls after balls decide, balls will break the walls"), Point(5,200), 0, 0.8, Scalar(0,0,0),2);
    putText(img, std::string("4. There are at most 5 balls appear on the map simultaneously"), Point(5,250), 0, 0.8, Scalar(0,0,0),2);
    putText(img, std::string("5. Speed of balls will accelerate as stage goes up."), Point(5,300), 0, 0.8, Scalar(0,0,0),2);
    putText(img, std::string("6. Every time you make mistake lives, - 1 (you got 10 lives at first)."), Point(5,350), 0, 0.8, Scalar(0,0,0),2);
    putText(img, std::string("*Click right button to start the game"), Point(5,430), 0, 1, Scalar(0,0,0),2);
    imshow(WINDOW, img);
    waitKey(1);

        //std::cout << "kkkkk" << std::endl;
        img.copyTo(nextimg);
        namedWindow(WINDOW);
        setMouseCallback(WINDOW, On_mouse2, 0);
        if(go == 1){
            break;
        }
    }

}
int main()
{
    R();
    /*srand((unsigned)time(NULL));

    for( int i  = 0; i < 5; i++){
        resetball2(i);
    }
    blist[1].delay = 1000;
    blist[2].delay = 1500;
    blist[3].delay = 2000;
    blist[4].delay = 2500;

    */
    /*while(1){

        img.copyTo(nextimg);
        namedWindow(WINDOW);
        //imshow(WINDOW, nextimg);
        setMouseCallback(WINDOW, On_mouse, 0);

        //float k = rand() % (5- 1 + 1) + 1;
        //std::cout << k << endl;
        itoa(t,bffer,10);
        itoa(Score,bffer2,10);
        imshow(WINDOW, img);
        waitKey(500);
    }*/
        ori();
        bv();
        gg();
        //break;


	return 0;
}
