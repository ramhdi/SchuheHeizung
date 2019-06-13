EESchema Schematic File Version 4
LIBS:SVC_1.0-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "jeu. 02 avril 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 8700 1100 0    60   ~ 0
1(Tx)
Text Label 8700 1200 0    60   ~ 0
0(Rx)
Text Label 8700 1300 0    60   ~ 0
Reset
Text Label 8700 1500 0    60   ~ 0
2
Text Label 8700 1600 0    60   ~ 0
3(**)
Text Label 8700 1700 0    60   ~ 0
4
Text Label 8700 1800 0    60   ~ 0
5(**)
Text Label 8700 1900 0    60   ~ 0
6(**)
Text Label 8700 2000 0    60   ~ 0
7
Text Label 8700 2100 0    60   ~ 0
8
Text Label 8700 2200 0    60   ~ 0
9(**)
Text Label 8700 2300 0    60   ~ 0
10(**/SS)
Text Label 8700 2400 0    60   ~ 0
11(**/MOSI)
Text Label 8700 2500 0    60   ~ 0
12(MISO)
Text Label 10550 2500 0    60   ~ 0
13(SCK)
Text Label 10550 2200 0    60   ~ 0
A0
Text Label 10550 2100 0    60   ~ 0
A1
Text Label 10550 2000 0    60   ~ 0
A2
Text Label 10550 1900 0    60   ~ 0
A3
Text Label 10550 1800 0    60   ~ 0
A4
Text Label 10550 1700 0    60   ~ 0
A5
Text Label 10550 1600 0    60   ~ 0
A6
Text Label 10550 1500 0    60   ~ 0
A7
Text Label 10550 2300 0    60   ~ 0
AREF
Text Label 10550 1300 0    60   ~ 0
Reset
Text Notes 8500 575  0    60   ~ 0
Shield for Arduino Nano
Text Label 10250 950  1    60   ~ 0
Vin
Wire Notes Line
	8475 650  9675 650 
Wire Notes Line
	9675 650  9675 475 
$Comp
L Connector_Generic:Conn_01x15 P1
U 1 1 56D73FAC
P 9550 1800
F 0 "P1" H 9550 2600 50  0000 C CNN
F 1 "Digital" V 9650 1800 50  0000 C CNN
F 2 "Socket_Arduino_Nano:Socket_Strip_Arduino_1x15" H 9550 1800 50  0001 C CNN
F 3 "" H 9550 1800 50  0000 C CNN
	1    9550 1800
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x15 P2
U 1 1 56D740C7
P 9950 1800
F 0 "P2" H 9950 2600 50  0000 C CNN
F 1 "Analog" V 10050 1800 50  0000 C CNN
F 2 "Socket_Arduino_Nano:Socket_Strip_Arduino_1x15" H 9950 1800 50  0001 C CNN
F 3 "" H 9950 1800 50  0000 C CNN
	1    9950 1800
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 56D7422C
P 9250 2600
F 0 "#PWR01" H 9250 2350 50  0001 C CNN
F 1 "GND" H 9250 2450 50  0000 C CNN
F 2 "" H 9250 2600 50  0000 C CNN
F 3 "" H 9250 2600 50  0000 C CNN
	1    9250 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 1400 9250 1400
Wire Wire Line
	9250 1400 9250 2600
Wire Wire Line
	9350 1100 8700 1100
Wire Wire Line
	8700 1200 9350 1200
Wire Wire Line
	9350 1300 8700 1300
Wire Wire Line
	8700 1500 9350 1500
Wire Wire Line
	9350 1600 8700 1600
Wire Wire Line
	8700 1700 9350 1700
Wire Wire Line
	9350 1800 8700 1800
Wire Wire Line
	8700 1900 9350 1900
Wire Wire Line
	9350 2000 8700 2000
Wire Wire Line
	8700 2100 9350 2100
Wire Wire Line
	9350 2200 8700 2200
Wire Wire Line
	8700 2300 9350 2300
Wire Wire Line
	9350 2400 8700 2400
Wire Wire Line
	8700 2500 9350 2500
$Comp
L power:GND #PWR02
U 1 1 56D746ED
P 10250 2600
F 0 "#PWR02" H 10250 2350 50  0001 C CNN
F 1 "GND" H 10250 2450 50  0000 C CNN
F 2 "" H 10250 2600 50  0000 C CNN
F 3 "" H 10250 2600 50  0000 C CNN
	1    10250 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 2600 10250 1200
Wire Wire Line
	10250 1200 10150 1200
Wire Wire Line
	10150 1100 10250 1100
Wire Wire Line
	10250 1100 10250 950 
Wire Wire Line
	10350 950  10350 1400
Wire Wire Line
	10350 1400 10150 1400
Wire Wire Line
	10450 950  10450 2400
Wire Wire Line
	10450 2400 10150 2400
Wire Wire Line
	10550 1300 10150 1300
Wire Wire Line
	10150 1500 10550 1500
Wire Wire Line
	10550 1600 10150 1600
Wire Wire Line
	10550 1900 10150 1900
Wire Wire Line
	10550 2000 10150 2000
Wire Wire Line
	10150 2100 10550 2100
Wire Wire Line
	10550 2200 10150 2200
Wire Wire Line
	10550 2300 10150 2300
Wire Wire Line
	10150 2500 10550 2500
Wire Notes Line
	11200 2850 8450 2850
Wire Notes Line
	8450 2850 8450 500 
Text Notes 9650 1100 0    60   ~ 0
1
$Comp
L Relay_SolidState:S202S01 U1
U 1 1 5C9F0C8E
P 3300 1400
F 0 "U1" H 3300 1725 50  0000 C CNN
F 1 "S202S01" H 3300 1634 50  0000 C CNN
F 2 "Package_SIP:SIP4_Sharp-SSR_P7.62mm_Straight" H 3100 1200 50  0001 L CIN
F 3 "http://www.sharp-world.com/products/device/lineup/data/pdf/datasheet/s102s01_e.pdf" H 3265 1400 50  0001 L CNN
	1    3300 1400
	1    0    0    -1  
$EndComp
$Comp
L Relay_SolidState:S202S01 U2
U 1 1 5C9F0D51
P 3300 1950
F 0 "U2" H 3300 2275 50  0000 C CNN
F 1 "S202S01" H 3300 2184 50  0000 C CNN
F 2 "Package_SIP:SIP4_Sharp-SSR_P7.62mm_Straight" H 3100 1750 50  0001 L CIN
F 3 "http://www.sharp-world.com/products/device/lineup/data/pdf/datasheet/s102s01_e.pdf" H 3265 1950 50  0001 L CNN
	1    3300 1950
	1    0    0    -1  
$EndComp
$Comp
L SVC_1.0-rescue:HLK-PM01-Converter_ACDC PS1
U 1 1 5C9F1E62
P 3300 2800
F 0 "PS1" H 3300 3125 50  0000 C CNN
F 1 "HLK-PM01" H 3300 3034 50  0000 C CNN
F 2 "Converter_ACDC:Converter_ACDC_HiLink_HLK-PMxx" H 3300 2500 50  0001 C CNN
F 3 "http://www.hlktech.net/product_detail.php?ProId=54" H 3700 2450 50  0001 C CNN
	1    3300 2800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5C9F2392
P 1000 1450
F 0 "J1" H 920 1125 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 920 1216 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_Wuerth_691311400102_P7.62mm" H 1000 1450 50  0001 C CNN
F 3 "~" H 1000 1450 50  0001 C CNN
	1    1000 1450
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 5C9F247B
P 1000 1950
F 0 "J2" H 920 1625 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 920 1716 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_Wuerth_691311400102_P7.62mm" H 1000 1950 50  0001 C CNN
F 3 "~" H 1000 1950 50  0001 C CNN
	1    1000 1950
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 5C9F2549
P 1000 2400
F 0 "J3" H 920 2075 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 920 2166 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_Wuerth_691311400102_P7.62mm" H 1000 2400 50  0001 C CNN
F 3 "~" H 1000 2400 50  0001 C CNN
	1    1000 2400
	-1   0    0    1   
$EndComp
Text GLabel 1200 1350 2    50   Input ~ 0
AC+
Text GLabel 1200 1450 2    50   Input ~ 0
AC-
Text GLabel 1200 1850 2    50   Input ~ 0
HEATER_OUT
Text GLabel 1200 2300 2    50   Input ~ 0
BLOWER_OUT
Text GLabel 1200 1950 2    50   Input ~ 0
AC-
Text GLabel 1200 2400 2    50   Input ~ 0
AC-
Text GLabel 3600 1300 2    50   Input ~ 0
AC+
Text GLabel 3600 1500 2    50   Input ~ 0
HEATER_OUT
Text GLabel 3600 1850 2    50   Input ~ 0
AC+
Text GLabel 3600 2050 2    50   Input ~ 0
BLOWER_OUT
Text GLabel 2900 2700 0    50   Input ~ 0
AC+
Text GLabel 2900 2900 0    50   Input ~ 0
AC-
$Comp
L power:+5V #PWR05
U 1 1 5C9F2C48
P 3700 2700
F 0 "#PWR05" H 3700 2550 50  0001 C CNN
F 1 "+5V" V 3700 2850 50  0000 L CNN
F 2 "" H 3700 2700 50  0001 C CNN
F 3 "" H 3700 2700 50  0001 C CNN
	1    3700 2700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5C9F2D7B
P 3700 2900
F 0 "#PWR06" H 3700 2650 50  0001 C CNN
F 1 "GND" V 3705 2772 50  0000 R CNN
F 2 "" H 3700 2900 50  0001 C CNN
F 3 "" H 3700 2900 50  0001 C CNN
	1    3700 2900
	0    -1   -1   0   
$EndComp
Text GLabel 2700 1300 0    50   Input ~ 0
HEATER_CTRL
$Comp
L Device:R R1
U 1 1 5C9F35A1
P 2850 1300
F 0 "R1" V 2643 1300 50  0000 C CNN
F 1 "R" V 2734 1300 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 2780 1300 50  0001 C CNN
F 3 "~" H 2850 1300 50  0001 C CNN
	1    2850 1300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5C9F3773
P 3000 1500
F 0 "#PWR03" H 3000 1250 50  0001 C CNN
F 1 "GND" V 3005 1372 50  0000 R CNN
F 2 "" H 3000 1500 50  0001 C CNN
F 3 "" H 3000 1500 50  0001 C CNN
	1    3000 1500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5C9F37CD
P 3000 2050
F 0 "#PWR04" H 3000 1800 50  0001 C CNN
F 1 "GND" V 3005 1922 50  0000 R CNN
F 2 "" H 3000 2050 50  0001 C CNN
F 3 "" H 3000 2050 50  0001 C CNN
	1    3000 2050
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5C9F3835
P 2850 1850
F 0 "R2" V 2643 1850 50  0000 C CNN
F 1 "R" V 2734 1850 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 2780 1850 50  0001 C CNN
F 3 "~" H 2850 1850 50  0001 C CNN
	1    2850 1850
	0    1    1    0   
$EndComp
Text GLabel 2700 1850 0    50   Input ~ 0
BLOWER_CTRL
Wire Notes Line
	10650 1050 10650 500 
Wire Notes Line
	11200 1050 10650 1050
Text Notes 10800 1000 0    60   ~ 0
Holes
NoConn ~ 11100 850 
NoConn ~ 11000 850 
NoConn ~ 10900 850 
NoConn ~ 10800 850 
$Comp
L Connector_Generic:Conn_01x01 P4
U 1 1 56D73D86
P 10900 650
F 0 "P4" V 11000 650 50  0000 C CNN
F 1 "CONN_01X01" V 11000 650 50  0001 C CNN
F 2 "Socket_Arduino_Nano:1pin_Nano" H 10900 650 50  0001 C CNN
F 3 "" H 10900 650 50  0000 C CNN
	1    10900 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P3
U 1 1 56D73ADD
P 10800 650
F 0 "P3" V 10900 650 50  0000 C CNN
F 1 "CONN_01X01" V 10900 650 50  0001 C CNN
F 2 "Socket_Arduino_Nano:1pin_Nano" H 10800 650 50  0001 C CNN
F 3 "" H 10800 650 50  0000 C CNN
	1    10800 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P6
U 1 1 56D73DD9
P 11100 650
F 0 "P6" V 11200 650 50  0000 C CNN
F 1 "CONN_01X01" V 11200 650 50  0001 C CNN
F 2 "Socket_Arduino_Nano:1pin_Nano" H 11100 650 50  0001 C CNN
F 3 "" H 11100 650 50  0000 C CNN
	1    11100 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P5
U 1 1 56D73DAE
P 11000 650
F 0 "P5" V 11100 650 50  0000 C CNN
F 1 "CONN_01X01" V 11100 650 50  0001 C CNN
F 2 "Socket_Arduino_Nano:1pin_Nano" H 11000 650 50  0001 C CNN
F 3 "" H 11000 650 50  0000 C CNN
	1    11000 650 
	0    -1   -1   0   
$EndComp
Text GLabel 10700 1700 2    50   Input ~ 0
SCL
Text GLabel 10700 1800 2    50   Input ~ 0
SDA
Text GLabel 8700 1700 0    50   Input ~ 0
BLOWER_CTRL
Text GLabel 8700 1800 0    50   Input ~ 0
HEATER_CTRL
$Comp
L power:+3.3V #PWR017
U 1 1 5C9FACD8
P 10450 950
F 0 "#PWR017" H 10450 800 50  0001 C CNN
F 1 "+3.3V" H 10465 1123 50  0000 C CNN
F 2 "" H 10450 950 50  0001 C CNN
F 3 "" H 10450 950 50  0001 C CNN
	1    10450 950 
	1    0    0    -1  
$EndComp
Text GLabel 5200 1600 0    50   Input ~ 0
SDA
Text GLabel 5200 1500 0    50   Input ~ 0
SCL
$Comp
L power:GND #PWR010
U 1 1 5C9F8BB0
P 5200 1300
F 0 "#PWR010" H 5200 1050 50  0001 C CNN
F 1 "GND" V 5205 1172 50  0000 R CNN
F 2 "" H 5200 1300 50  0001 C CNN
F 3 "" H 5200 1300 50  0001 C CNN
	1    5200 1300
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR09
U 1 1 5C9F8B1A
P 5200 1400
F 0 "#PWR09" H 5200 1250 50  0001 C CNN
F 1 "+5V" V 5215 1528 50  0000 L CNN
F 2 "" H 5200 1400 50  0001 C CNN
F 3 "" H 5200 1400 50  0001 C CNN
	1    5200 1400
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 5C9F899E
P 5400 1400
F 0 "J4" H 5480 1392 50  0000 L CNN
F 1 "Conn_01x04" H 5480 1301 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 5400 1400 50  0001 C CNN
F 3 "~" H 5400 1400 50  0001 C CNN
	1    5400 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder_Switch SW1
U 1 1 5CAF2933
P 5400 2300
F 0 "SW1" H 5400 2667 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 5400 2576 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 5250 2460 50  0001 C CNN
F 3 "~" H 5400 2560 50  0001 C CNN
	1    5400 2300
	1    0    0    -1  
$EndComp
Text GLabel 5100 2200 0    50   Input ~ 0
RE_A
Text GLabel 5100 2400 0    50   Input ~ 0
RE_B
$Comp
L power:GND #PWR07
U 1 1 5CAF4260
P 4750 2350
F 0 "#PWR07" H 4750 2100 50  0001 C CNN
F 1 "GND" H 4755 2177 50  0000 C CNN
F 2 "" H 4750 2350 50  0001 C CNN
F 3 "" H 4750 2350 50  0001 C CNN
	1    4750 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 2350 4750 2300
Wire Wire Line
	4750 2300 5100 2300
$Comp
L power:GND #PWR012
U 1 1 5CAF4AEA
P 5700 2400
F 0 "#PWR012" H 5700 2150 50  0001 C CNN
F 1 "GND" H 5705 2227 50  0000 C CNN
F 2 "" H 5700 2400 50  0001 C CNN
F 3 "" H 5700 2400 50  0001 C CNN
	1    5700 2400
	1    0    0    -1  
$EndComp
Text GLabel 5700 2200 2    50   Input ~ 0
RE_SW
Text GLabel 8700 1500 0    50   Input ~ 0
RE_A
Text GLabel 8700 1600 0    50   Input ~ 0
RE_B
Text GLabel 8700 2500 0    50   Input ~ 0
RE_SW
$Comp
L power:+5V #PWR013
U 1 1 5CAF7200
P 10250 950
F 0 "#PWR013" H 10250 800 50  0001 C CNN
F 1 "+5V" H 10265 1123 50  0000 C CNN
F 2 "" H 10250 950 50  0001 C CNN
F 3 "" H 10250 950 50  0001 C CNN
	1    10250 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 1700 10700 1700
Wire Wire Line
	10150 1800 10700 1800
Wire Notes Line
	600  1000 600  2500
Wire Notes Line
	600  2500 1800 2500
Wire Notes Line
	1800 2500 1800 1000
Wire Notes Line
	1800 1000 600  1000
Wire Notes Line
	2100 2200 2100 1000
Wire Notes Line
	2100 1000 4200 1000
Wire Notes Line
	4200 1000 4200 2200
Wire Notes Line
	4200 2200 2100 2200
Wire Notes Line
	2650 3000 2650 2400
Wire Notes Line
	2650 2400 4050 2400
Wire Notes Line
	4050 2400 4050 3000
Wire Notes Line
	4050 3000 2650 3000
Wire Notes Line
	4850 1700 4850 1200
Wire Notes Line
	4850 1200 6050 1200
Wire Notes Line
	6050 1200 6050 1700
Wire Notes Line
	6050 1700 4850 1700
Wire Notes Line
	4650 2650 4650 1850
Wire Notes Line
	4650 1850 6050 1850
Wire Notes Line
	6050 1850 6050 2650
Wire Notes Line
	6050 2650 4650 2650
$Comp
L Connector_Generic:Conn_01x05 J5
U 1 1 5CB026CB
P 5450 3100
F 0 "J5" H 5530 3142 50  0000 L CNN
F 1 "Conn_01x05" H 5530 3051 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x05_P2.54mm_Horizontal" H 5450 3100 50  0001 C CNN
F 3 "~" H 5450 3100 50  0001 C CNN
	1    5450 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5CB02C8B
P 5250 2900
F 0 "#PWR08" H 5250 2650 50  0001 C CNN
F 1 "GND" V 5255 2772 50  0000 R CNN
F 2 "" H 5250 2900 50  0001 C CNN
F 3 "" H 5250 2900 50  0001 C CNN
	1    5250 2900
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR011
U 1 1 5CB02CEE
P 5250 3000
F 0 "#PWR011" H 5250 2850 50  0001 C CNN
F 1 "+5V" V 5265 3128 50  0000 L CNN
F 2 "" H 5250 3000 50  0001 C CNN
F 3 "" H 5250 3000 50  0001 C CNN
	1    5250 3000
	0    -1   -1   0   
$EndComp
Text GLabel 5250 3100 0    50   Input ~ 0
SCK
Text GLabel 5250 3200 0    50   Input ~ 0
CS
Text GLabel 5250 3300 0    50   Input ~ 0
SO
Text GLabel 8700 2200 0    50   Input ~ 0
SCK
Text GLabel 8700 2300 0    50   Input ~ 0
CS
Text GLabel 8700 2400 0    50   Input ~ 0
SO
Wire Notes Line
	4700 2800 6050 2800
Wire Notes Line
	6050 2800 6050 3400
Wire Notes Line
	6050 3400 4700 3400
Wire Notes Line
	4700 3400 4700 2800
$EndSCHEMATC
