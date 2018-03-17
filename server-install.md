Server Install Guide

Merciless 2 V3.4+ Installation Guide

Before starting insure that you have downloaded the zip and it contains the following files:

[filename].iwd (cilent side mod)
[filename_svr_].iwd (server side mod)
merc2ded.cfg (Merciless Mod 2 Main Dedicated CFG file)


The follow are not needed within the game folder to run Merciless:
Any files ending with .txt and or .rtf

Create folder "mymerciless" (you can change the name to whatever) in Call of Duty 2
Add the following files to the folder:

1. Both client and server IWD files
2. merc2ded.cfg

If you wish to enable PunkBuster

sv_punkbuster "1"
pb_sv_enable
exec pbsv.cfg (remove double slashes in cfg)

Executing the game via desktop shortcut
Create a shortcut to your "CoD2MP_s.exe"
add "+set fs_game mymerciless +exec merc2ded.cfg" to your target line

"C:\Program Files\Activision\Call of Duty 2\CoD2MP_s.exe" +set dedicated 2 +set net_ip  xx.xxx.xxx.xxx +set net_port 28960 +set fs_game mymerciless +exec merc2ded.cfg +set sv_punkbuster 0 +map_rotate
(replace X's with your public IP address not local one)
Local IP should be 10.0.0.x (don't put it down)

Linux: start your server with "./cod2_lnxded +set fs_game mymerciless +exec merc2ded.cfg"

Please note that merc2ded.cfg has been heavly modified from V3.3
Use the supplied cfg file with your zip.

Open these ports via router/gateway if game will not broacast server:
TDP 28960
UDP 20500, 20510, 28960 to 28970 (including 28961 ect.) 

If you get the following errors your ports are not open:
(X's are your computers public IP address)

Opening IP socket: xx.xxx.xxx.xxx:28960 
WARNING: UDP_OpenSocket: bind: WSAEADDRNOTAVAIL
Opening IP socket: xx.xxx.xxx.xxx:28961
