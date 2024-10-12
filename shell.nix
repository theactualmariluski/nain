{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.gcc            # For compiling C code
    pkgs.python3       # Python 3 interpreter
    pkgs.dialog         # For using dialog
    pkgs.make           # For using Makefile
    pkgs.git            # For version control
    pkgs.toml          # TOML file support
  ];

  shellHook = ''
    echo "Welcome to the development shell for your project!"
    echo "You can build and run your application using the following commands:"
    echo "  make             # To build the project"
    echo "  python3 pkgs/dialog.py # To run the Python dialog script"
  '';
}
