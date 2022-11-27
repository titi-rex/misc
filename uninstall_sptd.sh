#!/bin/bash
brew uninstall spotifyd
rm -rf ~/.config/spotifyd
security delete-generic-password -s spotifyd
exit
