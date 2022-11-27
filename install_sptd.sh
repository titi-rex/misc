#!/bin/bash
brew install spotifyd
mkdir -p ~/.config/spotifyd
echo "Prompt your Spotify username :"
read USERNAME_SPT
LOGIN_NAME=$(whoami)
 `echo "[global]
# Fill this in with your Spotify login.
username = \"$USERNAME_SPT\"

# You'll be using the macOS keychain to specify your password.
use_keyring = true

# How this machine shows up in Spotify Connect.
device_name = \"spotifyd\"
device_type = \"computer\"

# This is the default location of Spotify's cache, so just replace LOGIN_NAME
# with your macOS login name (type \`whoami\` at a Terminal window).
cache_path = \"/Users/$LOGIN_NAME/Library/Application Support/Spotify/PersistentCache/Storage\"
no_audio_cache = false

# Various playback options. Tweak these if Spotify is too quiet.
bitrate = 320
volume_normalisation = true
normalisation_pregain = -10

# These need to be set, but don't need to be changed.
backend = \"rodio\"
mixer = \"PCM\"
volume_controller = \"softvol\"
zeroconf_port = 1234" >  ~/.config/spotifyd/spotifyd.conf`
echo "Authetification via Keychain Access app"
echo "Prompt your Spotify password :"
read USER_PASSWD
security add-generic-password -s spotifyd -D rust-keyring -a $USERNAME_SPT -w $USER_PASSWD
spotifyd --no-daemon
brew services restart spotifyd
exit
