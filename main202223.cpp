#include "globals.hpp"
void autodrive(float moveAmnt, float speed) {
float n = 0.8;
RT.tare_position();
LT.tare_position();
   while(abs(RT.get_position())<moveAmnt){
float actualspeed = speed-(pow((RT.get_position()/moveAmnt), n)*speed);
       RT.move(-speed);
       RB.move(speed);
       RF.move(speed);
       LT.move(speed);
       LB.move(-speed);
       LF.move(-speed);
	pros::delay(20);
   }
   if(speed>0){
	   RT.move(10);
  	   RB.move(-10);
       RF.move(-10);
       LT.move(-10);
       LB.move(10);
       LF.move(10);
       pros::delay(100);
       RT.move(0);
       RB.move(0);
       RF.move(0);
       LT.move(0);
       LB.move(0);
       LF.move(0);}
   else{
	   RT.move(0);
       RB.move(0);
       RF.move(0);
       LT.move(0);
       LB.move(0);
       LF.move(0);}
    }
void turnAuton(float moveAmnt, float speed){
   RT.tare_position();
   LT.tare_position();
    while(abs(RT.get_position())<moveAmnt){
    RT.move(-speed);
    RB.move(speed);
    RF.move(speed);
    LT.move(-speed);
    LB.move(speed);
    LF.move(speed);
}
   if(speed>0){
	   RT.move(10);
   	   RB.move(-10);
       RF.move(-10);
       LT.move(-10);
       LB.move(10);
       LF.move(10);
       pros::delay(100);
       RT.move(0);
       RB.move(0);
       RF.move(0);
       LT.move(0);
       LB.move(0);
       LF.move(0);
   }else{
       RT.move(-10);
       RB.move(10);
       RF.move(10);
       LT.move(10);
       LB.move(-10);
       LF.move(-10);
       pros::delay(100);
       RT.move(0);
       RB.move(0);
       RF.move(0);
       LT.move(0);
	   LB.move(0);
       LF.move(0);
   }
 
}
void autonomous() {}

void opcontrol() {
    
    bool IntakeStatus=false;
	bool ShooterStatus=false;
    bool CataStatus=false;
    bool DropperStatus=false;
    bool WingStatus;
    pros::ADIDigitalOut LeftPiston = pros::ADIDigitalOut('F', true);
    pros::ADIDigitalOut RightPiston = pros::ADIDigitalOut('D', true); 
	pros::Controller master (E_CONTROLLER_MASTER);
	while(true){

	RT.move(master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
	RB.move(-master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
    RF.move(-master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y));
	LT.move(-master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
	LB.move(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
	LF.move(master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));

    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){ //negative is forwards
			if (!IntakeStatus) {
				IntakeStatus=true;
				IntakeMotor.move(-127);
			} else {
				IntakeStatus=false;
				IntakeMotor.move(0);
			}
        }   
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
			if (!IntakeStatus) {
				IntakeStatus=true;
				IntakeMotor.move(127);
			} else {
				IntakeStatus=false;
				IntakeMotor.move(0);
			}
        }

    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){ //positive true=forwards
			if (!DropperStatus) {
				DropperStatus=true;
				DropperMotor.move(60);
                pros::delay(500);
                DropperMotor.move(0);
			} else {
				DropperStatus=false;
				DropperMotor.move(-60);
                pros::delay(500);
                DropperMotor.move(0);
			}
        }   
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
			if (!CataStatus) {
				CataStatus=true;
				CataMotor.move(80);
			} else {
				CataStatus=false;
				CataMotor.move(0);
			}
        }

    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
			if (!WingStatus) {
				WingStatus=true;
				LeftPiston.set_value(WingStatus);
                RightPiston.set_value(WingStatus);
			} else {
				WingStatus=false;
				CataMotor.move(0);
                LeftPiston.set_value(WingStatus);
                RightPiston.set_value(WingStatus);
			}
        }
    }
}
