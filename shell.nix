# This file is used to build the nain and NeoPack packages for Nix.
# It is not intended to be used directly.

{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [pkgs.gcc];
}
