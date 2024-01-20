#include "main.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;

/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nTime);

/* Private functions ---------------------------------------------------------*/
int main(void)
{
	// Enable APB2 Clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	// Initialize GPIO_InitStructure
	GPIO_InitTypeDef GPIO_InitStructure;
	// Setting GPIO_InitStructure
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// Initialize GPIO
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// Setting System tick and interrupt
	SysTick_Config(SystemCoreClock / 1000);

	while (1)
	{
		Delay(1000);
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		Delay(1000);
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	}
}

/**
 * @brief  Inserts a delay time.
 * @param  nTime: specifies the delay time length, in milliseconds.
 * @retval None
 */
void Delay(__IO uint32_t nTime)
{
	TimingDelay = nTime;

	while (TimingDelay != 0);
}

/**
 * @brief  Decrements the TimingDelay variable.
 * @param  None
 * @retval None
 */
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}