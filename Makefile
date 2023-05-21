##
# Deploy and compile the keymap via qmk_firmware environment
#

.DEFAULT_GOAL := help
QMKDIR :=  ~/src/qmk_firmware
QMKPATH := keyboards/kinesis/keymaps

compile: ## Deploy the 'vlnn' keymap top qmk_firmware repo and compile it into the firmware of hex format
	@echo "Deploying the \'vlnn\' keymap into $(QMKDIR):"
	rsync -arupE vlnn $(QMKDIR)/$(QMKPATH)
	@echo "Compiling the keymap into the firmware"
	cd $(QMKDIR) && make kinesis/stapelberg:vlnn
	@echo "Copying all the firmwares to active directory for backup"
	rsync -arupE $(QMKDIR)/*_vlnn.hex ./
	@echo "Look for the latest firmware:"
	ls ./*_vlnn.hex
# end

flash: ## Flash the \'vlnn\' keymap: you will need to reset the keyboard
	@echo "ACTION NEEDED: PRESS RESET COMBINATION (F9+ESC by default)"
	cd $(QMKDIR) && qmk flash -kb kinesis/stapelberg -km vlnn
# end

help:   ## Show short help for every available make target
	@echo "\033[1mAvailable make commands with descriptions:"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[1m\033[32mmake %-30s\033[0m %s\n", $$1, $$2}'
	@echo "For more specific info check https://github.com/vlnn/README.md"
