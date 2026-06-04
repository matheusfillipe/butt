# BUTT (fork) — long broadcaster password support

A fork of [BUTT (Broadcast Using This Tool)](https://danielnoethen.de/butt/) 1.46.0
with a single patch: the server **password** field no longer truncates at 100
characters.

## Why

Upstream caps the password input widget at 100 characters
(`input_add_srv_pwd->maximum_size(100)`). Streaming servers that authenticate
with long credentials — e.g. JWT livestream tokens, which run ~300 characters —
get silently truncated to the first 100 chars before BUTT sends them. The server
then rejects the broadcast with `invalid user/password`, even though the pasted
token is correct.

The credential is stored dynamically (`realloc`/`strlen`), so only the GUI input
widget imposed the limit.

## The patch

`src/FLTK/flgui.fl` and the generated `src/FLTK/flgui.cpp`:

```
-this->input_add_srv_pwd->maximum_size(100);
+this->input_add_srv_pwd->maximum_size(8192);
```

All other fields keep their upstream limits.

## Building

See `INSTALL`. On macOS with Homebrew:

```
brew install fltk portaudio lame libvorbis libogg flac opus libsamplerate fdk-aac openssl@3 portmidi pkg-config automake autoconf
./configure && make
```

Upstream is GPL-2.0; see `COPYING`.
