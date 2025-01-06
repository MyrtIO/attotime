.PHONY: configure
configure:
	pio init --ide vscode

.PHONY: format
format:
	find test/ src/ lib/ -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i

.PHONY: test-uno
test-uno:
	pio test -vvv -e uno --without-uploading

.PHONY: test-native
test-native:
	pio test -e native

.PHONY: test
test:
	make test-native
	make test-uno

