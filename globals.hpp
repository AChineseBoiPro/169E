#include "main.h"

pros::Controller controller (E_CONTROLLER_MASTER);

pros::Motor LF = pros::Motor(/*port # */19, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor LB = pros::Motor(/*port # */10, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor LT = pros::Motor(/*port # */6, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor RF = pros::Motor(/*port # */12, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor RB = pros::Motor(/*port # */3, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor RT = pros::Motor(/*port # */5, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DropperMotor = pros::Motor(/*port # */9, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor IntakeMotor = pros::Motor(/*port # */16, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor CataMotor = pros::Motor(/*port # */16, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::ADIDigitalOut LeftlPiston = pros::ADIDigitalOut('F', false);
pros::ADIDigitalOut RightPiston = pros::ADIDigitalOut('D', false); 
