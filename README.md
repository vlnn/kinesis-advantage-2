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

* clone [qmk_firmware](https://github.com/qmk/qmk_firmware) repo
* create new directory inside `qmk_firmware/keyboards/kinesis/keymaps/{your_directory}`
* copy files from `qmk` directory there
* `make kinesis/stapelberg:{your_directory}` from `qmk_firmware` root directory
* the firmware called `kinesis_stapelberg_{your_directory}` can be installed to your keyboard using [**teensy**](https://www.pjrc.com/teensy/loader_linux.html) or [**qmk_toolbox**](https://qmk.fm/toolbox/)


## Official harware (no mod) keymap installation
#### Note that it's outdated and misses some features that "Stapelberg" version has
#### This also means that official setup is no longer maintained
* update the keyboard firmware to **1.0.516** as described here: https://kinesis-ergo.com/support/advantage2/
* get to power-user mode pressing *progm+shift+esc*
* mount and open the folder with configs pressing *progm+F1*
* copy the configs from `official` over the existing ones
* press *progm+F1* once again to unmount the `config` folder of the internal drive and apply the new configuration

## General notes
You're more than welcome to make configs better sending me pull requests or creating issues. I'm more than free to ignore those requests, but will take a look.
