#include "led.h"

#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
    uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
    uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
    uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
    uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
    uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
    uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

typedef struct
{
  uint32_t Pin;       /*!< Specifies the GPIO pins to be configured.
                           This parameter can be any value of @ref GPIO_pins_define */

  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins.
                           This parameter can be a value of @ref GPIO_mode_define */

  uint32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                           This parameter can be a value of @ref GPIO_pull_define */

  uint32_t Speed;     /*!< Specifies the speed for the selected pins.
                           This parameter can be a value of @ref GPIO_speed_define */

  uint32_t Alternate;  /*!< Peripheral to be connected to the selected pins.
                            This parameter can be a value of @ref GPIO_Alternate_function_selection */
} GPIO_InitTypeDef;

#define PERIPH_BASE      0x40000000UL
#define AHB1PERIPH_BASE  (PERIPH_BASE + 0x00020000UL)
#define GPIOJ_BASE       (AHB1PERIPH_BASE + 0x2400UL)
#define GPIOJ            ((GPIO_TypeDef *) GPIOJ_BASE)

#define GREEN_LED        ((uint16_t)0x0020U)
#define RED_LED          ((uint16_t)0x2000U)

#define GPIO_MODE             ((uint32_t)0x00000003U)
#define GPIO_OUTPUT_TYPE      ((uint32_t)0x00000010U)
#define GPIO_MODE_INPUT                        ((uint32_t)0x00000000U)
#define GPIO_MODE_OUTPUT_PP                    ((uint32_t)0x00000001U)
#define GPIO_MODE_OUTPUT_OD                    ((uint32_t)0x00000011U)
#define GPIO_MODE_AF_PP                        ((uint32_t)0x00000002U)
#define GPIO_MODE_AF_OD                        ((uint32_t)0x00000012U)
#define GPIO_NOPULL           ((uint32_t)0x00000000U)
#define GPIO_SPEED_FREQ_LOW   ((uint32_t)0x00000000U)
#define GPIO_NUMBER           ((uint32_t)16U)
#define GPIO_MODER_MODER0_Pos            (0U)
#define GPIO_MODER_MODER0_Msk            (0x3UL << GPIO_MODER_MODER0_Pos)
#define GPIO_MODER_MODER0                GPIO_MODER_MODER0_Msk
#define GPIO_OSPEEDER_OSPEEDR0_Pos       (0U)
#define GPIO_OSPEEDER_OSPEEDR0_Msk       (0x3UL << GPIO_OSPEEDER_OSPEEDR0_Pos)
#define GPIO_OSPEEDER_OSPEEDR0           GPIO_OSPEEDER_OSPEEDR0_Msk
#define GPIO_OTYPER_OT_0                 0x00000001U
#define GPIO_PUPDR_PUPDR0_Pos            (0U)
#define GPIO_PUPDR_PUPDR0_Msk            (0x3UL << GPIO_PUPDR_PUPDR0_Pos)
#define GPIO_PUPDR_PUPDR0                GPIO_PUPDR_PUPDR0_Msk

typedef enum
{
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
} GPIO_PinState;

void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    if (PinState != GPIO_PIN_RESET) {
        GPIOx->BSRR = GPIO_Pin;
    } else {
        GPIOx->BSRR = (uint32_t)GPIO_Pin << 16;
    }
}

void HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
  uint32_t position = 0x00;
  uint32_t ioposition = 0x00;
  uint32_t iocurrent = 0x00;
  uint32_t temp = 0x00;

  /* Configure the port pins */
  for(position = 0; position < GPIO_NUMBER; position++)
  {
    /* Get the IO position */
    ioposition = ((uint32_t)0x01) << position;
    /* Get the current IO position */
    iocurrent = (uint32_t)(GPIO_Init->Pin) & ioposition;

    if(iocurrent == ioposition)
    {
      /*--------------------- GPIO Mode Configuration ------------------------*/
      /* In case of Alternate function mode selection */
      if((GPIO_Init->Mode == GPIO_MODE_AF_PP) || (GPIO_Init->Mode == GPIO_MODE_AF_OD))
      {
        /* Configure Alternate function mapped with the current IO */
        temp = GPIOx->AFR[position >> 3];
        temp &= ~((uint32_t)0xF << ((uint32_t)(position & (uint32_t)0x07) * 4)) ;
        temp |= ((uint32_t)(GPIO_Init->Alternate) << (((uint32_t)position & (uint32_t)0x07) * 4));
        GPIOx->AFR[position >> 3] = temp;
      }

      /* Configure IO Direction mode (Input, Output, Alternate or Analog) */
      temp = GPIOx->MODER;
      temp &= ~(GPIO_MODER_MODER0 << (position * 2));
      temp |= ((GPIO_Init->Mode & GPIO_MODE) << (position * 2));
      GPIOx->MODER = temp;

      /* In case of Output or Alternate function mode selection */
      if((GPIO_Init->Mode == GPIO_MODE_OUTPUT_PP) || (GPIO_Init->Mode == GPIO_MODE_AF_PP) ||
         (GPIO_Init->Mode == GPIO_MODE_OUTPUT_OD) || (GPIO_Init->Mode == GPIO_MODE_AF_OD))
      {
        /* Configure the IO Speed */
        temp = GPIOx->OSPEEDR;
        temp &= ~(GPIO_OSPEEDER_OSPEEDR0 << (position * 2));
        temp |= (GPIO_Init->Speed << (position * 2));
        GPIOx->OSPEEDR = temp;

        /* Configure the IO Output Type */
        temp = GPIOx->OTYPER;
        temp &= ~(GPIO_OTYPER_OT_0 << position) ;
        temp |= (((GPIO_Init->Mode & GPIO_OUTPUT_TYPE) >> 4) << position);
        GPIOx->OTYPER = temp;
      }

      /* Activate the Pull-up or Pull down resistor for the current IO */
      temp = GPIOx->PUPDR;
      temp &= ~(GPIO_PUPDR_PUPDR0 << (position * 2));
      temp |= ((GPIO_Init->Pull) << (position * 2));
      GPIOx->PUPDR = temp;
    }
  }
}

static bool _gpio_initialized = false;

void GPIO_init()
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = GREEN_LED;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = RED_LED;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

    HAL_GPIO_WritePin(GPIOJ, RED_LED, GPIO_PIN_RESET);

    _gpio_initialized = true;
}

void green_led_switch_on()
{
    if (!_gpio_initialized)
        GPIO_init();

    HAL_GPIO_WritePin(GPIOJ, GREEN_LED, GPIO_PIN_SET);
}

void green_led_switch_off()
{
    if (!_gpio_initialized)
        GPIO_init();

    HAL_GPIO_WritePin(GPIOJ, GREEN_LED, GPIO_PIN_RESET);
}
