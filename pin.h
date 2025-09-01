#ifndef INC_PIN_H_
#define INC_PIN_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t pin_num;
} pin_t;

static inline void write_pin(const pin_t *pin, GPIO_PinState state)
{
	assert_param(pin != NULL);
	HAL_GPIO_WritePin(pin->port, pin->pin_num, state);
}

static inline GPIO_PinState read_pin(const pin_t *pin)
{
	assert_param(pin != NULL);
	return HAL_GPIO_ReadPin(pin->port, pin->pin_num);
}

static inline void toggle_pin(const pin_t *pin)
{
	assert_param(pin != NULL);
	HAL_GPIO_TogglePin(pin->port, pin->pin_num);
}

#ifdef __cplusplus
}
#endif

#endif /* INC_PIN_H_ */
