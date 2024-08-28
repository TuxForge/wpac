# WPac - Windows Package Manager Wrapper

WPac is a command-line tool that provides a zypper/pkg-like syntax for the Windows Package Manager (winget) written purely in C. It simplifies software package management on Windows by offering both shorthand and full syntax options for winget commands, making it easier for users to install, uninstall, upgrade, search for, and manage software packages.

## Features

- Shorthand and full syntax support for common `winget` commands
- Easy-to-use interface for Windows package management
- Supports all major `winget` operations

## Installation

1. Clone this repository:
   ```sh
   git clone https://github.com/Gur0v/wpac.git
   cd wpac
   ```
2. Compile the C using MinGW:
   ```sh
   gcc -o wpac.exe wpac.c
   ```
3. Add the directory containing the `wpac` executable to your system's PATH.

## Usage

WPac supports both shorthand and full syntax for various `winget` commands. Here are some examples:

```
wpac in <package>    # Install a package
wpac rm <package>    # Uninstall a package
wpac ug              # Upgrade all packages
wpac se <query>      # Search for packages
wpac ls              # List installed packages
```

### Supported Commands

| Shorthand | Full Command | Description |
|-----------|--------------|-------------|
| in        | install      | Install a package |
| sw        | show         | Show package information |
| src       | source       | Manage sources |
| se        | search       | Search for packages |
| ls        | list         | List installed packages |
| up        | upgrade      | Upgrade a specific package |
| ug        | -            | Upgrade all packages including unknown versions |
| rm        | uninstall    | Uninstall a package |
| ha        | hash         | Generate hash for installer |
| val       | validate     | Validate a manifest |
| st        | settings     | Open settings |
| ft        | features     | Show available features |
| ex        | export       | Export installed packages |
| im        | import       | Import packages |
| pi        | pin          | Manage package pins |
| cfg       | configure    | Configure system |
| dw        | download     | Download a package |
| rp        | repair       | Repair a package |

## Examples

1. Install a package:
   ```sh
   wpac in Mozilla.Firefox
   ```

2. Search for a package:
   ```sh
   wpac se "visual studio code"
   ```

3. Upgrade all packages:
   ```sh
   wpac ug
   ```

4. Uninstall a package:
   ```sh
   wpac rm Microsoft.Skype
   ```

## License

This project is licensed under the GNU General Public License - see the [LICENSE](https://raw.githubusercontent.com/Gur0v/wpac/main/LICENSE) file for details.

## Acknowledgments

- This project is a wrapper around Microsoft's `winget` tool.
- This project was initially made for personal use, I know that it is really simple.
