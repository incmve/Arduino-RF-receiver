Arduino-RF-status-LED
=====================

Here are some simple Arduino sketches to receive a kaku RF signal and perform some functions.

* arduin-rf-relay.ino switch on/off a relay, active low. If you need it to be active High remove <code>digitalWrite(RELAY1, HIGH);</code>

* receive-fadein-fadeout.ino when receiving a on signal it will fade a led in/out and glow at the end, I use this to give visual feedback when a device is switched on.

* 
