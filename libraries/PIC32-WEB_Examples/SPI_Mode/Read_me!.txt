To run "PIC32-WEB_SPI_Demo" on Olimex's "PIC32-WEB" board is required:
1. Program "PIC32-WEB" on-board microcontroller "PIC32MX460F512L-80I/PT" with "PIC32-WEB_SPI_Demo.hex"
2. Remove "PIC32-WEB" power supply and insert "MOD-ENC624J600" board into corresponding EXT1 and ExT2 connectors.
   Then connect "MOD-ENC624J600's" UEXT and "PIC32-WEB's" UEXT connectors via cable.
3. Check and make sure that all "MOD-ENC624J600" and "PIC32-WEB" jumper are set to be in SPI Mode.
   Correct jumpers positions are shown in "PIC32-WEB" schematic. (See the drawn table, column  "Connected to SPI2" )
4. Connect LAN cable into "MOD-ENC624J600" LAN connector.
5. Make physical connection between your computer and "PIC32-WEB's" RS232 connector, open terminal and set it to:
	115200 bits/sec, 8 data bits, No Parity, 1 Stop Bit
6. Insert again Power Supply into "PIC32-WEB's" power jack and you have to see on terminal

	***************************************************
	**** Welcom to OLIMEX PIC32-WEB Demo program! *****
	***************************************************
	         ------ -------- ----------
	        | LED  | Status | Emoticon |
	         ------ -------- ----------
	        | LED1 |   OFF  |  :(     |
	        | LED2 |   OFF  |  :(     |
	        | LED3 |   OFF  |  :(     |
	         ------ -------- ----------

7. Load "PIC32-WEB's" demo web page like just open your web browser and type "http://pic32-web/". Default IP addres is: 192.168.0.77
8. Enjoy "PIC32-WEB" demo!
