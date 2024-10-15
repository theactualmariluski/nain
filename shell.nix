# This file is used to build the nain and NeoPack packages for Nix.
# It is not intended to be used directly.

{ stdenv, fetchFromGitHub, rustPlatform, pkgconfig, openssl, ncurses, git, cmake }:

rustPlatform.buildRustPackage rec {
  name = "Nain-${version}";
  version = "0.1.0";

  src = fetchFromGitHub {
    owner = "theactualmariluski";
    repo = "nain";
    rev = "v${version}";
  }
}