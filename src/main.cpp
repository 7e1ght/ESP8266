#include <stm32f1xx.h>

void delay(uint32_t msec) 
{
    for(uint32_t i = 0; i < 2000UL*msec; ++i)
    {
        __NOP();
    }
}

int main() 
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    GPIOC->CRH |= GPIO_CRH_MODE14_1;
    GPIOA->CRL |= GPIO_CRL_MODE1_1;

    GPIOC->CRH &= ~(GPIO_CRH_CNF14_0);
    GPIOA->CRL &= ~(GPIO_CRL_CNF1_0);

    while(1)
    {
        GPIOC->BSRR |= GPIO_BSRR_BS14;
        delay(100);

        GPIOC->BSRR |= GPIO_BSRR_BR14;
        delay(100);

        GPIOA->BSRR |= GPIO_BSRR_BS1;
        delay(100);

        GPIOA->BSRR |= GPIO_BSRR_BR1;
        delay(100);
    }

    return 0;
}