#define ESC 0x1B
#include "hardware.h"
#include "charset.h"

int joyinout()
{
    uint16_t val_up = (GPIOA->IDR & (0x0001 << 4)) >> 4;
    uint16_t val_down = (GPIOB->IDR & (0x0001 << 0));
    uint16_t val_center = (GPIOB->IDR & (0x0001 << 5)) >> 5;
    uint16_t val_right = (GPIOC->IDR & (0x0001 << 0));
    uint16_t val_left = (GPIOC->IDR & (0x0001 << 1)) >> 1;

    gotoxy(50,30);
    printf("\n\nUp: %d\nDown: %d\nLeft: %d\nRight: %d\nCenter: %d\n", val_up, val_down, val_left, val_right, val_center);

    return val_up | val_down << 1 | val_center << 2 | val_left << 3 | val_right << 4;
}

void setLed(int farve)
{
    if(farve==0b10000 << 0)
    {
        GPIOA->ODR &= ~(0x0001 << 9);
        GPIOB->ODR |= (0x0001 << 4);
        GPIOC->ODR |= (0x0001 << 7);
    }
    else if(farve==0b01000)
    {
        GPIOA->ODR |= (0x0001 << 9);
        GPIOB->ODR &= ~(0x0001 << 4);
        GPIOC->ODR |= (0x0001 << 7);
    }
    else if(farve==0b00100)
    {
        GPIOA->ODR |= (0x0001 << 9);
        GPIOB->ODR |= (0x0001 << 4);
        GPIOC->ODR &= ~(0x0001 << 7);
    }
    else if(farve==0b00010)
    {
        GPIOA->ODR &= ~(0x0001 << 9);
        GPIOB->ODR &= ~(0x0001 << 4);
        GPIOC->ODR |= (0x0001 << 7);
    }
    else if(farve==0b00001)
    {
        GPIOA->ODR &= ~(0x0001 << 9);
        GPIOB->ODR |= (0x0001 << 4);
        GPIOC->ODR &= ~(0x0001 << 7);
    }
    else
    {
        GPIOA->ODR |= (0x0001 << 9);
        GPIOB->ODR |= (0x0001 << 4);
        GPIOC->ODR |= (0x0001 << 7);
    }
}












void timer_pp()
{
    RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;
    TIM2->CR1 = 0; // Configure timer 2
    TIM2->ARR = 6399; // Set reload value / 6399999
    TIM2->PSC = 0; // Set prescale value

    TIM2->DIER |= 0x0001;

    NVIC_SetPriority(TIM2_IRQn, 0); // Set interrupt priority
    NVIC_EnableIRQ(TIM2_IRQn); // Enable interrupt

    TIM2->CR1 |= 0x0001;
}

/*typedef struct timer_t {
    uint8_t hs, s, m, h;
};

volatile struct timer_t tid;
volatile uint8_t flag;*/

void TIM2_IRQHandler(void)
{
    tid.hs++;
    if(tid.hs>=100)
    {
        tid.s++;
        tid.hs=0;
        if(tid.s>=60)
        {
            tid.m++;
            tid.s=0;
            if(tid.m>=60)
            {
                tid.h++;
                tid.m=0;
            }
        }
    }


    flag = 1;
    TIM2->SR &= ~0x0001;

}

void lcd_write_string(char *benis, int slice, int line, uint8_t *buffer)
{
    int len = strlen(benis);
    int k = slice;
    for (int i=0; i < len; i++)
    {
        for (int j=0; j<=4; j++)
        {
            buffer[(k & 0x7F)+(line-1)*128]=character_data[benis[i] - 0x20][j];
            k++;
        }

    }
}

void lcd_update(int *k)
{

    if (flag == 1)
    {
        (*k)--;
        flag = 0;

    }
}


