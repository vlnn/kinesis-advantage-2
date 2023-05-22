# kinesis-advantage-2
## Sane layouts for the THE KINESIS KEYBOARD

Kinesis Advantage2 is the state-of-the-art ergonomic keyboard with sofisticated configuration setup.

This setup here is

* MacOS specific (e.g. COPY/INSERT, language switching etc)
* qwerty-based
* simple
* customized instead of being universal
* symmetrical where possible
* autodocumented (in sense it should be easy enough to get what's inside the layout using sources)
* intended to transform the potential powers of the kinesis advantage 2 keyboard into the kinetic ones

![Somewhat outdated layout](https://github.com/vlnn/kinesis-advantage-2/blob/master/kinesis-advantage-tamed.png)

## Stapelberg mod keymap installation (QMK based)

This is general more functional variant, which **_requires_** [Stapelberg mod](https://michael.stapelberg.ch/posts/2013-03-21-kinesis_custom_controller/). This means hardware change of the controller of your Kinesis Advantage keyboard. In return you have all the features from QMK available (in my firmware mod keys set up on home row keys -- i.e. holding `F` or `J` is same as holding the `SHIFT` key -- which makes "usual" mod keys under pinky unnecessary). I don't think there is a feature in official firmware, which you can not set up using QMK -- except the warranty!

* clone [qmk_firmware](https://github.com/qmk/qmk_firmware) repo into `~/src` and follow its installation instructions
* clone [this repo](https://github.com/vlnn/kinesis-advantage-2) into `~/src`
* `cd ~/src/kinesis-advantage-2`
* `make compile`
* if no errors on previous step, `make flash` -- here you will have to use "RESET" key so the flasher could see your keyboard
* et voila

## Official harware (no mod) keymap installation
#### Note that it's outdated and misses some features that "Stapelberg" version has
#### This also means that official setup is no longer maintained and is planned to be removed
* update the keyboard firmware to **1.0.516** as described here: https://kinesis-ergo.com/support/advantage2/
* get to power-user mode pressing *progm+shift+esc*
* mount and open the folder with configs pressing *progm+F1*
* copy the configs from `official` over the existing ones
* press *progm+F1* once again to unmount the `config` folder of the internal drive and apply the new configuration

## General notes
You're more than welcome to make configs better sending me pull requests or creating issues. I'm more than free to ignore those requests, but will take a look.
