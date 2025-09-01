#ifndef INC_BTN_H_
#define INC_BTN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "pin.h"

typedef struct {
	const pin_t pin;
	bool previous_state;
} btn_t;

static inline bool is_btn_pressed(const btn_t *btn)
{
	assert_param(btn != NULL);
	return (read_pin(&btn->pin)) == GPIO_PIN_RESET ? true : false;
}

static inline void update_btn_state(btn_t *btn, bool state)
{
	assert_param(btn != NULL);
	btn->previous_state = state;
}

static inline void handle_btn_press(btn_t *btn, void (*callback)(void *), void *ctx)
{
	assert_param(btn != NULL && callback != NULL && ctx != NULL);

	bool pressed = is_btn_pressed(btn);

	if (pressed && btn->previous_state == false)
	{
		callback(ctx);
	}

	update_btn_state(btn, pressed);
}

#ifdef __cplusplus
}
#endif

#endif /* INC_BTN_H_ */
