# This is the Makefile for the Nain project
.all: install

install:
    @echo "Installing Nain..."
	gcc -o src/nain nain.c
	cp nain $HOME/.local/bin/nain
	@echo "The nain compiler has been installed!"
	@echo "Two more things are needed to install the Nain Hub..."
	@echo "Installing the Nain Hub..."
	cp ./hub/hub.sh $HOME/.local/bin/nain-hub
	@echo "The Nain Hub has been installed!"
	@echo "Install basic libraries (math, iostream, etc.)?"
	@echo "(y)es or (n)o"
	read
	if [ $REPLY == "y" ]; then
		curl -s https://npack.nain.dev/api/basiclibs
		cp basiclibs $HOME/.local/nainlibs/
	else
		@echo "Got it. Nain was installed sucessfully!"
	fi

		