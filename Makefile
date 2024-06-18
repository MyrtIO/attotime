.PHONY: configure
configure:
	pio init --ide vscode

.PHONY: format
format:
	find test/ src/ -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i

.PHONY: test
test:
	pio test --without-uploading -e uno
