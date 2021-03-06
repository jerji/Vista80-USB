EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR0101
U 1 1 5EFD1023
P 5200 4800
F 0 "#PWR0101" H 5200 4550 50  0001 C CNN
F 1 "GND" H 5205 4627 50  0000 C CNN
F 2 "" H 5200 4800 50  0001 C CNN
F 3 "" H 5200 4800 50  0001 C CNN
	1    5200 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal X1
U 1 1 5EFD1CFD
P 3800 3000
F 0 "X1" V 3754 2869 50  0000 R CNN
F 1 "12Mhz" V 3845 2869 50  0000 R CNN
F 2 "Crystal:Crystal_HC18-U_Vertical" H 3800 3000 50  0001 C CNN
F 3 "~" H 3800 3000 50  0001 C CNN
	1    3800 3000
	0    -1   1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 5EFD5F0E
P 3350 3450
F 0 "C1" H 3235 3496 50  0000 R CNN
F 1 "27pF" H 3235 3405 50  0000 R CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W2.5mm_P5.00mm" H 3388 3300 50  0001 C CNN
F 3 "~" H 3350 3450 50  0001 C CNN
	1    3350 3450
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5EFD70FB
P 3800 3450
F 0 "C2" H 3550 3500 50  0000 L CNN
F 1 "27pF" H 3500 3400 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W2.5mm_P5.00mm" H 3838 3300 50  0001 C CNN
F 3 "~" H 3800 3450 50  0001 C CNN
	1    3800 3450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3800 2800 3350 2800
Wire Wire Line
	3800 3300 3800 3200
Wire Wire Line
	3350 3600 3550 3600
$Comp
L power:GND #PWR0102
U 1 1 5EFD7D08
P 3550 3750
F 0 "#PWR0102" H 3550 3500 50  0001 C CNN
F 1 "GND" H 3555 3577 50  0000 C CNN
F 2 "" H 3550 3750 50  0001 C CNN
F 3 "" H 3550 3750 50  0001 C CNN
	1    3550 3750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3550 3750 3550 3600
Connection ~ 3550 3600
Wire Wire Line
	3550 3600 3800 3600
Wire Wire Line
	3800 3200 4050 3200
Wire Wire Line
	4050 3200 4050 3100
Wire Wire Line
	4050 3100 4600 3100
Connection ~ 3800 3200
Wire Wire Line
	3800 3200 3800 3150
Wire Wire Line
	3800 2800 3800 2850
Wire Wire Line
	4050 2800 3800 2800
Wire Wire Line
	4050 2800 4050 2900
Connection ~ 3800 2800
Wire Wire Line
	3350 2800 3350 3300
$Comp
L Connector_Generic:Conn_02x12_Counter_Clockwise J1
U 1 1 5EFE3E23
P 6600 1800
F 0 "J1" V 6604 2380 50  0000 L CNN
F 1 "CardEdge24" V 6695 2380 50  0000 L CNN
F 2 "CardEdge:DIP-24_200" H 6600 1800 50  0001 C CNN
F 3 "~" H 6600 1800 50  0001 C CNN
	1    6600 1800
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0107
U 1 1 5EFE7649
P 5200 2150
F 0 "#PWR0107" H 5200 2000 50  0001 C CNN
F 1 "+5V" H 5215 2323 50  0000 C CNN
F 2 "" H 5200 2150 50  0001 C CNN
F 3 "" H 5200 2150 50  0001 C CNN
	1    5200 2150
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATtiny:ATtiny4313-PU U1
U 1 1 5F001C82
P 5200 3500
F 0 "U1" H 4800 4700 50  0000 C CNN
F 1 "ATtiny4313-PU" H 4800 4600 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm" H 5200 3500 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc8246.pdf" H 5200 3500 50  0001 C CNN
	1    5200 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2900 4050 2900
Wire Wire Line
	5200 2400 5200 2150
Text Notes 2450 4750 0    50   ~ 0
Keyboard consumes ~190mA idle and ~210 when one key is pressed
$Comp
L Connector:USB_B J2
U 1 1 5F010E1E
P 8650 4600
F 0 "J2" H 8420 4589 50  0000 R CNN
F 1 "USB" H 8420 4498 50  0000 R CNN
F 2 "Connector_USB:USB_B_OST_USB-B1HSxx_Horizontal" H 8800 4550 50  0001 C CNN
F 3 " ~" H 8800 4550 50  0001 C CNN
	1    8650 4600
	-1   0    0    -1  
$EndComp
$Comp
L Device:D_Zener Z1
U 1 1 5F014224
P 7850 5050
F 0 "Z1" V 7800 4850 50  0000 L CNN
F 1 "3V6" V 7900 4800 50  0000 L CNN
F 2 "Diode_THT:D_5W_P12.70mm_Horizontal" H 7850 5050 50  0001 C CNN
F 3 "~" H 7850 5050 50  0001 C CNN
	1    7850 5050
	0    1    1    0   
$EndComp
$Comp
L Device:D_Zener Z2
U 1 1 5F01538A
P 8000 5050
F 0 "Z2" V 7954 5130 50  0000 L CNN
F 1 "3V6" V 8045 5130 50  0000 L CNN
F 2 "Diode_THT:D_5W_P12.70mm_Horizontal" H 8000 5050 50  0001 C CNN
F 3 "~" H 8000 5050 50  0001 C CNN
	1    8000 5050
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5F016E2E
P 7500 4600
F 0 "R2" V 7293 4600 50  0000 C CNN
F 1 "68R" V 7384 4600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 7430 4600 50  0001 C CNN
F 3 "~" H 7500 4600 50  0001 C CNN
	1    7500 4600
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 5F01980D
P 4400 2500
F 0 "R1" H 4331 2454 50  0000 R CNN
F 1 "4K7" H 4331 2545 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 4330 2500 50  0001 C CNN
F 3 "~" H 4400 2500 50  0001 C CNN
	1    4400 2500
	1    0    0    1   
$EndComp
Wire Wire Line
	8750 5000 8750 5500
Wire Wire Line
	8750 5500 8650 5500
Wire Wire Line
	8650 5000 8650 5500
Wire Wire Line
	4600 2700 4400 2700
Wire Wire Line
	4400 2700 4400 2650
$Comp
L power:+5V #PWR0108
U 1 1 5F021C34
P 4400 2150
F 0 "#PWR0108" H 4400 2000 50  0001 C CNN
F 1 "+5V" H 4415 2323 50  0000 C CNN
F 2 "" H 4400 2150 50  0001 C CNN
F 3 "" H 4400 2150 50  0001 C CNN
	1    4400 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2150 4400 2350
$Comp
L Device:CP1 C3
U 1 1 5F026B70
P 8500 3050
F 0 "C3" H 8615 3096 50  0000 L CNN
F 1 "10uF" H 8615 3005 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P2.00mm" H 8500 3050 50  0001 C CNN
F 3 "~" H 8500 3050 50  0001 C CNN
	1    8500 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C4
U 1 1 5F027E61
P 9000 3050
F 0 "C4" H 9115 3096 50  0000 L CNN
F 1 "0.1uF" H 9115 3005 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P2.00mm" H 9000 3050 50  0001 C CNN
F 3 "~" H 9000 3050 50  0001 C CNN
	1    9000 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5F02AB91
P 8500 3700
F 0 "#PWR0109" H 8500 3450 50  0001 C CNN
F 1 "GND" H 8505 3527 50  0000 C CNN
F 2 "" H 8500 3700 50  0001 C CNN
F 3 "" H 8500 3700 50  0001 C CNN
	1    8500 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 5F02B186
P 8500 2400
F 0 "#PWR0110" H 8500 2250 50  0001 C CNN
F 1 "+5V" H 8515 2573 50  0000 C CNN
F 2 "" H 8500 2400 50  0001 C CNN
F 3 "" H 8500 2400 50  0001 C CNN
	1    8500 2400
	1    0    0    -1  
$EndComp
Text GLabel 5900 3600 2    50   Input ~ 0
T1
Text GLabel 5900 3700 2    50   Input ~ 0
T2
Wire Wire Line
	5900 3600 5800 3600
Wire Wire Line
	5900 3700 5800 3700
$Comp
L Connector:AVR-ISP-6 J3
U 1 1 5F04ADE6
P 7850 3100
F 0 "J3" H 7520 3196 50  0000 R CNN
F 1 "ISP" H 7520 3105 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" V 7600 3150 50  0001 C CNN
F 3 " ~" H 6575 2550 50  0001 C CNN
	1    7850 3100
	-1   0    0    -1  
$EndComp
Text GLabel 4300 2700 0    50   Input ~ 0
RST
Wire Wire Line
	4300 2700 4400 2700
Connection ~ 4400 2700
Wire Wire Line
	7350 3200 7450 3200
Wire Wire Line
	7950 2600 7950 2550
Wire Wire Line
	7950 3500 7950 3550
Wire Wire Line
	9000 2550 9000 2900
Wire Wire Line
	7950 2550 8500 2550
Wire Wire Line
	9000 3200 9000 3550
Wire Wire Line
	7950 3550 8500 3550
Wire Wire Line
	8500 2550 8500 2400
Connection ~ 8500 2550
Wire Wire Line
	8500 2550 9000 2550
Wire Wire Line
	8500 3550 8500 3700
Connection ~ 8500 3550
Wire Wire Line
	8500 3550 9000 3550
Wire Wire Line
	8500 2900 8500 2550
Wire Wire Line
	8500 3200 8500 3550
$Comp
L power:+5V #PWR0111
U 1 1 5F08E323
P 7950 1500
F 0 "#PWR0111" H 7950 1350 50  0001 C CNN
F 1 "+5V" H 7965 1673 50  0000 C CNN
F 2 "" H 7950 1500 50  0001 C CNN
F 3 "" H 7950 1500 50  0001 C CNN
	1    7950 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5F08EA65
P 7950 1900
F 0 "#PWR0112" H 7950 1650 50  0001 C CNN
F 1 "GND" H 7955 1727 50  0000 C CNN
F 2 "" H 7950 1900 50  0001 C CNN
F 3 "" H 7950 1900 50  0001 C CNN
	1    7950 1900
	1    0    0    -1  
$EndComp
Text GLabel 7900 1650 0    50   Input ~ 0
T1
Text GLabel 7900 1750 0    50   Input ~ 0
T2
Wire Wire Line
	7950 1500 7950 1550
Wire Wire Line
	7950 1550 8000 1550
Wire Wire Line
	7900 1650 8000 1650
Wire Wire Line
	7900 1750 8000 1750
Wire Wire Line
	8000 1850 7950 1850
Wire Wire Line
	7950 1850 7950 1900
$Comp
L Device:R R3
U 1 1 5F017A11
P 7500 4700
F 0 "R3" V 7600 4700 50  0000 C CNN
F 1 "68R" V 7700 4700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 7430 4700 50  0001 C CNN
F 3 "~" H 7500 4700 50  0001 C CNN
	1    7500 4700
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5EFD334D
P 7850 4350
F 0 "R4" V 8050 4350 50  0000 C CNN
F 1 "1K5" V 7950 4350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 7780 4350 50  0001 C CNN
F 3 "~" H 7850 4350 50  0001 C CNN
	1    7850 4350
	-1   0    0    1   
$EndComp
$Comp
L Device:R R5
U 1 1 5EFD461A
P 8000 4350
F 0 "R5" V 7793 4350 50  0000 C CNN
F 1 "1M" V 7884 4350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 7930 4350 50  0001 C CNN
F 3 "~" H 8000 4350 50  0001 C CNN
	1    8000 4350
	-1   0    0    1   
$EndComp
Wire Wire Line
	5200 4600 5200 4800
Text GLabel 5900 3800 2    50   Input ~ 0
D+
Text GLabel 5900 3900 2    50   Input ~ 0
D-
$Comp
L power:+5V #PWR0113
U 1 1 5EFFE051
P 8000 4050
F 0 "#PWR0113" H 8000 3900 50  0001 C CNN
F 1 "+5V" H 8015 4223 50  0000 C CNN
F 2 "" H 8000 4050 50  0001 C CNN
F 3 "" H 8000 4050 50  0001 C CNN
	1    8000 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 4200 7850 4100
Wire Wire Line
	7850 4100 8000 4100
Wire Wire Line
	8300 4100 8300 4400
Wire Wire Line
	8300 4400 8350 4400
Wire Wire Line
	8000 4200 8000 4100
Connection ~ 8000 4100
Wire Wire Line
	8000 4100 8300 4100
Wire Wire Line
	8000 4050 8000 4100
Wire Wire Line
	7650 4700 7850 4700
Wire Wire Line
	7650 4600 8000 4600
Wire Wire Line
	8650 5500 8350 5500
Wire Wire Line
	7850 5500 7850 5200
Connection ~ 8650 5500
Wire Wire Line
	8000 5200 8000 5500
Connection ~ 8000 5500
Wire Wire Line
	8000 5500 7850 5500
Wire Wire Line
	8000 4900 8000 4600
Connection ~ 8000 4600
Wire Wire Line
	8000 4600 8350 4600
Wire Wire Line
	8000 4500 8000 4600
Wire Wire Line
	7850 4500 7850 4700
Connection ~ 7850 4700
Wire Wire Line
	7850 4700 8350 4700
Wire Wire Line
	7850 4700 7850 4900
Wire Wire Line
	5800 3800 5900 3800
Wire Wire Line
	5800 3900 5900 3900
Text GLabel 7250 4600 0    50   Input ~ 0
D+
Text GLabel 7250 4700 0    50   Input ~ 0
D-
Wire Wire Line
	7250 4600 7350 4600
Wire Wire Line
	7250 4700 7350 4700
$Comp
L Device:R R6
U 1 1 5F00A5BB
P 6000 4500
F 0 "R6" V 6200 4500 50  0000 C CNN
F 1 "220R" V 6100 4500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 5930 4500 50  0001 C CNN
F 3 "~" H 6000 4500 50  0001 C CNN
	1    6000 4500
	-1   0    0    1   
$EndComp
$Comp
L Device:R R8
U 1 1 5F00AF1C
P 6350 4500
F 0 "R8" V 6550 4500 50  0000 C CNN
F 1 "220R" V 6450 4500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 6280 4500 50  0001 C CNN
F 3 "~" H 6350 4500 50  0001 C CNN
	1    6350 4500
	-1   0    0    1   
$EndComp
$Comp
L Device:R R9
U 1 1 5F012EDE
P 6700 4500
F 0 "R9" V 6900 4500 50  0000 C CNN
F 1 "220R" V 6800 4500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0411_L9.9mm_D3.6mm_P12.70mm_Horizontal" V 6630 4500 50  0001 C CNN
F 3 "~" H 6700 4500 50  0001 C CNN
	1    6700 4500
	-1   0    0    1   
$EndComp
Wire Wire Line
	6000 4200 6000 4350
Wire Wire Line
	5800 4200 6000 4200
Wire Wire Line
	6350 4100 6350 4350
Wire Wire Line
	5800 4100 6350 4100
Wire Wire Line
	6700 4000 6700 4350
Wire Wire Line
	5800 4000 6700 4000
$Comp
L Device:LED D2
U 1 1 5F022CB4
P 6350 4900
F 0 "D2" V 6389 4782 50  0000 R CNN
F 1 "NUM" V 6298 4782 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 6350 4900 50  0001 C CNN
F 3 "~" H 6350 4900 50  0001 C CNN
	1    6350 4900
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D3
U 1 1 5F023774
P 6700 4900
F 0 "D3" V 6739 4782 50  0000 R CNN
F 1 "SCROLL" V 6648 4782 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 6700 4900 50  0001 C CNN
F 3 "~" H 6700 4900 50  0001 C CNN
	1    6700 4900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6000 4650 6000 4750
Wire Wire Line
	6350 4750 6350 4650
Wire Wire Line
	6700 4650 6700 4750
$Comp
L power:GND #PWR0114
U 1 1 5F02C21C
P 6350 5300
F 0 "#PWR0114" H 6350 5050 50  0001 C CNN
F 1 "GND" H 6355 5127 50  0000 C CNN
F 2 "" H 6350 5300 50  0001 C CNN
F 3 "" H 6350 5300 50  0001 C CNN
	1    6350 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 5050 6000 5150
Wire Wire Line
	6000 5150 6350 5150
Wire Wire Line
	6700 5150 6700 5050
Wire Wire Line
	6350 5050 6350 5150
Connection ~ 6350 5150
Wire Wire Line
	6350 5150 6700 5150
Wire Wire Line
	6350 5150 6350 5300
$Comp
L Device:LED D1
U 1 1 5F022258
P 6000 4900
F 0 "D1" V 6039 4782 50  0000 R CNN
F 1 "CAPS" V 5948 4782 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 6000 4900 50  0001 C CNN
F 3 "~" H 6000 4900 50  0001 C CNN
	1    6000 4900
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 5F038379
P 8200 1650
F 0 "J4" H 8280 1642 50  0000 L CNN
F 1 "Test" H 8280 1551 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 8200 1650 50  0001 C CNN
F 3 "~" H 8200 1650 50  0001 C CNN
	1    8200 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 5F06D68B
P 8350 5650
F 0 "#PWR0115" H 8350 5400 50  0001 C CNN
F 1 "GND" H 8355 5477 50  0000 C CNN
F 2 "" H 8350 5650 50  0001 C CNN
F 3 "" H 8350 5650 50  0001 C CNN
	1    8350 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 5650 8350 5500
Connection ~ 8350 5500
Wire Wire Line
	8350 5500 8000 5500
Wire Wire Line
	6000 1600 6000 1500
Wire Wire Line
	6100 1600 6100 1300
$Comp
L power:GND #PWR0106
U 1 1 5EFE9F12
P 6100 1300
F 0 "#PWR0106" H 6100 1050 50  0001 C CNN
F 1 "GND" H 6105 1127 50  0000 C CNN
F 2 "" H 6100 1300 50  0001 C CNN
F 3 "" H 6100 1300 50  0001 C CNN
	1    6100 1300
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5EFE8282
P 6000 1500
F 0 "#PWR0103" H 6000 1350 50  0001 C CNN
F 1 "+5V" H 6015 1673 50  0000 C CNN
F 2 "" H 6000 1500 50  0001 C CNN
F 3 "" H 6000 1500 50  0001 C CNN
	1    6000 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 2200 6100 2100
Wire Wire Line
	6000 2100 6000 2350
$Comp
L power:GND #PWR0105
U 1 1 5EFE9817
P 6100 2200
F 0 "#PWR0105" H 6100 1950 50  0001 C CNN
F 1 "GND" H 6105 2027 50  0000 C CNN
F 2 "" H 6100 2200 50  0001 C CNN
F 3 "" H 6100 2200 50  0001 C CNN
	1    6100 2200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5EFE8AC5
P 6000 2350
F 0 "#PWR0104" H 6000 2200 50  0001 C CNN
F 1 "+5V" H 6015 2523 50  0000 C CNN
F 2 "" H 6000 2350 50  0001 C CNN
F 3 "" H 6000 2350 50  0001 C CNN
	1    6000 2350
	-1   0    0    1   
$EndComp
Text GLabel 7350 3200 0    50   Input ~ 0
RST
Wire Wire Line
	7100 3100 7100 3400
Wire Wire Line
	7450 3100 7100 3100
Wire Wire Line
	6900 3000 6900 3200
Wire Wire Line
	7450 3000 6900 3000
Wire Wire Line
	7000 2900 7000 3300
Wire Wire Line
	7450 2900 7000 2900
Wire Wire Line
	6300 2700 5800 2700
Wire Wire Line
	6300 2100 6300 2700
Wire Wire Line
	6500 2800 5800 2800
Wire Wire Line
	6500 2100 6500 2800
Wire Wire Line
	6600 2900 5800 2900
Wire Wire Line
	6600 2100 6600 2900
Wire Wire Line
	6700 3000 5800 3000
Wire Wire Line
	6700 2100 6700 3000
Wire Wire Line
	6800 3100 5800 3100
Wire Wire Line
	6800 2100 6800 3100
Wire Wire Line
	6900 3200 5800 3200
Connection ~ 6900 3000
Wire Wire Line
	6900 2100 6900 3000
Wire Wire Line
	7000 3300 5800 3300
Connection ~ 7000 2900
Wire Wire Line
	7000 2100 7000 2900
Wire Wire Line
	7100 3400 5800 3400
Connection ~ 7100 3100
Wire Wire Line
	7100 2100 7100 3100
$EndSCHEMATC
