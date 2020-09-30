/**
Name: Mohamed A
Section EGR 226 904
Date: 9/20/20
ABOUT:  Sequencing colored LEDs using a pushbutton switch AND Sequencing colored LEDs using a timer and pushbutton

 */


#include "msp.h"
void delayFunction(int milli);





void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer



    P2->DIR |= (BIT0 | BIT1 | BIT2);                //sets bits 0,1,&2, pin 2
    P1->DIR &= ~BIT1;                       //resets bit 1 and pin 1 to input

    P1->REN |= BIT1;                            //resistor

    P1->OUT |= BIT1;                                //resistor (pull up)
    P2->OUT &= ~(BIT0 | BIT1 | BIT2);           //turns off P2 BITs 0,1,2 (reset)

    int PushButton = 0;
    int counts = 0;
    int i;


while(1){

if(!(P1->IN & BIT1) && counts == 0 && PushButton == 0)//if button is pushed flag is one,
{
            delayFunction(10);//debounce with delay

            PushButton = 1;

                                                            // WHEN NOT PUSHED
            P2->OUT &= ~BIT1;//turns off bit 1
            P2->OUT &= ~BIT2;//turns off bit 2
            P2->OUT |= BIT0;  //turns on bit 0

            printf("Count is 1");
            counts = 1;// press counter

}


    if(!(P1->IN & BIT1) && counts == 1 && PushButton == 0)//if button is pushed flag is 2
    {
        delayFunction(10);  //debounce

        PushButton = 1;

        P2->OUT &= ~BIT0;
        P2->OUT &= ~BIT2;
        P2->OUT |= BIT1;  //LED
        printf("Count is 2");
        counts = 2; //if pressed 2
    }

    if(!(P1->IN & BIT1) && counts == 2 && PushButton == 0)//if button is pushed flag is 3
    {
        delayFunction(10);

        PushButton = 1;
        P2->OUT &= ~BIT0;
        P2->OUT &= ~BIT1;
        P2->OUT |= BIT2;  //toggle LED status
        printf("Count is 0");
        counts = 0;
     }
     if( !(P1->IN & BIT1) ){//sets PushButton to 0 when button is pressed
         PushButton = 0;

                                                                       //if( !(P1->IN & BIT1) ){      //FOR PART 2
                                                                        // PushButton = 0;

}

delayFunction(1000);
}

}




void delayFunction(int milli){
 int i;

 for(i=0; i<milli; i++){                //loops delay cycles milli times

__delay_cycles(3000);               //delay for time
 }

}
