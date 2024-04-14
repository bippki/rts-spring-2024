#include <TaskManagerIO.h>
#define pin1 3
#define pin2 5
#define pin3 6
#define pin4 9
#define pin5 10

const unsigned long time1 = 10000UL;
const unsigned long time2 = 1000UL;
const unsigned long time3 = 500UL;
const unsigned long time4 = 100UL;
const unsigned long time5 = 50UL;
int pin1State=LOW;
int pin2State=LOW;
int pin3State=LOW;
int pin4State=LOW;
int pin5State=LOW;

void setup() {
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);
  taskid_t task1 = taskManager.scheduleFixedRate(time1, [] {
    if(pin1State==LOW){
      pin1State=HIGH;  
    }else{
      pin1State=LOW;
      }    
    digitalWrite(pin1,pin1State);
  }, TIME_MICROS);
  taskid_t task2 = taskManager.scheduleFixedRate(time2, [] {
    if(pin2State==LOW){
      pin2State=HIGH;  
    }else{
      pin2State=LOW;
      }    
    digitalWrite(pin2,pin2State);
  }, TIME_MICROS);
  taskid_t task3 = taskManager.scheduleFixedRate(time3, [] {
    if(pin3State==LOW){
      pin3State=HIGH;  
    }else{
      pin3State=LOW;
      }    
    digitalWrite(pin3,pin3State);
  }, TIME_MICROS);
  taskid_t task4 = taskManager.scheduleFixedRate(time4, [] {
    if(pin4State==LOW){
      pin4State=HIGH;  
    }else{
      pin4State=LOW;
      }    
    digitalWrite(pin4,pin4State);
  }, TIME_MICROS);
  taskid_t task5 = taskManager.scheduleFixedRate(time5, [] {
    if(pin5State==LOW){
      pin5State=HIGH;  
    }else{
      pin5State=LOW;
      }    
    digitalWrite(pin5,pin5State);
  }, TIME_MICROS);
}

void loop() {
   taskManager.runLoop();
}
