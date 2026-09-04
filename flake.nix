{
  description = "Markdown formatting checks";

  inputs = {
    flake-utils.url = "github:numtide/flake-utils";
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    treefmt-nix.url = "github:numtide/treefmt-nix";
  };

  outputs =
    { self, ... }@inputs:
    inputs.flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import inputs.nixpkgs { inherit system; };
        pkgs-treefmt = (import inputs.nixpkgs) {
          inherit system;
        };
        treefmtconfig = inputs.treefmt-nix.lib.evalModule pkgs-treefmt {
          projectRootFile = "flake.nix";
          programs = {
            mdformat = {
              enable = true;
              plugins = ps: [
                ps.mdformat-gfm
                ps.mdformat-frontmatter
              ];
              settings = {
                wrap = 88;
                end-of-line = "lf";
              };
            };
            shellcheck.enable = true;
            shfmt.enable = true;
            nixfmt.enable = true;
          };
          settings.formatter.shellcheck.excludes = [
            ".envrc"
          ];
        };
      in
      {
        formatter = treefmtconfig.config.build.wrapper;
        devShells = {
          default = pkgs.mkShell {
            name = "markdown-shell";

            packages = with pkgs; [
              arduino
            ];

            buildInputs = with pkgs; [
              nil
              nixd
              platformio
              gcc-arm-embedded
            ];

            shellHook = ''
              # Direct PlatformIO to download packages locally
              export PLATFORMIO_CORE_DIR="$PWD/.pio/core"
              # Install ESP32 platform & toolchains locally if missing
              if [ ! -d "$PLATFORMIO_CORE_DIR/packages" ]; then
                  echo "Installing ESP32 packages into .pio/core..."
                  pio pkg install
              fi
            '';
          };
        };
        checks = {
          formatting = treefmtconfig.config.build.check self;
        };
      }
    );
}
