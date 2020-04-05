# kinesis-advantage-2
## Sane layouts for the THE KINESIS KEYBOARD

Kinesis Advantage2 is the state-of-the-art ergonomic keyboard with sofisticated configuration setup.

This setup here is

* qwerty-based
* simple
* customized instead of being universal
* symmetrical where possible
* autodocumented
* intended to transform the potential powers of the kinesis advantage 2 keyboard into the kinetic ones

![Somewhat outdated layout](https://github.com/vlnn/kinesis-advantage-2/blob/master/kinesis-advantage-tamed.png)

## Official (no mod) keymap installation

* update the keyboard firmware to 1.0.516 as described here: https://kinesis-ergo.com/support/advantage2/
* get to power-user mode pressing progm+shift+esc
* mount and open the folder with configs pressing progm+F1
* copy the configs over the existing ones
* press progm+F1 once again to unmount the config folder and apply the new configuration

## Stapelberg mod keymap installation

This is general more functional variant.

    * install qmk_firmware
    * create new directory inside qmk_firmware/keyboards/kinesis/keymaps/{your_directory}
    * copy files from qmk directory there
    * make kinesis/stapelberg:{your_directory}
    * the firmware called kinesis_stapelberg_{your_directory} can be installed to your keyboard using teensy or qmk_toolset

## General notes
You're more than welcome to make configs better sending me pull requests or creating issues. I'm more than free to ignore those requests.
