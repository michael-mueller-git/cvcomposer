{
  inputs = {
    nixpkgs = {
      url = "github:nixos/nixpkgs/nixos-unstable";
    };
    flake-utils = {
      url = "github:numtide/flake-utils";
    };
  };
  outputs = { nixpkgs, flake-utils, ... }: flake-utils.lib.eachDefaultSystem (system:
    let
      pkgs = import nixpkgs {
        inherit system;
      };
      cvcomposer = (with pkgs; stdenv.mkDerivation {
          pname = "cvcomposer";
          version = "1.3.1";
          src = fetchgit {
            url = "https://github.com/michael-mueller-git/cvcomposer.git";
            rev = "774388876aedc4b00afaebae6a8477710599d7d5";
            sha256 = "sha256-067V0XolutU9UfSXaWd9jbu3WgqUPUBDMtQWWlOVxnM=";
            fetchSubmodules = true;
          };
          nativeBuildInputs = [
            clang
            cmake
            qt6.full
            opencv
          ];
          buildPhase = "cmake . && make -j $NIX_BUILD_CORES";
          installPhase = ''
            mkdir -p $out/bin
            mv cvcomposer $out/bin
          '';
        }
      );
    in rec {
      defaultApp = flake-utils.lib.mkApp {
        drv = defaultPackage;
      };
      defaultPackage = cvcomposer;
      devShell = pkgs.mkShell {
        buildInputs = [
          cvcomposer
          pkgs.qt6.full
          pkgs.opencv
        ];
      };
    }
  );
}
