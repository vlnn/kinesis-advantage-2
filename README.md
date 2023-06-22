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

## Main features I rely on in everyday life

- **Switching the languages with two separate buttons**. Map `F13` and `F14` somewhere (I chose to use the thumb cluster), add custom rule to the Karabiner-elements as [this great article describes](https://solovyov.net/blog/2020/karabiner-hotkeys/), and you'll never type 'руддщ' instead of 'hello' again!
- **Using home row mods as a main mod driver**. The main idea is that you never move your fingers far away from the home row, even if you need to use good old `OPTION`, `CTRL`, `COMMAND` or `SHIFT`. E.g. if you press the button `F` and keep pressing it, instead typing long line of `f` characters your keyboard will emit Shift key. `F` and `J` are new `SHIFT`s (you may use usual "pinky shifts" if you want to in addition), `D` and `K` are new `COMMAND` keys, `D` and `L` are new `CTRL`s, and `F` and `H` are new `SHIFT`s. Read more [here](https://precondition.github.io/home-row-mods)
- **Switching Virtual Desktops with one button**. I don't use `F1`-`F12` buttons during my normal work, so I'm reusing them slightly (don't be afraid, you can still access them, they are on the second layer). Most beneficial usage of this special row is mapping `F1`, `F2`, `F3` and `F4` to macOS virtual desktops. Thus you press `F1` and big fat browser is on the screen. Then you want to listen to the Spotify and press `F4` -- Spotify is always on the fourth desktop in my setup, playing music and not interrupting the Browser. Fancy to work? Press `F2` and there you have your IDE open with all the terminals on the side.
- **`HYPER` Key is where your `CAPS` key was. It's also `ESC`!** Read more [here](https://www.reddit.com/r/olkb/comments/7h0pe3/purpose_of_hyper_in_qmk/)

## Stapelberg mod keymap installation (QMK based)

This firmware **_requires_** [Stapelberg mod](https://michael.stapelberg.ch/posts/2013-03-21-kinesis_custom_controller/). It's **NOT COMPATIBLE WITH UNMODIFIED KINESIS ADVANTAGE!**. This means hardware change of the controller of your Kinesis Advantage keyboard is needed. In return you have all the features from QMK available. I don't think there is a feature in official firmware, which you can not set up using QMK -- except the warranty!

### Installation

* clone [qmk_firmware](https://github.com/qmk/qmk_firmware) repo into `~/src` and follow its installation instructions
* clone [this repo](https://github.com/vlnn/kinesis-advantage-2) into `~/src`
* `cd ~/src/kinesis-advantage-2`
* `make compile`
* if no errors on previous step, `make flash` -- here you will have to use F9 and Esc keys on the very top row simultaneousely so the flasher could see and flash your keyboard.
* et voila

## General notes
You're more than welcome to make configs better sending me pull requests or creating issues. I'm more than free to ignore those requests, but will take a look.
