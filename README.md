# kinesis-advantage-2
## Sane layouts for the THE KINESIS KEYBOARD

*The sane layout for insane world. Ukraine 🇺🇦 is being attacked and destroyed by terrorist state of russia. Help 🇺🇦Ukraine🇺🇦! Defend the World from russian fascism!*

Kinesis Advantage2 is the state-of-the-art ergonomic keyboard with sofisticated configuration setup.

This setup here is

* qwerty-based
* simple (as in two main layers only)
* MacOS specific (e.g. COPY/INSERT, language switching, virtual desktops switching etc)
* customized instead of being universal
* symmetrical where possible
* heavy relies on home row keys modifiers
* ~~autodocumented (in sense it should be easy enough to get what's inside the layout using sources)~~ we're not there yet
* intended to transform the potential powers of the kinesis advantage 2 keyboard into the kinetic ones

![Somewhat outdated layout](https://github.com/vlnn/kinesis-advantage-2/blob/master/kinesis-advantage-tamed.png)

## Stapelberg mod keymap installation (QMK based)

This is general more functional variant, which **_requires_** [Stapelberg mod](https://michael.stapelberg.ch/posts/2013-03-21-kinesis_custom_controller/). This means hardware change of the controller of your Kinesis Advantage keyboard. In return you have all the features from QMK available (in my firmware mod keys set up on home row keys -- i.e. holding `F` or `J` is same as holding the `SHIFT` key -- which makes "usual" mod keys under pinky unnecessary). I don't think there is a feature in official firmware, which you can not set up using QMK -- except the warranty!

* clone [qmk_firmware](https://github.com/qmk/qmk_firmware) repo into `~/src` and follow its installation instructions
* clone [this repo](https://github.com/vlnn/kinesis-advantage-2) into `~/src`
* `cd ~/src/kinesis-advantage-2`
* `make compile`
* if no errors on previous step, `make flash` -- here you will have to use F9 and Esc keys on the very top row simultaneousely so the flasher could see and flash your keyboard.
* et voila

## General notes
You're more than welcome to make configs better sending me pull requests or creating issues. I'm more than free to ignore those requests, but will take a look.
