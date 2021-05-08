# LEDgame
working on a led game for a friend
The led's are conected from pin 9-13.
The button is conected to pin 8 and pulled LOW by defalt.

Lines 23-39 count the led's UP. and checks the button each time.
Lines 40-55 count DOWN the led's and checks if te button is pressed.

Only function leds cycles through the array shutting off all pins, unless the up or down counter sets that pin HIGH.
