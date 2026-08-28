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

            buildInputs = with pkgs; [
              nil
              nixd
            ];
          };
        };
        checks = {
          formatting = treefmtconfig.config.build.check self;
        };
      }
    );
}
