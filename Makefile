.PHONY: configure
configure:
	pio init --ide vscode

.PHONY: format
format:
	find test/ src/ include/ -iname '*.h' -o -iname '*.c' | xargs clang-format -i

.PHONY: test
test:
	pio test -e native
