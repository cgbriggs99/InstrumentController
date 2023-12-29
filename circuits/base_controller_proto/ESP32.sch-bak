EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 6
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
L RF_Module:ESP32-WROOM-32 U?
U 1 1 64CF7031
P 4800 3850
AR Path="/64CF7031" Ref="U?"  Part="1" 
AR Path="/64CF57AE/64CF7031" Ref="U1"  Part="1" 
F 0 "U1" H 4800 5431 50  0000 C CNN
F 1 "ESP32-WROOM-32" H 4800 5340 50  0000 C CNN
F 2 "RF_Module:ESP32-WROOM-32" H 4800 2350 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf" H 4500 3900 50  0001 C CNN
	1    4800 3850
	1    0    0    -1  
$EndComp
Text GLabel 5400 4350 2    50   Input ~ 0
DEVCL_2
Text GLabel 5400 4450 2    50   Input ~ 0
DEVCL_3
Text GLabel 5400 4550 2    50   Input ~ 0
DEVCL_4
Text GLabel 5400 4650 2    50   Input ~ 0
DEVCL_0
Text GLabel 5400 4750 2    50   Input ~ 0
DEVCL_1
Text GLabel 5400 4850 2    50   Input ~ 0
DEVID_2
Text GLabel 5400 4950 2    50   Input ~ 0
DEVID_3
Text GLabel 4200 2850 0    50   Input ~ 0
DEVID_0
Text GLabel 4200 2950 0    50   Input ~ 0
DEVID_1
Text GLabel 5400 2750 2    50   Input ~ 0
TXD0
Text GLabel 5400 2950 2    50   Input ~ 0
RXD0
Text GLabel 5400 3250 2    50   Input ~ 0
MTDI
Text GLabel 5400 3350 2    50   Input ~ 0
MTCK
Text GLabel 5400 3450 2    50   Input ~ 0
MTMS
Text GLabel 5400 3550 2    50   Input ~ 0
MTDO
Text GLabel 4200 2650 0    50   Input ~ 0
EN
$Comp
L power:Earth #PWR?
U 1 1 64CF7051
P 4800 5250
AR Path="/64CF7051" Ref="#PWR?"  Part="1" 
AR Path="/64CF57AE/64CF7051" Ref="#PWR0101"  Part="1" 
F 0 "#PWR0101" H 4800 5000 50  0001 C CNN
F 1 "Earth" H 4800 5100 50  0001 C CNN
F 2 "" H 4800 5250 50  0001 C CNN
F 3 "~" H 4800 5250 50  0001 C CNN
	1    4800 5250
	1    0    0    -1  
$EndComp
NoConn ~ 4200 3850
NoConn ~ 4200 3950
NoConn ~ 4200 4050
NoConn ~ 4200 4150
NoConn ~ 4200 4250
NoConn ~ 4200 4350
$Comp
L pspice:C C?
U 1 1 64CF705D
P 7050 2500
AR Path="/64CF705D" Ref="C?"  Part="1" 
AR Path="/64CF57AE/64CF705D" Ref="C1"  Part="1" 
F 0 "C1" V 6735 2500 50  0000 C CNN
F 1 "10 uF" V 6826 2500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 7050 2500 50  0001 C CNN
F 3 "~" H 7050 2500 50  0001 C CNN
	1    7050 2500
	0    1    1    0   
$EndComp
$Comp
L pspice:C C?
U 1 1 64CF7063
P 7050 3050
AR Path="/64CF7063" Ref="C?"  Part="1" 
AR Path="/64CF57AE/64CF7063" Ref="C2"  Part="1" 
F 0 "C2" V 6735 3050 50  0000 C CNN
F 1 "0.1 uF" V 6826 3050 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 7050 3050 50  0001 C CNN
F 3 "~" H 7050 3050 50  0001 C CNN
	1    7050 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 2500 6800 2750
Wire Wire Line
	7300 3050 7300 2500
$Comp
L power:+3.3V #PWR?
U 1 1 64CF706B
P 6800 2500
AR Path="/64CF706B" Ref="#PWR?"  Part="1" 
AR Path="/64CF57AE/64CF706B" Ref="#PWR0102"  Part="1" 
F 0 "#PWR0102" H 6800 2350 50  0001 C CNN
F 1 "+3.3V" H 6815 2673 50  0000 C CNN
F 2 "" H 6800 2500 50  0001 C CNN
F 3 "" H 6800 2500 50  0001 C CNN
	1    6800 2500
	1    0    0    -1  
$EndComp
Connection ~ 6800 2500
$Comp
L power:Earth #PWR?
U 1 1 64CF7072
P 7300 3050
AR Path="/64CF7072" Ref="#PWR?"  Part="1" 
AR Path="/64CF57AE/64CF7072" Ref="#PWR0103"  Part="1" 
F 0 "#PWR0103" H 7300 2800 50  0001 C CNN
F 1 "Earth" H 7300 2900 50  0001 C CNN
F 2 "" H 7300 3050 50  0001 C CNN
F 3 "~" H 7300 3050 50  0001 C CNN
	1    7300 3050
	1    0    0    -1  
$EndComp
Connection ~ 7300 3050
Wire Wire Line
	4800 2450 6650 2450
Wire Wire Line
	6650 2450 6650 2750
Wire Wire Line
	6650 2750 6800 2750
Connection ~ 6800 2750
Wire Wire Line
	6800 2750 6800 3050
Text GLabel 5400 3150 2    50   Input ~ 0
IO5
Text GLabel 5400 2650 2    50   Input ~ 0
IO0
Text GLabel 8200 1300 0    50   Input ~ 0
IO0
$Comp
L Device:R R10
U 1 1 64DB1E06
P 8200 1150
F 0 "R10" H 8270 1196 50  0000 L CNN
F 1 "10 K" H 8270 1105 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 8130 1150 50  0001 C CNN
F 3 "~" H 8200 1150 50  0001 C CNN
	1    8200 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0130
U 1 1 64DB23C5
P 8200 1000
F 0 "#PWR0130" H 8200 850 50  0001 C CNN
F 1 "+3.3V" H 8215 1173 50  0000 C CNN
F 2 "" H 8200 1000 50  0001 C CNN
F 3 "" H 8200 1000 50  0001 C CNN
	1    8200 1000
	1    0    0    -1  
$EndComp
Text GLabel 8200 1900 0    50   Input ~ 0
IO5
$Comp
L Device:R R11
U 1 1 64DB3945
P 8200 1750
F 0 "R11" H 8270 1796 50  0000 L CNN
F 1 "10 K" H 8270 1705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 8130 1750 50  0001 C CNN
F 3 "~" H 8200 1750 50  0001 C CNN
	1    8200 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0131
U 1 1 64DB3E7D
P 8200 1600
F 0 "#PWR0131" H 8200 1450 50  0001 C CNN
F 1 "+3.3V" H 8215 1773 50  0000 C CNN
F 2 "" H 8200 1600 50  0001 C CNN
F 3 "" H 8200 1600 50  0001 C CNN
	1    8200 1600
	1    0    0    -1  
$EndComp
Text GLabel 8200 2300 0    50   Input ~ 0
MTDI
$Comp
L Device:R R12
U 1 1 64DB4BBC
P 8200 2450
F 0 "R12" H 8270 2496 50  0000 L CNN
F 1 "10 K" H 8270 2405 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 8130 2450 50  0001 C CNN
F 3 "~" H 8200 2450 50  0001 C CNN
	1    8200 2450
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0132
U 1 1 64DB519E
P 8200 2600
F 0 "#PWR0132" H 8200 2350 50  0001 C CNN
F 1 "Earth" H 8200 2450 50  0001 C CNN
F 2 "" H 8200 2600 50  0001 C CNN
F 3 "~" H 8200 2600 50  0001 C CNN
	1    8200 2600
	1    0    0    -1  
$EndComp
Text GLabel 8200 2950 0    50   Input ~ 0
MTCK
$Comp
L Device:R R13
U 1 1 64DB78C4
P 8200 3100
F 0 "R13" H 8270 3146 50  0000 L CNN
F 1 "10 K" H 8270 3055 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 8130 3100 50  0001 C CNN
F 3 "~" H 8200 3100 50  0001 C CNN
	1    8200 3100
	1    0    0    -1  
$EndComp
Text GLabel 8200 3500 0    50   Input ~ 0
MTMS
$Comp
L power:Earth #PWR0133
U 1 1 64DB8128
P 8200 3250
F 0 "#PWR0133" H 8200 3000 50  0001 C CNN
F 1 "Earth" H 8200 3100 50  0001 C CNN
F 2 "" H 8200 3250 50  0001 C CNN
F 3 "~" H 8200 3250 50  0001 C CNN
	1    8200 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R14
U 1 1 64DB8954
P 8200 3650
F 0 "R14" H 8270 3696 50  0000 L CNN
F 1 "10 K" H 8270 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 8130 3650 50  0001 C CNN
F 3 "~" H 8200 3650 50  0001 C CNN
	1    8200 3650
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0134
U 1 1 64DB8EA9
P 8200 3800
F 0 "#PWR0134" H 8200 3550 50  0001 C CNN
F 1 "Earth" H 8200 3650 50  0001 C CNN
F 2 "" H 8200 3800 50  0001 C CNN
F 3 "~" H 8200 3800 50  0001 C CNN
	1    8200 3800
	1    0    0    -1  
$EndComp
Text GLabel 8200 4500 0    50   Input ~ 0
MTDO
$Comp
L Device:R R15
U 1 1 64DBB8A4
P 8200 4350
F 0 "R15" H 8270 4396 50  0000 L CNN
F 1 "10 K" H 8270 4305 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 8130 4350 50  0001 C CNN
F 3 "~" H 8200 4350 50  0001 C CNN
	1    8200 4350
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0135
U 1 1 64DBBE5A
P 8200 4200
F 0 "#PWR0135" H 8200 4050 50  0001 C CNN
F 1 "+3.3V" H 8215 4373 50  0000 C CNN
F 2 "" H 8200 4200 50  0001 C CNN
F 3 "" H 8200 4200 50  0001 C CNN
	1    8200 4200
	1    0    0    -1  
$EndComp
Text GLabel 5400 4250 2    50   Input ~ 0
DATA_IO
Text GLabel 5400 4150 2    50   Input ~ 0
SHCP_1
Text GLabel 5400 4050 2    50   Input ~ 0
STCP_1
Text GLabel 5400 3950 2    50   Input ~ 0
OE_1
Text GLabel 5400 3850 2    50   Input ~ 0
MR_1
Text GLabel 5400 3750 2    50   Input ~ 0
SHCP_2
Text GLabel 5400 3650 2    50   Input ~ 0
STCP_2
Text GLabel 5400 3050 2    50   Input ~ 0
PL_2
Text GLabel 5400 2850 2    50   Input ~ 0
MR_2
$EndSCHEMATC
