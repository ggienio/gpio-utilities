# GPIO Utilities for STM32

This project provides simple GPIO utility functions and structures for STM32 microcontrollers, for polling-driven button and pin handling. It is written in C, works with C++ projects, uses the STM32 HAL library, and has been tested on the STM32F303RET6.

## Features

- Simple abstractions for GPIO pins and buttons
- Inline functions
- Button press handling using polling with callback support

## Usage

### pin.h

Defining a pin:
```c
const pin_t LD2 = {LD2_GPIO_Port, LD2_Pin};
```
Writing to a pin:
```c
write_pin(&LD2, GPIO_PIN_SET);
```
```c
write_pin(&LD2, GPIO_PIN_RESET);

```
Toggling a pin:
```c
toggle_pin(&LD2);
```
Reading from a pin:
```c
GPIO_PinState state = read_pin(&LD2);

if (state == GPIO_PIN_SET)
{
    // do stuff...
}
```

### btn.h

Defining a button:
```c
btn_t user_btn = {
		{USER_BTN_GPIO_Port, USER_BTN_Pin},
		false
};
```
Defining a callback function:
```c
void handle_user_btn(void *ctx)
{
	// do stuff...
}

```
Then, in the main event loop:
```c
handle_btn_press(&user_btn, handle_user_btn, NULL); // for callbacks without arguments
```
You can pass arguments to the callback function using the `void *ctx` parameter:
```c
void increment_counter(void *ctx)
{
	int *counter = (int *)ctx;
    ++(*counter);
}

// ...

int counter = 0;

while (1)
{
    handle_btn_press(&user_btn, increment_counter, &counter);
    // ...
}
```