# Identity Thief Fighter (itf) cli and service program.
- Detects and applies cyber warfare to thieves using your name.
- Reduces suffering in your inner space.

## Pre-requisites
- A C++ compiler and build stack.
- Could be g++ or clang++, the 2 I have tried.
- The make utility
- a Linux operated computer or the Windows Subsystem for Linux (WSL)

## Building
- open the Linux terminal or bash terminal
- type: git clone https://github.com/refgift/itf.git
- cd itf
- type: make
- if the make succeeds, then type: ./itf and it will run.

## Installing
- cd itf
- type: make deploy
- It will ask for your password
- It will copy itf to /usr/sbin
- It will copy itf.service to /etc/systemd/system

## Check Status
type: systemctl status itf



