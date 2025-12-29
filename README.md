<div align="center">
  <img src="resources/logo/logo_350x350.png" alt="KeeBox Logo" width="180" height="180">
  <h1>KeeBox</h1>
</div>

KeeBox is a secure, open-source password manager built with C++ and Qt. It uses **SQLCipher** (AES-256) to ensure your data is always encrypted at rest.

## Features
- 🔒 **Strong Encryption**: Powered by SQLCipher 4.
- 💻 **Cross-Platform**: Built on Qt 6 for Linux, Windows, and macOS.
- 📂 **Local Storage**: Your passwords stay on your device.
- ⚡ **Native Performance**: Fast and resource-efficient.

## Installation

### RPM-based Linux (Fedora, RHEL, Rocky, AlmaLinux, openSUSE)

Download the latest RPM from [Releases](https://github.com/SBAI-Youness/KeeBox/releases) and install:

```bash
# Fedora, RHEL 8+, Rocky Linux, AlmaLinux
sudo dnf install ./keebox-*.rpm

# openSUSE
sudo zypper install ./keebox-*.rpm

# Older RHEL/CentOS
sudo yum localinstall ./keebox-*.rpm
```

### Build from Source

For development or other platforms:

```bash
# 1. Clone the repository
git clone https://github.com/SBAI-Youness/KeeBox.git
cd KeeBox

# 2. Create build directory
mkdir build && cd build

# 3. Compile
cmake ..
make -j$(nproc)

# 4. Run
./KeeBox
```

**Requirements:** C++17 compiler, CMake 3.16+, Qt 6, SQLCipher

## License
This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.
