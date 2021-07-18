Quick notes for building:

- Use Ubuntu 20.04 x64
- Generate ACPI tables with IASL
- Follow this quick draft

# Mono
apt-get install gnupg ca-certificates
apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 3FA7E0328081BFF6A14DA29AA6A19B38D3D831EF
echo "deb https://download.mono-project.com/repo/ubuntu stable-focal main" | sudo tee /etc/apt/sources.list.d/mono-official-stable.list
apt-get update
apt-get install mono-devel

# Host utilities
apt-get install python3 python3-venv python3-pip
apt-get install python
apt-get install git-core git
apt-get install build-essential

# PowerShell
# Import the public repository GPG keys
curl https://packages.microsoft.com/keys/microsoft.asc | apt-key add -

# Register the Microsoft Ubuntu repository
curl https://packages.microsoft.com/config/ubuntu/20.04/prod.list | tee /etc/apt/sources.list.d/microsoft.list

# Update the list of products
apt-get update

# Install PowerShell
apt-get install -y powershell

# Linaro Toolchains
cd /opt
wget http://releases.linaro.org/components/toolchain/binaries/7.5-2019.12/aarch64-elf/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-elf.tar.xz
tar xf gcc-linaro-7.5.0-2019.12-x86_64_aarch64-elf.tar.xz
sudo update-alternatives --install /usr/bin/gcc gcc /opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-elf/bin/aarch64-elf-gcc 70
sudo update-alternatives --install /usr/bin/gcc-ar gcc-ar /opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-elf/bin/aarch64-elf-gcc-ar 70

# Activate Workspace
python3 -m venv Lumia950Xl
source Lumia950Xl/bin/activate

# Build UEFI
pip install --upgrade -r pip-requirements.txt
stuart_setup -c Platforms/Lumia950XLPkg/PlatformBuild.py TOOL_CHAIN_TAG=GCC5
stuart_update -c Platforms/Lumia950XLPkg/PlatformBuild.py TOOL_CHAIN_TAG=GCC5
stuart_build -c Platforms/Lumia950XLPkg/PlatformBuild.py TOOL_CHAIN_TAG=GCC5

# Generate ELF image
pwsh
$env:PATH = "/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-elf/bin:/opt/gcc-linaro-7.5.0-2019.12-x86_64_arm-eabi/bin:$($env:PATH)"
Import-Module ./Tools/PsModules/redirector.psm1
Import-Module ./Tools/PsModules/elf.psm1
Copy-ElfImages