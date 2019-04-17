/*
These are the codes for the small robot
Game Plan has been moved to the README.md file
*/
#include <kipr/botball.h>
void moveForward(){
    motor(0, 100);
    motor(3, 100);
}
void turnRight(){
    motor(3,75);  
}
void turnLeft(){
    motor(0,75);
}

void moveBackward(){
    motor(0, -100);
    motor(3, -100);
}
void moveForwardUntilBlack(){
    while(analog(1)<2000){

        motor(0,50);
        motor(3,50);

    }
    ao();    }
void moveBackwardUntilBlack(){
    while(analog(1)<2000){

        motor(0,-50);
        motor(3,-50);

    }
    ao();    }
void turnLeftUntilWhite(){
    while(analog(1)>800){


        motor(3,49);

    }
    ao();    }
void turnRightUntilWhite(){
    while(analog(1)>800){


        motor(3,49);

    }
    ao();    }
void putArmDown(){
    set_servo_position(0,1632);
}
void arm2DownNclose(){
    set_servo_position(1,5);
    msleep(1000);
    set_servo_position(0,66);
}
void arm2UpNopen(){
    set_servo_position(1,1457);
    msleep(1000);
    set_servo_position(0,1843);
}
void followBlack(){
    cmpc(0);
    msleep(1000);
    while (gmpc(0)> -6300){
        if (analog(1)>1000)
        {
            motor(0,-20);
            motor(3,-100);
        }
        else{
            motor(0,-100);
            motor(3,-20);
        }
        gmpc(0);
    }
    ao();
}
void turnInAWeirdWayToWhite(){
     while(analog(0)>1900){
        motor(0,-59);

    }
    
    ao();   
}
void clawDown(){
    set_servo_position(3, 1666);
}
void clawUp(){
    set_servo_position(3,467);
}
void moveBackwardUntilBlue(){
    while(analog(1)<185){ //original 1-2000
        motor(0,-30);
        motor(3,-30);
    }
    ao();    
}
void moveForwardUntilBlue(){
    while(analog(1)<2000){


        motor(0,50);
        motor(3,50);

    }
    ao();    }
void turnLeftUntilBlue(){
    while(analog(0)<1500){
        motor(0,-59);

    }
    
    ao();   
}

void turnLeftUntilGrey()
{
    while(analog(2)<1150){


        motor(3,59);

    }
    ao();    }

void turnRightUntilGrey()
{
    while(analog(0)<3000){


        motor(0,59);

    }
    ao();    }

void followBlue(){
   cmpc(0);
    msleep(1000);
    while (gmpc(0)> -5000){
        if (analog(0)>2390)
        {
            // was -50 instead of -30
            motor(0,-30);
            motor(3,-10);
        }
        else{
            motor(0,-10);
            //was -50 instead of -30
            motor(3,-30);
        }
        gmpc(0);
    }
    ao();

}


int main()
{
    printf("Hello World\n");
    enable_servos();
    set_servo_position(3,422);
    set_servo_position(0,557);
    set_servo_position(1,0);
    ao();
    msleep(500);
    moveForwardUntilBlack();
    ao();
    msleep(1000);
    set_servo_position(0,1846);
    ao();
    msleep(1000);
    moveForward();
    msleep(700);
    moveForwardUntilBlack();
    ao();
    msleep(1000);
    // turnLeftUntilWhite();
    ao();
    msleep(1000);
    followBlack();
    ao();
    msleep(1250);
    //// after following black, the robot will turn to get the fisrt 3 blue balls

    
    turnLeftUntilGrey();
    ao();
    msleep(1000);
   
   
    //turnRight();
    //msleep(1300);
    //ao();
    //msleep(500);


    clawDown();// claw goes down to grab the first set of blue balls
    ao();
    msleep(500);
    
    moveBackward();// move to get the blue balls in the claw
    msleep(700);
    ao();
    msleep(500);

  
    clawUp();// claw up to put the blue balls in the coupler
    ao();
    msleep(500);

    
    //was a move back until blue //moves toward blue poms to grab
    moveBackwardUntilBlue();
    ao();
    msleep(1000);
    turnLeftUntilWhite();
    ao();
    msleep(1000);
    //turnLeftUntilBlue(); //aligns with blue tape to grab blue balls
    //ao();
    //msleep(1000);
    printf("turned until blue");
    followBlue(); //starts to follow blue
    ao();
    msleep(1000);
    turnInAWeirdWayToWhite();



    return 0;
}
