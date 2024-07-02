EESchema Schematic File Version 5
EELAYER 36 0
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
Comment5 ""
Comment6 ""
Comment7 ""
Comment8 ""
Comment9 ""
$EndDescr
Connection ~ 1600 5750
Connection ~ 2650 5750
Connection ~ 2800 3600
Connection ~ 2800 3900
Connection ~ 7550 4100
Connection ~ 7550 4350
Connection ~ 8050 4650
Wire Wire Line
	1600 5750 1850 5750
Wire Wire Line
	2250 3700 2600 3700
Wire Wire Line
	2250 3800 2600 3800
Wire Wire Line
	2600 3600 2800 3600
Wire Wire Line
	2600 3700 2600 3600
Wire Wire Line
	2600 3800 2600 3900
Wire Wire Line
	2600 3900 2800 3900
Wire Wire Line
	2650 5750 2450 5750
Wire Wire Line
	5650 4050 7400 4050
Wire Wire Line
	6600 2200 7550 2200
Wire Wire Line
	6600 2300 7200 2300
Wire Wire Line
	6600 2400 7150 2400
Wire Wire Line
	6600 2500 7100 2500
Wire Wire Line
	6600 2600 7250 2600
Wire Wire Line
	6600 2700 7150 2700
Wire Wire Line
	6600 2800 7050 2800
Wire Wire Line
	6600 2900 6950 2900
Wire Wire Line
	6950 2850 7550 2850
Wire Wire Line
	6950 2900 6950 2850
Wire Wire Line
	7050 2800 7050 2900
Wire Wire Line
	7050 2900 7550 2900
Wire Wire Line
	7100 1900 7550 1900
Wire Wire Line
	7100 2500 7100 1900
Wire Wire Line
	7150 2000 7550 2000
Wire Wire Line
	7150 2400 7150 2000
Wire Wire Line
	7150 2700 7150 3000
Wire Wire Line
	7150 3000 7550 3000
Wire Wire Line
	7200 2100 7550 2100
Wire Wire Line
	7200 2300 7200 2100
Wire Wire Line
	7250 2600 7250 3100
Wire Wire Line
	7250 3100 7550 3100
Wire Wire Line
	7400 4050 7400 4350
Wire Wire Line
	7400 4350 7550 4350
Wire Wire Line
	7550 2850 7550 2800
Wire Wire Line
	7550 4100 7550 4350
Wire Wire Line
	7550 4350 7550 4650
Wire Wire Line
	8050 4650 8050 4100
Text GLabel 8950 2900 0    50   Input ~ 0
IO0
Text GLabel 8950 3500 0    50   Input ~ 0
IO5
$Comp
L power:+5V #PWR?
U 1 1 00000000
P 1600 5750
F 0 "#PWR?" H 1600 5600 50  0001 C CNN
F 1 "+5V" H 1600 5891 50  0000 C CNN
F 2 "" H 1600 5750 50  0001 C CNN
F 3 "" H 1600 5750 50  0001 C CNN
	1    1600 5750
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 00000000
P 2650 5750
F 0 "#PWR?" H 2650 5600 50  0001 C CNN
F 1 "+3.3V" H 2650 5891 50  0000 C CNN
F 2 "" H 2650 5750 50  0001 C CNN
F 3 "" H 2650 5750 50  0001 C CNN
	1    2650 5750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0112
U 1 1 64DA7388
P 2800 3600
F 0 "#PWR0112" H 2800 3450 50  0001 C CNN
F 1 "+5V" H 2815 3773 50  0000 C CNN
F 2 "" H 2800 3600 50  0001 C CNN
F 3 "" H 2800 3600 50  0001 C CNN
	1    2800 3600
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 00000000
P 5050 4250
F 0 "#PWR?" H 5050 4100 50  0001 C CNN
F 1 "+3.3V" H 5050 4391 50  0000 C CNN
F 2 "" H 5050 4250 50  0001 C CNN
F 3 "" H 5050 4250 50  0001 C CNN
	1    5050 4250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 64DA0C72
P 6600 2100
F 0 "#PWR0110" H 6600 1950 50  0001 C CNN
F 1 "+5V" H 6615 2273 50  0000 C CNN
F 2 "" H 6600 2100 50  0001 C CNN
F 3 "" H 6600 2100 50  0001 C CNN
	1    6600 2100
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0109
U 1 1 64DA05DC
P 7550 1800
F 0 "#PWR0109" H 7550 1650 50  0001 C CNN
F 1 "+5V" H 7565 1973 50  0000 C CNN
F 2 "" H 7550 1800 50  0001 C CNN
F 3 "" H 7550 1800 50  0001 C CNN
	1    7550 1800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0108
U 1 1 64DA00F0
P 7550 2700
F 0 "#PWR0108" H 7550 2550 50  0001 C CNN
F 1 "+5V" H 7565 2873 50  0000 C CNN
F 2 "" H 7550 2700 50  0001 C CNN
F 3 "" H 7550 2700 50  0001 C CNN
	1    7550 2700
	1    0    0    -1  
$EndComp
$Comp
L base_controller-rescue:+3.3V-power #PWR?
U 1 1 00000000
P 7550 4100
F 0 "#PWR?" H 7550 3950 50  0001 C CNN
F 1 "+3.3V" H 7565 4273 50  0000 C CNN
F 2 "" H 7550 4100 50  0001 C CNN
F 3 "" H 7550 4100 50  0001 C CNN
	1    7550 4100
	1    0    0    -1  
$EndComp
$Comp
L base_controller-rescue:+3.3V-power #PWR?
U 1 1 00000000
P 8950 2600
F 0 "#PWR?" H 8950 2450 50  0001 C CNN
F 1 "+3.3V" H 8965 2773 50  0000 C CNN
F 2 "" H 8950 2600 50  0001 C CNN
F 3 "" H 8950 2600 50  0001 C CNN
	1    8950 2600
	1    0    0    -1  
$EndComp
$Comp
L base_controller-rescue:+3.3V-power #PWR?
U 1 1 00000000
P 8950 3200
F 0 "#PWR?" H 8950 3050 50  0001 C CNN
F 1 "+3.3V" H 8965 3373 50  0000 C CNN
F 2 "" H 8950 3200 50  0001 C CNN
F 3 "" H 8950 3200 50  0001 C CNN
	1    8950 3200
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 00000000
P 1600 6050
F 0 "#PWR?" H 1600 5800 50  0001 C CNN
F 1 "Earth" H 1600 5900 50  0001 C CNN
F 2 "" H 1600 6050 50  0001 C CNN
F 3 "~" H 1600 6050 50  0001 C CNN
	1    1600 6050
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 00000000
P 2150 6050
F 0 "#PWR?" H 2150 5800 50  0001 C CNN
F 1 "Earth" H 2150 5900 50  0001 C CNN
F 2 "" H 2150 6050 50  0001 C CNN
F 3 "~" H 2150 6050 50  0001 C CNN
	1    2150 6050
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 00000000
P 2650 6050
F 0 "#PWR?" H 2650 5800 50  0001 C CNN
F 1 "Earth" H 2650 5900 50  0001 C CNN
F 2 "" H 2650 6050 50  0001 C CNN
F 3 "~" H 2650 6050 50  0001 C CNN
	1    2650 6050
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0113
U 1 1 64DA7A19
P 2800 3900
F 0 "#PWR0113" H 2800 3650 50  0001 C CNN
F 1 "Earth" H 2800 3750 50  0001 C CNN
F 2 "" H 2800 3900 50  0001 C CNN
F 3 "~" H 2800 3900 50  0001 C CNN
	1    2800 3900
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 00000000
P 5650 6850
F 0 "#PWR?" H 5650 6600 50  0001 C CNN
F 1 "Earth" H 5650 6700 50  0001 C CNN
F 2 "" H 5650 6850 50  0001 C CNN
F 3 "~" H 5650 6850 50  0001 C CNN
	1    5650 6850
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0111
U 1 1 64DA11D9
P 6200 3100
F 0 "#PWR0111" H 6200 2850 50  0001 C CNN
F 1 "Earth" H 6200 2950 50  0001 C CNN
F 2 "" H 6200 3100 50  0001 C CNN
F 3 "~" H 6200 3100 50  0001 C CNN
	1    6200 3100
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 00000000
P 8050 4650
F 0 "#PWR?" H 8050 4400 50  0001 C CNN
F 1 "Earth" H 8050 4500 50  0001 C CNN
F 2 "" H 8050 4650 50  0001 C CNN
F 3 "~" H 8050 4650 50  0001 C CNN
	1    8050 4650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 64DA21C2
P 2050 3700
F 0 "J2" H 2158 3881 50  0000 C CNN
F 1 "5V" H 2158 3790 50  0000 C CNN
F 2 "Connector_JST:JST_XH_B2B-XH-A_1x02_P2.50mm_Vertical" H 2050 3700 50  0001 C CNN
F 3 "~" H 2050 3700 50  0001 C CNN
	1    2050 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 00000000
P 8950 2750
F 0 "R?" H 9020 2796 50  0000 L CNN
F 1 "10 K" H 9020 2705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 8880 2750 50  0001 C CNN
F 3 "~" H 8950 2750 50  0001 C CNN
	1    8950 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 00000000
P 8950 3350
F 0 "R?" H 9020 3396 50  0000 L CNN
F 1 "10 K" H 9020 3305 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 8880 3350 50  0001 C CNN
F 3 "~" H 8950 3350 50  0001 C CNN
	1    8950 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Polarized C?
U 1 1 00000000
P 1600 5900
F 0 "C?" H 1715 5968 50  0000 L CNN
F 1 "10 uF" H 1715 5868 50  0000 L CNN
F 2 "" H 1638 5750 50  0001 C CNN
F 3 "~" H 1600 5900 50  0001 C CNN
	1    1600 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Polarized C?
U 1 1 00000000
P 2650 5900
F 0 "C?" H 2765 5968 50  0000 L CNN
F 1 "22 uF" H 2765 5868 50  0000 L CNN
F 2 "" H 2688 5750 50  0001 C CNN
F 3 "~" H 2650 5900 50  0001 C CNN
	1    2650 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 64DA34E5
P 2800 3750
F 0 "C1" H 2915 3796 50  0000 L CNN
F 1 "10 nF" H 2915 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 2838 3600 50  0001 C CNN
F 3 "~" H 2800 3750 50  0001 C CNN
	1    2800 3750
	1    0    0    -1  
$EndComp
$Comp
L 28byj_controller-rescue:28BYJ-48_Stepper-FlightMotors M1
U 1 1 64D7C7A5
P 7750 1700
F 0 "M1" H 7622 1959 50  0000 R CNN
F 1 "28BYJ-48_Stepper" H 7622 2050 50  0000 R CNN
F 2 "Connector_JST:JST_XH_B5B-XH-A_1x05_P2.50mm_Vertical" H 7750 1700 50  0001 C CNN
F 3 "" H 7750 1700 50  0001 C CNN
	1    7750 1700
	-1   0    0    1   
$EndComp
$Comp
L 28byj_controller-rescue:28BYJ-48_Stepper-FlightMotors M2
U 1 1 64D7FD63
P 7750 2600
F 0 "M2" H 7622 2859 50  0000 R CNN
F 1 "28BYJ-48_Stepper" H 7622 2950 50  0000 R CNN
F 2 "Connector_JST:JST_XH_B5B-XH-A_1x05_P2.50mm_Vertical" H 7750 2600 50  0001 C CNN
F 3 "" H 7750 2600 50  0001 C CNN
	1    7750 2600
	-1   0    0    1   
$EndComp
$Comp
L pspice:C C?
U 1 1 00000000
P 7800 4100
F 0 "C?" V 7485 4100 50  0000 C CNN
F 1 "10 uF" V 7576 4100 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 7800 4100 50  0001 C CNN
F 3 "~" H 7800 4100 50  0001 C CNN
	1    7800 4100
	0    1    1    0   
$EndComp
$Comp
L pspice:C C?
U 1 1 00000000
P 7800 4650
F 0 "C?" V 7485 4650 50  0000 C CNN
F 1 "0.1 uF" V 7576 4650 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 7800 4650 50  0001 C CNN
F 3 "~" H 7800 4650 50  0001 C CNN
	1    7800 4650
	0    1    1    0   
$EndComp
$Comp
L Regulator_Linear:AMS1117-3.3 U?
U 1 1 00000000
P 2150 5750
F 0 "U?" H 2150 5971 50  0000 C CNN
F 1 "AMS1117-3.3" H 2150 5871 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 2150 5950 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 2250 5500 50  0001 C CNN
	1    2150 5750
	1    0    0    -1  
$EndComp
$Comp
L Transistor_Array:ULN2803A U2
U 1 1 64D837D7
P 6200 2400
F 0 "U2" H 6200 2967 50  0000 C CNN
F 1 "ULN2803A" H 6200 2876 50  0000 C CNN
F 2 "Package_DIP:DIP-18_W7.62mm" H 6250 1750 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/uln2803a.pdf" H 6300 2200 50  0001 C CNN
	1    6200 2400
	1    0    0    -1  
$EndComp
$Comp
L RF_Module:ESP32-WROOM-32 U?
U 1 1 00000000
P 5650 5450
F 0 "U?" H 5730 6896 50  0000 L CNN
F 1 "ESP32-WROOM-32" H 5730 6796 50  0000 L CNN
F 2 "RF_Module:ESP32-WROOM-32" H 5650 3950 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf" H 5350 5500 50  0001 C CNN
	1    5650 5450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
