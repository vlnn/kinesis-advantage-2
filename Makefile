##
# Compile and flash the keymap as a QMK external userspace
#

.DEFAULT_GOAL := help
KEYBOARD := kinesis/stapelberg
KEYMAP := vlnn
export QMK_HOME ?= $(HOME)/src/open/qmk_firmware
export QMK_USERSPACE := $(CURDIR)

compile: ## Compile the 'vlnn' keymap into the firmware of hex format
	qmk compile -kb $(KEYBOARD) -km $(KEYMAP)
	@echo "Look for the latest firmware:"
	ls ./*_$(KEYMAP).hex
# end

flash: ## Flash the 'vlnn' keymap: you will need to reset the keyboard
	@echo "ACTION NEEDED: PRESS RESET COMBINATION (F9+ESC by default)"
	qmk flash -kb $(KEYBOARD) -km $(KEYMAP)
# end

help:   ## Show short help for every available make target
	@echo "\033[1mAvailable make commands with descriptions:"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[1m\033[32mmake %-30s\033[0m %s\n", $$1, $$2}'
	@echo "For more specific info check https://github.com/vlnn/kinesis-advantage-2"
