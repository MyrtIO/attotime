.PHONY: configure
configure:
	pio init --ide vscode

.PHONY: format
format:
	find test/ src/ lib/ -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i

.PHONY: test
test:
	pio test -e native

.PHONY: test-avr
test-avr:
	pio test --without-uploading -e uno
