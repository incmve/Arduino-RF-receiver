Arduino-RF-status-LED
=====================

This is a simple Arduino sketch to receive an kaku RF signal and glow an LED to show you the status.
This way when you send a on command the arduino also picks it up and lets a led fade in and out and glow.

```
Verwarming-LED-fade-blink.ino
Unit 66 ID 6 off = fade red
Unit 66 ID 6 on = fade blue
Unit 66 ID 7 off = blink red
Unit 66 ID 7 on = blink red/blue
Unit 66 ID 8 off = burn pink
unit 66 ID 8 on = burn green
unit 66 ID 9 off = LED off
unit 66 ID 9 on = burn green dim
```

```
Verwarming-LED-fade-blink-Dimmer.ino (not working yet)
Unit 66 ID 6 dimlevel 1 to xx
```
Here is an example: http://youtu.be/92gRuwptlOc
